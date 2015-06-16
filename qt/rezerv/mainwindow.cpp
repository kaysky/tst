#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    skin()
{
    ui->setupUi(this);

    QObject::connect(ui->pb150, SIGNAL(clicked()),this,SLOT(resize150()));
    QObject::connect(ui->pb15, SIGNAL(clicked()),this,SLOT(resize15()));
    QObject::connect(ui->pb45, SIGNAL(clicked()),this,SLOT(resize45()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    skin.init(&painter);
    skin.draw();
}

void MainWindow::mouseMoveEvent(QMouseEvent *mv)
{
    skin.position = mv->pos();
    skin.setXY();
    std::cout<< "mouse event in action: ";
    std::cout << skin.position.x() << "/" << skin.position.y() << std::endl;
    update();
}


void MainWindow::resize150()
{
    skin.resize150();
    update();
}

void MainWindow::resize15()
{
    skin.resize15();
    update();
}

void MainWindow::resize45()
{
    skin.resize45();
    update();
}
