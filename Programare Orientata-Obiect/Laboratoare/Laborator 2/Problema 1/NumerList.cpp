#include <iostream>
#include "NumberList.h"

using namespace std;


void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count >= 10)
	{
		return false;
	}
	this->numbers[this->count] = x;
	this->count++;
	return true;
}


void NumberList::Remove(int index)
{
	for (int i = index; i <= this->count; i++)
	{
		this->numbers[i] = this->numbers[i + 1];
	}
	this->count--;
}

void NumberList::Insert(int index, int valoare)
{
	this->count++;
	for (int i = this->count - 1; i > index; i--)
	{
		this->numbers[i] = this->numbers[i - 1];
	}
	this->numbers[index] = valoare;
}

void NumberList::InsertVector(int index, int v[], int n)
{
	this->count += n;
	for (int i = this->count - 1; i > index; i--)
	{
		this->numbers[i] = this->numbers[i - n];
	}

	for (int i = 0; i < n; i++)
	{
		this->numbers[index + i] = v[i];
	}
}


void NumberList::Sort()
{
	for (int i = 0; i < this->count - 1; i++)
	{
		for (int j = i + 1; j < this->count; j++)
		{
			if (this->numbers[i] > this->numbers[j])
			{
				int aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
		}
	}
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
	{
		cout << this->numbers[i] << ' ';
	}
	cout << '\n';
}

