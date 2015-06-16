#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    tm(new QTimer(this))

{
    ui->setupUi(this);
    QObject::connect(ui->btStart, SIGNAL(clicked()),this,SLOT(start()));
    QObject::connect(ui->btStop, SIGNAL(clicked()),this,SLOT(stop()));
    QObject::connect(tm, SIGNAL(timeout()),this,SLOT(update()));
    x = 30;
    y = 30;
    dx = 15;
    dy = 15;
    r = 20;
    w = 400;
    h = 400;
    alf = 14;
    v = 1;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
////    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QColor(Qt::red));

    alf = alf*3.14/180;
    dx = cos(alf)*v;
    dy = sin(alf)*v;

    x += dx;
    y += dy;
    if (x - r <= 0 || x + r >= w) // шарик стукнулся о вертикальную границу
    {
//      dx = -dx;
      alf += 3.14/2 ;
//      v = -v;
    }
    if (y - r <= 0 || y + r >= h) // шарик стукнулся о горизонтальную границу
    {
//      dy = -dy;
            alf += 3.14/2 ;
//      v = -v;
    }


    painter.drawEllipse(x,y,20,20);
}
void Dialog::start()
{
//    std::cout << "START BUTTN PUSHED" << std::endl;
    tm->start(100);
}

void Dialog::stop()
{
//    std::cout << "STOP BUTTN PUSHED" << std::endl;
    tm->stop();
}
