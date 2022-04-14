#ifndef TRIP_H
#define TRIP_H
#include <QDate>
#include <QTime>


class Trip
{
public:
    Trip(QDate date, QString place, QTime t, int number);
    QDate dateOfDeparture;
    QString destination;
    QTime departureTime;
    int numberOfSeats;
    QString toString();
    QString toShortString();
};

#endif // TRIP_H
