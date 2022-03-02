#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;


Student::Student()
{
	strcpy(this->Nume, "");
	this->notaMatematica = -1;
	this->notaEngleza = -1;
	this->notaIstorie = -1;
}

void Student::setNume(char nume[])
{
	strcpy(this->Nume, nume);
}

char* Student::getNume()
{
	return this->Nume;
}

void Student::setNotaMatematica(int valoare)
{
	if (valoare >= 1 && valoare <= 10)
	{
		this->notaMatematica = valoare;
	}
}

float Student::getNotaMatematica()
{
	return this->notaMatematica;
}

void Student::setNotaEngleza(int valoare)
{
	if (valoare >= 1 && valoare <= 10)
	{
		this->notaEngleza = valoare;
	}
}

float Student::getNotaEngleza()
{
	return this->notaEngleza;
}

void Student::setNotaIstorie(int valoare)
{
	if (valoare >= 1 && valoare <= 10)
	{
		this->notaIstorie = valoare;
	}
}

float Student::getNotaIstorie()
{
	return this->notaIstorie;
}

float Student::mediaAritmetica()
{
	float medie = 0;
	medie += this->notaMatematica;
	medie += this->notaEngleza;
	medie += this->notaIstorie;
	medie /= 3;
	return medie;
}
