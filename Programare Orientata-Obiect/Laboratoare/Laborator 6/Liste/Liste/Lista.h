#pragma once


class List 
{
public:
    virtual int operator[](unsigned index) = 0;

    virtual void push_front(int x) = 0;
    virtual void push_back(int x) = 0;

    virtual bool empty() = 0;
    virtual int size() = 0;

    // get the first element    
    virtual int front() = 0;

    // get the last element
    virtual int back() = 0;
};