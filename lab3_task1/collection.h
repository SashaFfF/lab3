#ifndef COLLECTION_H
#define COLLECTION_H
#include <QFile>
#include <QMessageBox>
#include "trip.h"
#include "list.h"


class Collection
{
public:
    Collection(QString str="C:/Users/Александра/OneDrive/Документы/lab3_task1");
    QFile file;
    int countOfTrips=8;
    Trip* trips[100]={};
    void LoadData();
    QString PrintData();
    QString tripsByTime(QString time, QString place);
    QString tripsByPlace(QString place);
    QString busesOnRoute();
    QString busesInPark();
    void Delete(int number);
    bool validationByNumber(QString number);
};

#endif // COLLECTION_H
