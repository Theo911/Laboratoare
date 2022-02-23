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



void sortare(char a[][101], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (strlen(a[i]) < strlen(a[j]))
            {
                swap(a[i], a[j]);
            }
            else
                if (strlen(a[i]) == strlen(a[j]))
                {
                    if (strcmp(a[i], a[j]) < 0)
                    {
                        swap(a[i], a[j]);
                    }
                }
        }
    }
}


void rezolva()
{
    char sir[256];
    printf("Introdu propozitia: ");
    //fgets(sir, 256, stdin);
    cin.get(sir, 256);

    char a[101][101];
    int n = -1;

    char* cuv = strtok(sir, " ");
    while (cuv)
    {
        strcpy(a[++n], cuv);
        cuv = strtok(NULL, " ");
    }

    sortare(a, n);
    for (int i = 0; i <= n; i++)
    {
        cout << a[i] << '\n';
    }

}



int main()
{
    rezolva();
    return 0;
}

