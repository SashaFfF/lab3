#ifndef LIST_H
#define LIST_H
#include "patient.h"
#include <QList>
#include <QFile>
#include <QPushButton>


class List
{
public:
    List(QString str = "C:/Users/Александра/OneDrive/Документы/lab1_task4");
    QFile file;
    int countOfPatients=9;
    Patient* patients[100]={};
    void LoadData();
    QString PrintData();
    QString numbersOfRooms();
    QString sortingPatients();
    QString patientsByAge(int min, int max);
    QString patientsByRoom(int number);
    QString patientsByGender(QString g);
    QString patientsByDiagnosis(QString d);
    QString patientsByName(QString LN, QString FN);
    bool validationByAge(QString age);
    bool validationByRoom(QString room);
    bool validationByDate(QString str);
    QString str;


};

#endif // LIST_H
