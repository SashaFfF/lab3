#include "patient.h"

Patient::Patient(QString LN, QString FN, QString G, int i, QString d,int number, QDate rd, QDate dd)
{
    Last_Name = LN;
    First_Name=FN;
    gender = G;
    age = i;
    diagnosis = d;
    numberOfRoom = number;
    receiptDate = rd;
    dateOfDischarge = dd;
}

QString Patient::toString(){
    QString result="";
    result=Last_Name+" "+First_Name + " gender: " + gender + " age: " + QString::number(age)
            + " diagnosis: " + diagnosis + " number of room: " + QString::number(numberOfRoom) +
            " receipt date: " + receiptDate.toString("dd.MM.yyyy") + " date of discharge: " + dateOfDischarge.toString("dd.MM.yyyy");
    return result;
}
