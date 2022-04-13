#pragma once
#ifndef DATE_H
#define DATE_H


#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDateTime>
#include <QDate>
#include <QMessageBox>
#include <QTextStream>


class Date {
public:
    Date(QString date = "", QString birthday = "");
    virtual ~Date() {    }

    void setData(QString date, QString birthday);
    QString NextDay();
    QString PreviousDay();
    bool isLeap();
    int WeekNumber();
    short DaysTillYourBirthday();
    unsigned long long Duration(Date rhs);


private:
    QString date, birthday;
    QString DaysInMonth(short MonthNumber);
    bool isLeap(short year);

};

#endif // DATE_H


