#include "dialog.h"
#include "ui_dialog.h"
#include <cmath>
#include <unistd.h>
#include <iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    tm(new QTimer(this))
{
    ui->setupUi(this);
//    ui->
    QObject::connect(ui->btStart, SIGNAL(clicked()),this,SLOT(start()));
    QObject::connect(ui->btStop, SIGNAL(clicked()),this,SLOT(stop()));
    QObject::connect(tm, SIGNAL(timeout()),this,SLOT(update()));
}


void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.save();
//    QBrush brush(Qt::blue, Qt::CrossPattern);
    QBrush brush(Qt::blue);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(brush,5, Qt::SolidLine,Qt::RoundCap));

    draw(painter);
}

void Dialog::draw(QPainter &painter)
{
    QColor flash = QColor(10,150,250);
    QColor scl = QColor(0,0,255);
    int xl,yl;
    const int k = 0;
    int x = 10 + k;
    int y = 10 + k;
    int d = 360 - k*2;
    const double start_angle = 90;
    QRectF circle_rect = QRectF(x, y, d, d);
    QPointF center = circle_rect.center();
//    int R = 150;
    int R = d/2;
    double r;
    static int I = 0;
    r = I*(3.14/180);
    xl = R*cos(r)+center.x();
    yl= R*sin(r)+center.y();
    painter.drawLine(QPoint(180,180),QPoint(xl,yl));
    if(I==360) I = 0;
    else ++I;
    double ber = 0;
    painter.drawText(10,40,QString(QString::number(atan2(x,y)*(180/3.14))));//atan2

    painter.restore();
    painter.setPen(scl);
    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.translate(180,180);
//    for (int j = 0; j < 72; ++j)
//    {
////        if ((j % 5) != 0)
//        painter.drawLine(110, 110, 115, 115);
//        painter.rotate(5.0);
//    }



    QPainterPath circle;
//    circle.addEllipse(x,y,d,d);
//    QPointF center = circle_rect.center();
//    circle.addEllipse(center,d/2.1,d/2.1);

    QPainterPath path;
    path.addEllipse(x,y,d,d);

    const double LONG_LINES = 30;
    QRectF long_stick_rect = QRectF(
        x + LONG_LINES / 2
      , y + LONG_LINES / 2
      , d - LONG_LINES
      , d - LONG_LINES
      );

    QPainterPath long_sticks;
//    int i = 1;
    for (int i = 0; i < 360; i += 10)
    {
        long_sticks.arcMoveTo(long_stick_rect, start_angle - i);
        long_sticks.arcTo(circle_rect, start_angle  - i, 0);
//        long_sticks.arcMoveTo(10,10, 10,start_angle - i, 10);
//        long_sticks.arcTo(40, 40, 20, 20, start_angle - i, 20);
    }


    painter.drawPath(long_sticks);
//    painter.drawPath(path);

}

void Dialog::start()
{
    std::cout << "START BUTTN PUSHED" << std::endl;
    tm->start(5);
}

void Dialog::stop()
{
    std::cout << "STOP BUTTN PUSHED" << std::endl;
    tm->stop();
}

Dialog::~Dialog()
{
    delete ui;
    delete tm;
}
