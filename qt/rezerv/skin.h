#ifndef SKIN_H
#define SKIN_H

#include <QPainter>
#include <cmath>
#include <map>
#include <iostream>

class Skin
{

public:
    Skin();
    ~Skin();

    void init(QPainter *);
    void draw();
    void resize150();
    void resize45();
    void resize15();
    QPoint position;
    void setXY();
    inline double norm_2pi(double angle);

private:
    QPainter *painter;
    int p1,p2,p3,k;
    std::map<int,QPoint> numPoints; //coordinates of numbers
    std::map<int,QPoint>::const_iterator it;
    void calcPoints();


private: /*Colors Pen and brush*/
    QBrush brGreen;
    QPen pnGreen;
    QRect mainRect;     // main rectangle
    QPoint center;      // center of main work rect
    QColor fillGrey;    // main filler of rects
    QBrush brBlack;     // filler for cercles
    QRect rectWork1;
    QRect rectWork2;
//    QBrush brYellow;
//    QPen pnYellow;
    int X,Y;            //coordinates of x,y (base on center)

};

#endif // SKIN_H
