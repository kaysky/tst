#ifndef A_H
#define A_H

#include <QObject>
#include <QDebug>

class A : public QObject
{
    Q_OBJECT
public:
    explicit A(QObject *parent = 0);
    ~A();

signals:

public slots:
};

#endif // A_H
