#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QTimer>

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
    void draw(QPainter &);
    QTimer *tm;
};

#endif // DIALOG_H
