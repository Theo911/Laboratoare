#pragma once

class NumberList
{
	int numbers[10];
	int count;

public:
	void Init();
	bool Add(int x);

	void Remove(int index);
	void Insert(int index, int valoare);
	void InsertVector(int index, int v[], int n);

	void Sort();
	void Print();
};
