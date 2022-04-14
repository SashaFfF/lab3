#ifndef LIST_H
#define LIST_H
#include "trip.h"

class List
{
    int N=0;
    Trip* arr[100]={};

public:
    void Show();
    void Add(Trip* x);
    QString Print();
    QString PrintShort();
};


#endif // LIST_H
