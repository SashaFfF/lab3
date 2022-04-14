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


QString Trip::toShortString()
{
    QString result = "";
     result =dateOfDeparture.toString("dd.MM.yyyy") + "/n" + destination +
             "/n" + departureTime.toString("hh.mm") + "/n" + QString::number(numberOfSeats);
     return result;


}
