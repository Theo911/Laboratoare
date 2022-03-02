#pragma once
#include <cstring>

class Student
{
public:
	char Nume[101];
	float notaMatematica;
	float notaEngleza;
	float notaIstorie;

public:

	Student();

	void setNume(char nume[]);
	char* getNume();

	void setNotaMatematica(int valoare);
	float getNotaMatematica();

	void setNotaEngleza(int valoare);
	float getNotaEngleza();

	void setNotaIstorie(int valoare);
	float getNotaIstorie();

	float mediaAritmetica();
};