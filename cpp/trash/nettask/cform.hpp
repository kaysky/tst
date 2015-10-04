#ifndef __CFORM__HPP__
#define __CFORM__HPP__


#include "ui_cli.h"
#include <QDebug>
#include <QApplication>

#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>


#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

namespace kki {

class DlgForm;

class Link
{
	DlgForm &dlg;
	std::vector<std::thread> vth;
	int number;
	int sfd;
	struct sockaddr_in saddr;
	bool loop;

	Link(const Link&);
	Link(const Link&&);

	void init_connection();
	void proceed_loop();

public:
	Link(DlgForm &rdlg);
	~Link() {}

	void link2srv();
	void thJoin();
	void setLoop(bool flag) { loop = flag; }
	bool getLoop() const { return loop; }
	void clear_vth() { vth.clear(); }
};

///
/// \brief
///

class DlgForm
    : public QWidget
    , public Ui::client_form
{
    Q_OBJECT
	Link lnk;
public:
    DlgForm(QWidget* parent = NULL);
    virtual ~DlgForm() {}

Q_SIGNALS:


public Q_SLOTS:
	void btLink_slot();
	


};

}
#endif // __CFORM__HPP__


