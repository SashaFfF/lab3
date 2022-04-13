#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QDate>


class Patient
{
public:
    Patient(QString LN, QString FN, QString G, int i, QString d,int number, QDate rd, QDate dd);
    QString Last_Name;
    QString First_Name;
    QString gender;
    int age;
    QString diagnosis;
    int numberOfRoom;
    QDate receiptDate;
    QDate dateOfDischarge;
    QString toString();

};

#endif // PATIENT_H
