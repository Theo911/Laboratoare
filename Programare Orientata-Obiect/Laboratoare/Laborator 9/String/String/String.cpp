#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class CompareModule
{
public:
    bool operator() (const pair<string, int>& v1, const pair<string, int>& v2) const
    {
        if (v1.second == v2.second)
        {
            return v1.first < v2.first;
        }
        else
        {
            return v1.second > v2.second;
        }
    }
};


int main()
{
    fstream fisier;
    fisier.open("input.in");

    string fraza;
    getline(fisier, fraza);
    transform(fraza.begin(), fraza.end(), fraza.begin(), ::tolower);

    map<string, int> M;
    string delimitatori = " ,?!.";
    
    string aux;
    size_t gasit = fraza.find_first_of(delimitatori);
    aux = fraza.substr(0, gasit);
    M[aux]++;
    while (gasit != std::string::npos)
    {
        size_t gasit2 = fraza.find_first_of(delimitatori, gasit + 1);
        aux = fraza.substr(gasit + 1, gasit2 - gasit - 1);
        if (aux.length() > 0)
        {
            M[aux]++;
        }
        gasit = gasit2;
    }

    vector<string> cuv;

    cout << "Cuvintele din propozitie sunt:\n";
    map<string, int>::iterator it;
    for (it = M.begin(); it != M.end(); it++)
    {
        cout << it->first << ' ' << it->second << '\n';
        cuv.push_back(it->first);
    }
    cout << "\n\n";

    
    vector<pair<string, int>> pr;
    for (auto str : cuv)
    {
        pr.push_back(make_pair(str, M[str]));
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, CompareModule> foo;
    for (auto i : pr)
    {
        foo.push(i);
    }

    while (!foo.empty())
    {
        cout << foo.top().first << " => " << foo.top().second << '\n';
        foo.pop();
    }

    fisier.close();
    return 0;
}

