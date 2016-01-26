#include "a.h"

A::A(QObject *parent) : QObject(parent)
{
    qDebug() << "constructor ...";
}

A::~A()
{
    qDebug() << "deconstructor ...";
}
