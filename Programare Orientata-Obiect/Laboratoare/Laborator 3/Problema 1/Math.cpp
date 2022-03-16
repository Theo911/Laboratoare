#include <iostream>
#include <stdarg.h>
#include "Math.h"

using namespace std;

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	int suma = 0;

	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		int nr = va_arg(args, int);
		suma += nr;
	}
	va_end(args);

	return suma;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
	{
		return nullptr;
	}

	int x = 0;
	for (int i = 0; i < strlen(a); i++)
	{
		x = x * 10 + (a[i] - '0');
	}
	

	int y = 0;
	for (int i = 0; i < strlen(b); i++)
	{
		y = y * 10 + (b[i] - '0');
	}

	int suma = x + y;
	int lg = 0;

	int aux = suma;
	do
	{
		lg++;
		aux /= 10;
	} while (aux);

	
	char* suma_sir = new char;
	_itoa(suma, suma_sir, 10);

	return suma_sir;
}