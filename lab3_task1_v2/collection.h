#ifndef COLLECTION_H
#define COLLECTION_H
#include <QFile>
#include "trip.h"


class Collection
{
public:
    Collection(QString str="C:/Users/Александра/OneDrive/Документы/lab3_task1_v2");
    QFile file;
    int countOfTrips=10;
    Trip* trips[100]={};
    void LoadData();
    QString PrintData();
    QString tripsByTime(QString time, QString place);
    QString tripsByDate(QString date);
    bool validationByDate(QString str);
    bool validationBySeats(QString number);


};

#endif // COLLECTION_H
