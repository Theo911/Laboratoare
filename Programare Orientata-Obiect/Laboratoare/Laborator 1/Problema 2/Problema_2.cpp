#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <ctype.h>

using namespace std;


int numar(char s[])
{
    int x = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        int cif = s[i] - '0';
        x = x * 10 + cif;
    }
    return x;
}


void rezolva()
{
    FILE* fisier = fopen("in.txt", "r");

    int x, suma = 0;
    char sir[128];
    while (!feof(fisier))
    {
        fscanf(fisier, "%s", sir);
        x = numar(sir);
        suma += x;
    }

    cout << suma;

    fclose(fisier);
}



int main()
{
    rezolva();
    return 0;
}

