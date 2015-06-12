#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//    painter.setWindow(10,10,900,900);
    QPainterPath path;
//    painter.save();
//    QBrush brush(Qt::blue, Qt::CrossPattern);
    QBrush brush(Qt::green);
//    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(brush,2, Qt::SolidLine,Qt::RoundCap));
//    QRect rect = QRect(5,20,905,920);
    QRect rect = QRect(5,20,955,955);
//    path.(rect);
    QPoint center = rect.center();
    painter.fillRect(rect,QColor(40,40,40));
//    painter.drawPath(path);
    painter.drawRoundedRect(rect,10,10);
//    painter.drawEllipse(rect);
    painter.save();
    painter.setBrush(QBrush(QColor(15,15,15)));
    painter.drawEllipse(center,450,450);
    painter.restore();
    painter.save();
    painter.setBrush(QBrush(QColor(6,0,0)));
    painter.drawEllipse(center,300,300);
    painter.restore();
    painter.save();
    painter.setBrush(QBrush(QColor(0,0,0)));
    painter.drawEllipse(center,150,150);
    painter.restore();
    painter.drawPoint(center);
    painter.translate(center);
    for (int i = 0; i < 72; ++i)
    {
        if ((i % 6) != 0)
        {
            painter.drawLine(310,310, 315, 315);
        }
        else
            painter.drawLine(105,105, 315, 315);
        painter.rotate(5.0);
    }

    for (int i = 0; i < 36; ++i)
    {
        static int I = 0;
        static int R = 425;
        double r;
        int x,y;
        r = I*(3.14/180);
        x = R*cos(r);
        y = R*sin(r);
        painter.drawText(x,y,QString(QString::number(i*10)));
        if(I==360) I = 0;
        else I+=10;
    }


    painter.resetTransform();

    QRect rectWork1 = QRect(965,20,310,455);
    QRect rectWork2 = QRect(965,480,310,495);
    painter.fillRect(rectWork1,QColor(40,40,40));
    painter.fillRect(rectWork2,QColor(40,40,40));
    painter.drawRoundedRect(rectWork1,10,10);
    painter.drawRoundedRect(rectWork2,10,10);

    QBrush br(Qt::yellow);
    painter.setPen(QPen(br,2, Qt::DotLine,Qt::RoundCap));
//    painter.drawEllipse(center,cos(position.x()),sin(position.y()));
//    painter.drawEllipse(center,position.x()-position.y(),position.y()-position.x());
    int a = position.x()-center.x();
    int b = position.y()-center.y();
    double r = sqrt(a*a+b*b);
    painter.drawEllipse(center,r,r);
    painter.drawLine(center.x(),center.y(),position.x(),position.y());
    painter.drawText(10,850,QString("X = " + QString::number(position.x())));
    painter.drawText(10,870,QString("Y = " + QString::number(position.y())));

    painter.drawText(810,850,QString("distance = " + QString::number(r)));
    //@ to do bearing
    painter.drawText(810,870,QString("bearing = " + QString::number((b/r)*(180/3.14))));


}

void MainWindow::mouseMoveEvent(QMouseEvent *mv)
{
    position = mv->pos();
    std::cout<< "mouse event in action: ";
    std::cout << position.x() << "/" << position.y() << std::endl;
    update();
}

