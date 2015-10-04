#include "cform.hpp"

namespace kki {

Link::Link(DlgForm &rdlg)
	: dlg(rdlg)
	, loop(false)
{
	memset(&saddr,0,sizeof(saddr));
	sfd = socket(AF_INET,SOCK_STREAM,0);
	saddr.sin_family = AF_INET;
	vth.clear();
}


void Link::init_connection()
{
	inet_pton(AF_INET,dlg.ipAddr->text().toStdString().c_str(),&saddr.sin_addr);
	saddr.sin_port = htons(dlg.port->value());
	connect(sfd,(struct sockaddr*) &saddr, sizeof(saddr));
}


void Link::proceed_loop()
{
	while(loop)
	{
		std::this_thread::sleep_for (std::chrono::seconds(1));
		number = rand() % dlg.range->value() + 1;
		dlg.sentNumber->display(number);
		send(sfd,(void*)&number,sizeof(number),0);
		std::cout << "send :" << number << std::endl;
		recv(sfd,(void*)&number,sizeof(number),0);
		dlg.gotNumber->display(number);
		std::cout << "got :" << number << std::endl;
	}
	exit(0);
}


void Link::link2srv()
{
	if(vth.empty())
	{
		qDebug() << "link connection threded!!!";
		loop = true;
		init_connection();
		vth.push_back(std::thread(&Link::proceed_loop,this));
	}
}


void Link::thJoin()
{
	if(!vth.empty())
		vth[0].join();
}


DlgForm::DlgForm(QWidget* parent)
    : QWidget(parent)
	, lnk(*this)
{
    setupUi(this);
}


void DlgForm::btLink_slot()
{
	if(btLink->isChecked())
	{
		ipAddr->setEnabled(false);
		port->setEnabled(false);
		range->setEnabled(false);
		btLink->setText("Exit");
		
		qDebug() << "btLink slot in action";
		lnk.link2srv();
	}
	else
	{
		lnk.setLoop(false);
		std::this_thread::sleep_for (std::chrono::seconds(2));
		lnk.clear_vth();
	}
}


}
