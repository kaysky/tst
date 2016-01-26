#include <QCoreApplication>
#include <QDebug>
#include <QPointer>
#include <QList>
#include "a.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    qDebug() << "Test debug log ...";

    QCoreApplication a(argc, argv);

    QList<QPointer<A> > lpa;

//    QPointer<A> pa = new A;
//    delete pa;

    lpa.push_back(new A);
    lpa.push_back(new A);
    lpa.push_back(new A);
    lpa.push_back(new A);

    delete lpa.first();
    qDeleteAll(lpa);


    a.exec();
    qDebug() << "end of the test ...";
    return 0;
}
