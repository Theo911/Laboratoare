#include <iostream>
#include "Map.h"

using namespace std;


int main()
{
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "este";
    m[30] = "simplu";

    m.Set("greu", 30);

    m.Print();

    int aux1 = 20;
    const char* aux2;
    bool exista = m.Get(aux1, aux2);
    if (exista)
    {
        cout << aux1 << ": " << aux2 << '\n';
    }
    else
    {
        cout << "-1\n";
    }

    cout << m.Count() << '\n';

    m.Clear();

    m.Print();


    Map<int, const char*> x;
    x[20] = "Buna";
    x[50] = "ziua";
    x[80] = "soare";

    bool sters = x.Delete(80);
    if (sters)
    {
        x.Print();
    }
    else
    {
        cout << "Elementul cu cheia cautata nu exista\n\n";
    }
    x[80] = "soare";


    Map<int, const char*> y;
    y[20] = "Buna";
    y[50] = "ziua";
    y[80] = "soare";

    bool include = x.Includes(y);
    if (include)
    {
        cout << "Mapa este inclusa!\n\n";
    }
    else
    {
        cout << "Mapa NU este inclusa!\n\n";
    }


    Map<int, const char*> z;
    z[4] = "Buna";
    z[5] = "seara";
    z[6] = "luna";
    x.Swap(z);
    x.Print();
    z.Print();

    x.Add(z);
    x.Print();

    for (auto [key, value, index] : y)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}
