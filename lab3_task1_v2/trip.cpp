#include "trip.h"

Trip::Trip(QDate date, QString place, QTime t, int number)
{
    dateOfDeparture = date;
    destination = place;
    departureTime = t;
    numberOfSeats = number;
}


QString Trip::toString()
{
    QString result = "";
    result ="departure date:" +  dateOfDeparture.toString("dd.MM.yyyy") + " destination:" + destination +
            " departure time:" + departureTime.toString("hh.mm") + " number of free seats:" + QString::number(numberOfSeats);
    return result;

}
