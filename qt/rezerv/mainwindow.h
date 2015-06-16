#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <skin.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);

public slots:
    void resize150();
    void resize15();
    void resize45();


private:
    Ui::MainWindow *ui;
    Skin skin;
    void mouseMoveEvent(QMouseEvent *mv);
};


#endif // MAINWINDOW_H
