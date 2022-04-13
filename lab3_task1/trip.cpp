#include "trip.h"

Trip::Trip(int N, QString type, QString d, QTime t1, QTime t2)
{
    number = N;
    busType = type;
    destination = d;
    dispatchTime = t1;
    arrivalTime = t2;

}

QString Trip::toString()
{
    QString result = "";
    result ="trip number:" +  QString::number(number) + " bus type:" + busType + " destination:" + destination +
            " departure time:" + dispatchTime.toString("hh.mm") + " arrival time:" + arrivalTime.toString("hh.mm");
    return result;

}

QString Trip::toShortString()
{
    QString result = "";
    result = QString::number(number) + "\n" + busType +"\n" + destination +"\n" +
             dispatchTime.toString("hh.mm") + "\n" + arrivalTime.toString("hh.mm");
    return result;

}

