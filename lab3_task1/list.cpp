#include "list.h"
#include <QDebug>


List::~List()                           //Деструктор
 {
     while (Head)                       //Пока по адресу на начало списка что-то есть
     {
         Tail = Head->Next;             //Резервная копия адреса следующего звена списка
         delete Head;                   //Очистка памяти от первого звена
         Head = Tail;                   //Смена адреса начала на адрес следующего элемента
     }
 }

void List::Add(Trip* x)
 {
   Node *temp = new Node;               //Выделение памяти под новый элемент структуры
   temp->Next = nullptr;                   //Указываем, что изначально по следующему адресу пусто
   temp->x = x;                         //Записываем значение в структуру

   if (Head != nullptr)                    //Если список не пуст
   {
       temp->Prev = Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
       Tail->Next = temp;               //Указываем адрес следующего за хвостом элемента
       Tail = temp;                     //Меняем адрес хвоста
   }
   else //Если список пустой
   {
       temp->Prev = nullptr;               //Предыдущий элемент указывает в пустоту
       Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
   }
}

QString List::Print()
{
    QString result = "";
    Node *temp=Head;

    while (temp != NULL)               //Пока не встретится пустое значение
    {
       result+= temp->x->toString();
       result += "\n";
       temp = temp->Next;             //Указываем, что нужен адрес предыдущего элемента
    }
    return result;
}

QString List::PrintShort()
{
    QString result = "";
    Node *temp=Head;

    while (temp != NULL)               //Пока не встретится пустое значение
    {
       result+= temp->x->toShortString();
       result += "\n";
       temp = temp->Next;             //Указываем, что нужен адрес предыдущего элемента
    }
    result.chop(1);
    return result;
}


 void List::Show()
 {
//ВЫВОДИМ СПИСОК С КОНЦА
     Node *temp=Tail;                   //Временный указатель на адрес последнего элемента

     while (temp != NULL)               //Пока не встретится пустое значение
     {
         qDebug() << temp->x->toString() << " ";        //Выводить значение на экран
         temp = temp->Prev;             //Указываем, что нужен адрес предыдущего элемента
     }
     qDebug() << "\n";

 //ВЫВОДИМ СПИСОК С НАЧАЛА
     temp = Head;                       //Временно указываем на адрес первого элемента
      while (temp != NULL)              //Пока не встретим пустое значение
     {
         qDebug() << temp->x->toString() << " ";        //Выводим каждое считанное значение на экран
         temp = temp->Next;             //Смена адреса на адрес следующего элемента
     }
     qDebug() << "\n";
 }
