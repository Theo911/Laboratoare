#include <iostream>
#include "NumberList.h"


using namespace std;


int main()
{
    NumberList test;

    test.Init();

    test.Add(12);
    test.Add(4);
    test.Add(42);
    test.Add(5);
    test.Print();

    test.Insert(2, 90);
    test.Print();

    test.Insert(4, 51);
    test.Print();

    test.Remove(3);
    test.Print();

    test.Remove(4);
    test.Print();

    test.Sort();
    test.Print();

    int v[3] = { 2, 5, 8 };
    int n = 3;
    test.InsertVector(2, v, n);
    test.Print();

    test.Sort();
    test.Print();

    return 0;
}
