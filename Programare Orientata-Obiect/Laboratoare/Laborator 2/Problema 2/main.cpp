#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;


int comparaNume(Student s1, Student s2)
{
	if (strcmp(s1.Nume, s2.Nume) == 0)
	{
		return 0;
	}
	else
		if (strcmp(s1.Nume, s2.Nume) > 0)
		{
			return 1;
		}
		else
		{
			return -1;
		}
}

int comparaNotaMatematica(Student s1, Student s2)
{
	if (s1.notaMatematica == s2.notaMatematica)
	{
		return 0;
	}
	else
		if (s1.notaMatematica > s2.notaMatematica)
		{
			return 1;
		}
		else
		{
			return -1;
		}
}

int comparaNotaEngleza(Student s1, Student s2)
{
	if (s1.notaEngleza == s2.notaEngleza)
	{
		return 0;
	}
	else
		if (s1.notaEngleza > s2.notaEngleza)
		{
			return 1;
		}
		else
		{
			return -1;
		}
}

int comparaNotaIstorie(Student s1, Student s2)
{
	if (s1.notaIstorie == s2.notaIstorie)
	{
		return 0;
	}
	else
		if (s1.notaIstorie > s2.notaIstorie)
		{
			return 1;
		}
		else
		{
			return -1;
		}
}

int comparaMedie(Student s1, Student s2)
{
	float medie_1 = s1.mediaAritmetica();
	float medie_2 = s2.mediaAritmetica();

	if (medie_1 == medie_2)
	{
		return 0;
	}
	else
		if (medie_1 > medie_2)
		{
			return 1;
		}
		else
		{
			return -1;
		}
}


void rezolva()
{
	Student stud_1;
	char nume_1[101];
	strcpy(nume_1, "Theo");
	stud_1.setNume(nume_1);
	stud_1.setNotaMatematica(9);
	stud_1.setNotaEngleza(10);
	stud_1.setNotaIstorie(10);

	
	Student stud_2;
	char nume_2[101];
	strcpy(nume_2, "Remus");
	stud_2.setNume(nume_2);
	stud_2.setNotaMatematica(7);
	stud_2.setNotaEngleza(9);
	stud_2.setNotaIstorie(10);

	//float medie1 = stud_1.mediaAritmetica();
	//float medie2 = stud_2.mediaAritmetica();
	//cout << medie1 << ' ' << medie2;
	
	cout << comparaNume(stud_1, stud_2) << '\n';
	cout << comparaNotaMatematica(stud_1, stud_2) << '\n';
	cout << comparaNotaEngleza(stud_1, stud_2) << '\n';
	cout << comparaNotaIstorie(stud_1, stud_2) << '\n';
	cout << comparaMedie(stud_1, stud_2) << '\n';

	return;
}


int main()
{
	rezolva();
	return 0;
}

