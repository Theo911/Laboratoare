#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
    srand(time(NULL));

    Sort S1(10, 50, 100);
    S1.Print();

    cout << "Lungimea vectorului este: " << S1.GetElementsCount() << '\n';

    cout << S1.GetElementFromIndex(3) << ' ' << S1.GetElementFromIndex(7) << '\n';
    cout << S1.GetElementFromIndex(1758) << '\n';

    cout << "\n\n";

    S1.BubbleSort(true);
    cout << "Sortare crescatoare(folosind BubbleSort):";
    S1.Print();
    S1.BubbleSort();
    cout << "Sortare descrescatoare(folosind BubbleSort):";
    S1.Print();

    cout << "\n\n";

    Sort S2({ 20, 10, 50, 30, 40 });
    S2.Print();
    S2.QuickSort(0, 4, true);
    cout << "Sortare crescatoare(folosind QuickSort):";
    S2.Print();
    S2.QuickSort(0, 4);
    cout << "Sortare descrescatoare(folosind QuickSort):";
    S2.Print();

    cout << "\n\n";

    int vect[] = { 23, 12, 60 };
    Sort S3(vect, 3);
    S3.Print();
    S3.InsertSort(true);
    cout << "Sortare crescatoare(folosind InsertSort):";
    S3.Print();
    S3.InsertSort();
    cout << "Sortare descrescatoare(folosind InsertSort):";
    S3.Print();

    cout << "\n\n";

    Sort S4(10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    S4.Print();

    cout << "\n\n";

    Sort S5("10,40,100,5,70");
    S5.Print();
    cout << S5.GetElementsCount();

    cout << "\n\n";

    S1.BubbleSort(true);
    S3.BubbleSort(true);
    S1.Print();
    S3.Print();
    S1.Merge(S3);

    return 0;
}

