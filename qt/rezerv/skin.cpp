#include <skin.h>

Skin::Skin()
    : brGreen(Qt::green)
    , pnGreen(brGreen,2, Qt::SolidLine,Qt::RoundCap)
    , mainRect(5,20,955,955)
    , center(mainRect.center())
    , position(482,497)
    , fillGrey(40,40,40)
    , brBlack(Qt::black)
    , rectWork1(965,20,310,455)
    , rectWork2(965,480,310,495)
    , X(0)
    , Y(0)
//    , brYellow(Qt::yellow)
//    , pnYellow((brYellow,2, Qt::DotLine,Qt::RoundCap))
{
    p1 = 50;
    p2 = 100;
    p3 = 150;
    k = 3;
    calcPoints();
}

Skin::~Skin()
{
}

void Skin::init(QPainter *p)
{
    painter = p;
}

void Skin::draw()
{
    painter->setPen(pnGreen);
    painter->fillRect(mainRect,fillGrey);
    painter->drawRoundedRect(mainRect,10,10);

    painter->save();
    painter->setBrush(brBlack);
    painter->drawEllipse(center,450,450);
    painter->drawEllipse(center,300,300);
    painter->drawEllipse(center,150,150);
    painter->restore();

    painter->drawPoint(center);

    painter->fillRect(rectWork1,fillGrey);
    painter->fillRect(rectWork2,fillGrey);
    painter->drawRoundedRect(rectWork1,10,10);
    painter->drawRoundedRect(rectWork2,10,10);

    painter->translate(center);

    painter->rotate(225.0);

    for (int i = 0; i < 72; ++i)
    {
        if ((i % 6) != 0)
        {
            painter->drawLine(310,310, 315, 315);
        }
        else
        {
            painter->drawLine(105,105, 315, 315);
        }
        painter->rotate(5.0);
    }

    painter->resetTransform();
    for (it = numPoints.begin()
        ;it != numPoints.end()
        ;++it)
    {   //draw static numbers (0-360/15 degrees)
        painter->drawText(it->second,QString(QString::number(it->first)));
    }



//    QBrush br(Qt::yellow);
//    painter->setPen(QPen(br,2, Qt::DotLine,Qt::RoundCap));
    painter->setPen(Qt::yellow);
    double r = sqrt(X*X+Y*Y);
    if (r < (center.x()-30))
    {
        painter->drawEllipse(center,r,r);
        painter->drawLine(center.x(),center.y(),position.x(),position.y());
        painter->drawText(10,890,QString("X = " + QString::number(X)));
        painter->drawText(10,910,QString("Y = " + QString::number(Y)));
        painter->drawText(810,850,QString("distance = " + QString::number(r/k)));
        double ber = norm_2pi(atan2(X,Y))*(180/M_PI);
        painter->drawText(810,870,QString("bearing = " + QString::number(ber)));
    }

    painter->drawText(10,850,QString("dX = " + QString::number(position.x())));
    painter->drawText(10,870,QString("dY = " + QString::number(position.y())));

    painter->drawText(485,360,QString(QString::number(p1)));
    painter->drawText(485,210,QString(QString::number(p2)));
    painter->drawText(485,60,QString(QString::number(p3)));

    painter->drawText(485,645,QString(QString::number(p1)));
    painter->drawText(485,795,QString(QString::number(p2)));
    painter->drawText(485,945,QString(QString::number(p3)));

    painter->drawText(335,510,QString(QString::number(p1)));
    painter->drawText(185,510,QString(QString::number(p2)));
    painter->drawText(35,510,QString(QString::number(p3)));

    painter->drawText(635,510,QString(QString::number(p1)));
    painter->drawText(785,510,QString(QString::number(p2)));
    painter->drawText(910,510,QString(QString::number(p3)));
}

void Skin::resize150()
{
    if(k != 3)
    {
        p1 = 50;
        p2 = 100;
        p3 = 150;
        k = 3;
    }
    else
        return;
}

void Skin::resize45()
{
    if(k != 10)
    {
        p1 = 15;
        p2 = 30;
        p3 = 45;
        k = 10;
    }
    else
        return;
}

void Skin::resize15()
{
    if(k != 30)
    {
        p1 = 5;
        p2 = 10;
        p3 = 15;
        k = 30;
    }
    else
        return;
}

void Skin::setXY()
{
    X = position.x() - center.x();
    Y = position.y() - center.y();
    Y = -Y;
}

inline double Skin::norm_2pi(double angle)
{
    angle = fmod(angle, 2. * M_PI);
    return angle < 0. ? 2. * M_PI + angle : angle;
}

//void Skin::calcPoints()
//{
//    int R = 470;
//    int x,y,r;

//    for(int i = 0; i < 360; i+=15)
//    {
////        if (i%15 == 0)
//        {
//            r = i*(3.14/M_PI);
//            x = R*cos(r) + center.x();
//            y = R*sin(r) + center.y();
////            x = R*cos(r);
////            y = R*sin(r);
//            numPoints[i] = QPoint(x,y);
//            std::cout << i << "=>" << "x/y = " << x << "/" << y << std::endl;
//        }
//    }
////    print(i,' has x =',x," y = ",y);
//}

void Skin::calcPoints()
{
    numPoints[0] = QPoint(484,43);
    numPoints[15] = QPoint(598,58);
    numPoints[30] = QPoint(708,106);
    numPoints[45] = QPoint(802,175);
    numPoints[60] = QPoint(873,270);
    numPoints[75] = QPoint(921,381);
    numPoints[90] = QPoint(935,501);
    numPoints[105] = QPoint(920,619);
    numPoints[120] = QPoint(875,730);
    numPoints[135] = QPoint(800,828);
    numPoints[150] = QPoint(710,902);
    numPoints[165] = QPoint(593,949);
    numPoints[180] = QPoint(475,960);
    numPoints[195] = QPoint(356,949);
    numPoints[210] = QPoint(240,900);
    numPoints[225] = QPoint(142,827);
    numPoints[240] = QPoint(68,732);
    numPoints[255] = QPoint(20,620);
    numPoints[270] = QPoint(7,500);
    numPoints[285] = QPoint(20,385);
    numPoints[300] = QPoint(65,272);
    numPoints[315] = QPoint(142,175);
    numPoints[330] = QPoint(240,100);
    numPoints[345] = QPoint(352,55);
//    numPoints[360] = QPoint(x,y);
}









