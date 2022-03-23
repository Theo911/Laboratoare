#include <iostream>
#include "Number.h"

using namespace std;


Number::Number(const char* value, int base)
{
	if (base >= 2 && base <= 16)
	{
		baza = base;
		strcpy(valoare, value);
	}
	else
	{
		cout << "Baza de numeratie incorecta";
	}
}

Number::~Number()
{
	//delete valoare;
	//valoare = nullptr;
	//baza = NULL;
}

Number::Number(const Number& n)			//constructor de copiere
{
	baza = n.baza;
	strcpy(valoare, n.valoare);
}

Number::Number(Number&& n)				//constructor de mutare
{
	baza = n.baza;
	strcpy(valoare, n.valoare);
	strcpy(n.valoare, "");
}

Number::Number(const int n)
{
	baza = 10;
	char aux[101];
	_itoa(n, aux, 10);
	strcpy(valoare, aux);
}

void Number::SwitchBase(int newBase)
{
	if (newBase >= 2 && newBase <= 16)
	{
		long x = valoareaInBazaZece(valoare, baza);
		char aux[102];
		_itoa(x, aux, newBase);
		strcpy(valoare, aux);
		baza = newBase;
	}
}

void Number::Print()
{
	for (int i = 0; valoare[i] != '\0'; i++)
	{
		cout << valoare[i];
	}
	cout << "\n";
}

int Number::GetDigitsCount()
{
	return strlen(valoare);
}

int Number::GetBase()
{
	return baza;
}

long Number::valoareaInBazaZece(char* sir, int bazaNum)
{
	long x = 0, p = 1;
	for (int i = strlen(sir) - 1; i >= 0; i--)
	{
		x += getDigit(sir[i]) * p;
		p *= bazaNum;
	}
	return x;
}

char* Number::convertToBase(long n, int base)
{
	char* c = new char[101];
	int i = 0;

	while (n != 0) 
	{
		int d = n % base;
		c[i++] = getChar(d);

		n /= base;
	}

	c[i] = '\0';

	for (int l = 0; l < i / 2; l++)
	{
		char aux = c[l];
		c[l] = c[i - l - 1];
		c[i - l - 1] = aux;
	}

	return c;
}

int Number::getDigit(char c)
{
	if (c >= 'A')
		return c - 'A' + 10;
	else
		return c - '0';
}

char Number::getChar(int n)
{
	if (n >= 10)
	{
		return 'A' + (n - 10);
	}
	else
	{
		return '0' + n;
	}
}

char Number::operator[](int i)
{
	return valoare[i];
}

bool Number::operator>(Number& n)
{
	long x = valoareaInBazaZece(valoare, baza);
	long y = valoareaInBazaZece(n.valoare, n.baza);
	
	if (x > y)
	{
		return 1;
	}
	return 0;
}

void Number::operator=(const char* sir)
{
	Number n(sir, 10);
	*this = n;
}

void Number::operator=(const Number& n)
{
	baza = n.baza;
	strcpy(valoare, n.valoare);
}

void Number::operator=(int n)
{
	baza = 10;
	char aux[101];
	_itoa(n, aux, 10);
	strcpy(valoare, aux);
}

Number Number::operator|(Number n2)
{
	Number Concat;

	if (this->baza == n2.baza)
	{
		char sol[201];
		sol[0] = '\0';
		strcat(sol, valoare);
		strcat(sol, n2.valoare);
		strcpy(Concat.valoare, sol);
		Concat.baza = baza;
	}
	else
	{
		if (baza > n2.baza)
		{
			Concat.baza = baza;
			n2.SwitchBase(baza);
			char sol[201];
			sol[0] = '\0';
			strcat(sol, valoare);
			strcat(sol, n2.valoare);
			strcpy(Concat.valoare, sol);
		}
		else
		{
			Concat.baza = n2.baza;
			this->SwitchBase(n2.baza);
			char sol[201];
			sol[0] = '\0';
			strcat(sol, valoare);
			strcat(sol, n2.valoare);
			strcpy(Concat.valoare, sol);
		}
	}

	//Number Concat;
	//char sol[201];
	//sol[0] = '\0';
	//strcat(sol, valoare);
	//strcat(sol, n2.valoare);
	//strcpy(Concat.valoare, sol);
	//if (baza > n2.baza)
	//{
	//	Concat.baza = baza;
	//}
	//else
	//{
	//	Concat.baza = n2.baza;
	//}

	return Concat;
}

void Number::operator+=(Number& n)
{
	long nr = valoareaInBazaZece(valoare, baza);
	nr += valoareaInBazaZece(n.valoare, n.baza);

	char aux[101];
	_itoa(nr, aux, 10);

	strcpy(valoare, aux);

	SwitchBase(baza);
}

void Number::operator--()
{
	char aux[101];
	aux[0] = '\0';
	strcat(aux, valoare + 1);
	strcpy(valoare, aux);
}

void Number::operator--(int)
{
	valoare[strlen(valoare) - 1] = '\0';
}

Number operator+(const Number& x, const Number& y)
{
	Number a = x;
	Number b = y;

	int bazaMaiMare;
	if (a.GetBase() > b.GetBase())
	{
		bazaMaiMare = a.GetBase();
	}
	else
	{
		bazaMaiMare = b.GetBase();
	}

	long nr = a.valoareaInBazaZece(a.valoare, a.baza);
	nr += b.valoareaInBazaZece(b.valoare, b.baza);

	char c[101];
	_itoa(nr, c, 10);

	Number nrNou(c, 10);
	nrNou.SwitchBase(bazaMaiMare);

	return nrNou;
}

Number operator-(const Number& x, const Number& y)
{
	Number a = x;
	Number b = y;

	int bazaMaiMare;
	if (a.GetBase() > b.GetBase())
	{
		bazaMaiMare = a.GetBase();
	}
	else
	{
		bazaMaiMare = b.GetBase();
	}

	long nr = a.valoareaInBazaZece(a.valoare, a.baza);
	nr -= b.valoareaInBazaZece(b.valoare, b.baza);

	char c[101];
	_itoa(nr, c, 10);

	Number nrNou(c, 10);
	nrNou.SwitchBase(bazaMaiMare);

	return nrNou;
}