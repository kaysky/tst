#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QTimer>
#include <cmath>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void paintEvent(QPaintEvent *event);

public slots:
    void start();
    void stop();

private:
    Ui::Dialog *ui;
    QTimer *tm;
    int x, y, r, dx, dy, v;
    int w, h;
    double alf;

};

#endif // DIALOG_H
