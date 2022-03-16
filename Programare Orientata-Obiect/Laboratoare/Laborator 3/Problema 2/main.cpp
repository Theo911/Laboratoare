#include <iostream>
#include "Canvas.h"

using namespace std;


int main()
{
    Canvas C(15, 15);

    C.SetPoint(3, 5, 'u');
    C.SetPoint(4, 4, '-');
    C.SetPoint(9, 13, '@');
    C.Print();

    C.Clear();
    C.Print();

    C.DrawCircle(8, 8, 4, '-');
    C.Print();

    C.FillCircle(8, 8, 4, '-');
    C.Print();

    C.DrawLine(1, 2, 4, 5, '@');
    C.Print();

    C.Clear();
    C.DrawRect(2, 2, 8, 8, '*');
    C.Print();

    C.FillRect(2, 2, 8, 8, '*');
    C.Print();

    C.Clear();
    C.Ellipse(6, 6, 5, 5, '$');
    C.Print();

    return 0;
}

