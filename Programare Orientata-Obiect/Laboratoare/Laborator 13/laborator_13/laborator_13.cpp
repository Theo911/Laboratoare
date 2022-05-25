#include <iostream>
#include <cstring>

#include "Clase.h"

using namespace std;


int main()
{
    Prieten p;
    cout << p.GetNume() << ' ' << p.GetAdresa() << ' ' << p.GetDataNastere() << ' ' << p.GetNrTelefon() << ' ' << p.GetTip() << '\n';

    Cunoscut c;
    cout << c.GetNume() << ' ' << c.GetNrTelefon() << ' ' << c.GetTip() << '\n';

    Coleg g;
    cout << g.GetNume() << ' ' << g.GetAdresa() << ' ' << g.GetNrTelefon() << ' ' << g.GetServiciu() << ' ' << g.GetTip() << '\n';

    cout << "\n\n";

    Agenda a;
    a.adauga(&p);
    a.adauga(&g);
    a.adauga(&c);

    a.Afiseaza();

    Contact* x = a.Cauta("James Webb");
    cout << x->GetNume() << ' ' << x->GetTip() << '\n';

    a.Save("test.txt");

    a.Sterge("James Webb");
    a.Afiseaza();

    return 0;
}
