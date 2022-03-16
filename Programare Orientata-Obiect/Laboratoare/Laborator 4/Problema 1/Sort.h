#pragma once
#include <initializer_list>
using namespace std;

class Sort
{
    int v[1000];
    int nr;

public:

    Sort(int nr, int min, int max);
    Sort(initializer_list<int> list);
    Sort(int a[], int dim);
    Sort(int count, ...);
    Sort(const char*);

    void InsertSort(bool ascendent = false);
    void QuickSort(int st, int dr, bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

    void Merge(Sort s);
};
