#pragma once
#include "Lista.h"

class VectorList : public List
{
    int v[100];
    int n;
public:

    VectorList();
    virtual int operator[](unsigned index);

    virtual void push_front(int x);
    virtual void push_back(int x);

    virtual bool empty();
    virtual int size();

    // get the first element    
    virtual int front();

    // get the last element
    virtual int back();
};