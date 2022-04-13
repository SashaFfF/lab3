#ifndef TRIP_H
#define TRIP_H
#include <QString>
#include <QTime>


class Trip
{
public:
    Trip(int N, QString type, QString d, QTime t1, QTime t2);
    int number;
    QString busType;
    QString destination;
    QTime dispatchTime;
    QTime arrivalTime;
    QString toString();
    QString toShortString();

};

#endif // TRIP_H
