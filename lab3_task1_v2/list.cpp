#include "list.h"
#include <QDebug>


void List::Add(Trip* x)
{
    arr[N] = x;
    N++;

}

QString List::Print()
{
    QString result = "";

    for(int i=0; i<N; i++){
        result+= arr[i]->toString();
        result += "\n";
    }
    return result;
}

QString List::PrintShort()
{
    QString result = "";

    for(int i=0; i<N; i++){
        result+= arr[i]->toShortString();
        result += "\n";
    }
    result.chop(1);
    return result;
}


 void List::Show()
 {
//ВЫВОДИМ СПИСОК С КОНЦА
     for(int i=N-1;i>=0;i--){
         qDebug() << arr[i]->toString() << " ";
     }
     qDebug() << "\n";

 //ВЫВОДИМ СПИСОК С НАЧАЛА

     for(int i=0; i<N; i++){
        qDebug() << arr[i]->toString() << " ";
     }
     qDebug() << "\n";
 }

