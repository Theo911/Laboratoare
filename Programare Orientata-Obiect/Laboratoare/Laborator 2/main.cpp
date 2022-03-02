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

    test.Sort();

    test.Print();

    return 0;
}
