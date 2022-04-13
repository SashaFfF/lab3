#include "list.h"
#include <QFile>
#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include <QFileDialog>

List::List(QString str)
{
     file.setFileName(str);
}

//bool List::validationByAge(QString age)
//{
//    foreach(QChar s,age)
//    {
//        if(s.isDigit() == false)
//        {
//            return false;
//        }

//    }
//    int test = age.toInt();
//    if(test < 0 || test >150)
//    {
//        return false;
//    }
//    return true;

//}

bool List::validationByRoom(QString room)
{
    foreach(QChar s,room)
    {
        if(!s.isDigit())
        {
            qDebug() << "test1";
            return false;
        }

    }
    int test = room.toInt();
    if(test < 0 || test >999)
    {
        return false;
        qDebug() << "test3";
    }
    return true;
}

//bool List::validationByDate(QString str)
//{

//        if(str.size() > 10)
//        {
//            return false;
//        }
//        else
//        {

//            foreach(QChar s, str)
//            {

//                if (s.isDigit() == false && s != '.') {
//                    return false;
//                }
//            }

//            int day = str.left(2).toInt();

//            if(day > 31 || day <= 0)
//            {
//                return false;
//            }

//            int month = str.mid(3,2).toInt();

//            if(month > 12 || month <= 0 )
//            {
//                return false;
//            }

//            int year = str.right(4).toInt();

//            if(year <= 0)
//            {
//                return false;
//            }

//            int monthLeap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
//            int monthNoLeap[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

//            if((year % 4 == 0 && !(year % 100 == 0)) || (year % 400 == 0))
//            {
//                if(month == 2)
//                {
//                    if(monthLeap[1] <  day){
//                        return false;
//                    }
//                }
//            }else{
//                if(month == 2)
//                {
//                    if(monthNoLeap[1] < day){
//                        return false;
//                    }
//                }

//           }
//        }
//        return true;

//}



void List::LoadData(){
    //QFile file("C://Users//Александра//OneDrive//Документы//lab1_task4//file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QTextStream in(&file);
    int N=8*countOfPatients;
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
    for(int i=0; i<N; i+=8){

        if(validationByRoom(arr[i+5])) {
            expectation++;
        }

        patients[j] = new Patient(arr[i], arr[i+1],arr[i+2],
                arr[i+3].toInt(), arr[i+4], arr[i+5].toInt(),
                QDate::fromString(arr[i+6],"dd.MM.yyyy"), QDate::fromString(arr[i+7],"dd.MM.yyyy"));


        j++;

    }

    if(expectation != countOfPatients){
        QMessageBox ms;
        ms.setText("The file contains invalid data");
        ms.exec();
        exit(1);

    }

}

QString List::PrintData(){
    QString result="";
    for (int i=0; i<countOfPatients; i++){
        result+=patients[i]->toString();
        result+="\n";

    }

    return result;
}

QString List::numbersOfRooms()
{
    QList<int> rooms;
    for(int i=0; i<countOfPatients; i++){
        int number=patients[i]->numberOfRoom;
        if (!rooms.contains(number)){
            rooms.append(number);
        }
    }

    QList<QList<QString>> diagnosisPerRooms;
    for(int i=0; i<rooms.length(); i++){
        diagnosisPerRooms.insert(i, {});
        for(int j=0; j<countOfPatients; j++){
            if (patients[j]->numberOfRoom == rooms[i]){
            QString d = patients[j]->diagnosis;
                if (!diagnosisPerRooms[i].contains(d)){
                    diagnosisPerRooms[i].append(d);
                }
            }
        }
    }
    QList<int> resultRooms;
    for(int i=0; i<diagnosisPerRooms.length(); i++){
        if(diagnosisPerRooms[i].length()>=3){
            resultRooms.append(rooms[i]);
        }
    }

    QString resultString="";
    for(int i=0; i<resultRooms.length(); i++){
        resultString+=QString::number(resultRooms[i]) + " ";
    }
    return resultString;

}

QString List::sortingPatients(){
    QList<Patient*> pat;
    for(int i=0; i<countOfPatients; i++){
        if(QDate::currentDate()<patients[i]->dateOfDischarge){
            pat.append(patients[i]);
        }
    }
    for (int n=0; n<pat.length(); n++){
        for(int i=n+1; i<pat.length(); i++){
            if(pat[n]->receiptDate < pat[i]->receiptDate){
                pat.move(i,n);
                n=0;
            }
        }
    }
    QString result="";
    for(int i=0; i<pat.length(); i++){
        result+=pat[i]->toString();
        result += "\n";
    }
    return result;
}

QString List::patientsByAge(int min, int max)
{
    QList<Patient*> pat;
    for(int i=0; i<countOfPatients; i++){
        if(patients[i]->age > min && patients[i]->age < max){
            pat.append(patients[i]);
        }
    }
    QString result="";
    for(int i=0; i<pat.length(); i++){
        result+=pat[i]->toString();
        result += "\n";
    }
    return result;

}

QString List::patientsByRoom(int number)
{
    QList<Patient*> pat;
    for(int i=0; i<countOfPatients; i++){
        if(patients[i]->numberOfRoom==number){
            pat.append(patients[i]);
        }
    }
    QString result="";
    for(int i=0; i<pat.length(); i++){
        result+=pat[i]->toString();
        result += "\n";
    }
    return result;


}

QString List::patientsByGender(QString g)
{
    QList<Patient*> pat;
    for(int i=0; i<countOfPatients; i++){
        if(patients[i]->gender==g){
            pat.append(patients[i]);
        }
    }
    QString result="";
    for(int i=0; i<pat.length(); i++){
        result+=pat[i]->toString();
        result += "\n";
    }
    return result;
}

QString List::patientsByDiagnosis(QString d)
{
    QList<Patient*> pat;
    for(int i=0; i<countOfPatients; i++){
        if(patients[i]->diagnosis==d){
            pat.append(patients[i]);
        }
    }
    QString result="";
    for(int i=0; i<pat.length(); i++){
        result+=pat[i]->toString();
        result += "\n";
    }
    return result;
}

QString List::patientsByName(QString LN, QString FN)
{
    QList<Patient*> pat;
    for(int  i=0; i<countOfPatients; i++){
        if(patients[i]->First_Name==FN && patients[i]->Last_Name==LN){
            pat.append(patients[i]);
        }
    }
    QString result="";
    for(int i=0; i<pat.length(); i++){
        result+=pat[i]->toString();
        result += "\n";
    }
    return result;
}

