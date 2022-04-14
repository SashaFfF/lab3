#include "collection.h"
#include <QMessageBox>

Collection::Collection(QString str)
{
    file.setFileName(str);
}

bool Collection::validationByDate(QString str)
{
           if(str.size() > 10)
            {
                return false;
            }
            else
            {

                foreach(QChar s, str)
                {

                    if (s.isDigit() == false && s != '.') {
                        return false;
                    }
                }

                int day = str.left(2).toInt();

                if(day > 31 || day <= 0)
                {
                    return false;
                }

                int month = str.mid(3,2).toInt();

                if(month > 12 || month <= 0 )
                {
                    return false;
                }

                int year = str.right(4).toInt();

                if(year <= 0)
                {
                    return false;
                }

                int monthLeap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
                int monthNoLeap[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

                if((year % 4 == 0 && !(year % 100 == 0)) || (year % 400 == 0))
                {
                    if(month == 2)
                    {
                        if(monthLeap[1] <  day){
                            return false;
                        }
                    }
                }else{
                    if(month == 2)
                    {
                        if(monthNoLeap[1] < day){
                            return false;
                        }
                    }

               }
            }
           return true;
}

bool Collection::validationBySeats(QString number)
{    foreach(QChar s,number)
    {
        if(!s.isDigit())
        {
            qDebug() << "test1";
            return false;
        }

    }
    int test = number.toInt();
    if(test < 0 || test >999)
    {
        return false;
        qDebug() << "test3";
    }
    return true;

}

void Collection::LoadData(){
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    QTextStream in(&file);
    int N=4*countOfTrips;
    qDebug()<<N;
    QString *arr=new QString[N];
    int i=0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        arr[i]=line;
        i++;
      }
    file.close();
    int j=0;
    int expectation = 0;
    for(int i=0; i<N; i+=4){
        if(validationBySeats(arr[i+3])) {
            expectation++;
        }

        trips[j] = new Trip(QDate::fromString(arr[i],"dd.MM.yyyy"), arr[i+1],
                QTime::fromString(arr[i+2],"hh.mm"),arr[i+3].toInt());
        j++;
    }
    if(expectation != countOfTrips){
        QMessageBox ms;
        ms.setText("The file contains invalid data");
        ms.exec();
        exit(1);

    }

}

QString Collection::PrintData(){
    QString result="";
    for (int i=0; i<countOfTrips; i++){
        result+=trips[i]->toString();
        result+="\n";
    }
    return result;
}

QString Collection::tripsByTime(QString time, QString place)
{
    List* tr = new List();
    for(int i=0; i<countOfTrips; i++){
        if(trips[i]->departureTime.toString()<=time && trips[i]->destination==place){
            tr->Add(trips[i]);
            if(trips[i]->numberOfSeats==0){
                QMessageBox ms;
                ms.setText("There are trips without empty seats in the list!");
                ms.exec();
            }
        }
    }
    tr->Show();
    QString result=tr->Print();
    return result;
}

QString Collection::tripsByDate(QString date)
{
    List* tr = new List();
    for(int i=0; i<countOfTrips; i++){
        if(trips[i]->dateOfDeparture.toString("dd.MM.yyyy")==date){
            tr->Add(trips[i]);
        }
    }
    tr->Show();
    QString result=tr->Print();
    return result;
}


