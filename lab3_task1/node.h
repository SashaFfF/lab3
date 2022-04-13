#ifndef NODE_H
#define NODE_H
#include "trip.h"

struct Node                             //Структура, являющаяся звеном списка
 {
     Trip* x;                             //Значение x будет передаваться в список
     Node *Next, *Prev;                 //Указатели на адреса следующего и предыдущего элементов списка
 };

#endif // NODE_H
