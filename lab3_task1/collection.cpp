#include "collection.h"

Collection::Collection(QString str)
{
    file.setFileName(str);
}

void Collection::LoadData(){
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    QTextStream in(&file);
    int N=5*countOfTrips;
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
    for(int i=0; i<N; i+=5){
        if(validationByNumber(arr[i])){
            expectation++;
        }

        trips[j] = new Trip(arr[i].toInt(), arr[i+1],arr[i+2],
                QTime::fromString(arr[i+3],"hh.mm"), QTime::fromString(arr[i+4],"hh.mm"));
        j++;
    }
    if(expectation != countOfTrips){
        QMessageBox ms;
        ms.setText("The file contains invalid data");
        ms.exec();
        exit(1);

    }

}

void Collection::ReloadData()
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    QTextStream in(&file);
    //int N=5*countOfTrips;

    int N=0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        N++;
      }

    file.close();
    countOfTrips = N/5;
    QString *arr=new QString[N];
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    int i=0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        arr[i]=line;
        i++;
      }
    file.close();
    int j=0;
    for(int i=0; i<N; i+=5){
        trips[j] = new Trip(arr[i].toInt(), arr[i+1],arr[i+2],
                QTime::fromString(arr[i+3],"hh.mm"), QTime::fromString(arr[i+4],"hh.mm"));
        j++;
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
        if(trips[i]->arrivalTime.toString()<=time && trips[i]->destination==place){
            tr->Add(trips[i]);
        }

    }
    tr->Show();
    QString result=tr->Print();
    return result;

}

QString Collection::tripsByPlace(QString place)
{
    List* tr = new List();
    for(int i=0; i<countOfTrips; i++){
        if(trips[i]->destination==place){
            tr->Add(trips[i]);
        }
    }
    tr->Show();
    QString result=tr->Print();
    return result;
}

QString Collection::busesOnRoute()
{
    List* tr = new List();
    for(int i=0; i<countOfTrips; i++){
        if(trips[i]->dispatchTime < QTime::currentTime() && trips[i]->arrivalTime > QTime::currentTime() ){
            tr->Add(trips[i]);
        }
    }
    tr->Show();
    QString result=tr->Print();
    return result;
}

QString Collection::busesInPark()
{
    List* tr = new List();
    for(int i=0; i<countOfTrips; i++){
        if(trips[i]->dispatchTime >= QTime::currentTime() || trips[i]->arrivalTime <= QTime::currentTime() ){
            tr->Add(trips[i]);
        }
    }
    tr->Show();
    QString result=tr->Print();
    return result;

}

void Collection::Delete(int number)
{
    List* tr = new List();
    for(int i=0; i<countOfTrips; i++){
        if(trips[i]->number != number){
            tr->Add(trips[i]);
        }
    }
    tr->Show();
    QString result=tr->PrintShort();
    qDebug() << result;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            return;
    }
    else{
        QTextStream writeStream(&file);
        writeStream << result;
        file.close();
    }
    ReloadData();

}

void Collection::ChangeByNumber(int number, QString str)
{
    List* tr = new List();
    for(int i=0; i<countOfTrips; i++){
        if(trips[i]->number == number){
            trips[i]->number=str.toInt();
            tr->Add(trips[i]);
        }
        else{
            tr->Add(trips[i]);
        }
    }
    tr->Show();
    QString result=tr->PrintShort();
    qDebug() << result;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            return;
    }
    else{
        QTextStream writeStream(&file);
        writeStream << result;
        file.close();
    }
    ReloadData();

}

void Collection::ChangeByType(int number, QString type)
{
    List* tr = new List();
    for(int i=0; i<countOfTrips; i++){
        if(trips[i]->number == number){
            trips[i]->busType=type;
            tr->Add(trips[i]);
        }
        else{
            tr->Add(trips[i]);
        }
    }
    tr->Show();
    QString result=tr->PrintShort();
    qDebug() << result;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            return;
    }
    else{
        QTextStream writeStream(&file);
        writeStream << result;
        file.close();
    }
    ReloadData();

}

void Collection::ChangeByPlace(int number, QString place)
{
    List* tr = new List();
    for(int i=0; i<countOfTrips; i++){
        if(trips[i]->number == number){
            trips[i]->destination=place;
            tr->Add(trips[i]);
        }
        else{
            tr->Add(trips[i]);
        }
    }
    tr->Show();
    QString result=tr->PrintShort();
    qDebug() << result;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            return;
    }
    else{
        QTextStream writeStream(&file);
        writeStream << result;
        file.close();
    }
    ReloadData();

}

bool Collection::validationByNumber(QString number)
{
    foreach(QChar s,number)
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
