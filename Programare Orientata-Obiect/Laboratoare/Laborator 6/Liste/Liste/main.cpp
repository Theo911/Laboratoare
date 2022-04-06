#include <iostream>
#include "Lista.h"
#include "VectorList.h"
#include "LinkedList.h"

using namespace std;


int main()
{
    List* l = new VectorList();
    List* l2 = new LinkedList();

    for (int i = 0; i < 10; ++i) 
    {
        l->push_back(i);
        l2->push_back(i);
    }

    l->push_front(56);

    l2->push_front(78);


    for (int i = 0; i < l->size(); ++i) 
    {
        cout << (*l)[i] << ' ';
    }
    cout << '\n';

    for (int i = 0; i < l->size(); ++i)
    {
        cout << (*l2)[i] << ' ';
    }
    cout << '\n';

    cout << "Este vectorul gol? " << (*l).empty() << '\n';
    cout << "Este lista goala? " << (*l2).empty() << '\n';

    cout << "Numarul de elemente: " << (*l).size() << '\n';
    cout << "Numarul de elemente: " << (*l2).size() << '\n';

    int x = (*l).front();
    cout << "Primul element: " << x << '\n';

    int y = (*l2).back();
    cout << "Ultimul element este: " << y << '\n';

    int z = (*l2).back();
    cout << "Ultimul element este: " << z << '\n';

    int t = (*l2).front();
    cout << "Primul element este: " << t << '\n';

    int k = (*l2).front();
    cout << "Primul element este: " << k << '\n';

    return 0;
}
