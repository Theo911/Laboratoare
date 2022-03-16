#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdarg.h>

using namespace std;


Sort::Sort(int nr_elemente, int min, int max)
{
	srand(time(NULL));

	nr = nr_elemente;
	v[nr] = {};
	for (int i = 0; i < nr; i++)
	{
		int val = rand() % max + 1;
		while (val < min)
		{
			val = rand() % max + 1;
		}
		v[i] = val;
	}
}

Sort::Sort(initializer_list<int> list)
{
	nr = 0;
	v[nr] = {};
	for (int x : list)
	{
		v[nr] = x;
		nr++;
	}

	/*
	Sau:
	initializer_list<int>::iterator it;
	for (it = list.begin(); it != list.end(); ++it)
	{
		v[nr] = *it;
		nr++;
	}
	*/
}

Sort::Sort(int a[], int dim)
{
	nr = dim;
	v[nr] = {};
	for (int i = 0; i < nr; i++)
	{
		v[i] = a[i];
	}
}

Sort::Sort(int count, ...)
{
	nr = count;
	v[nr] = {};
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		v[i] = va_arg(args, int);
	}
	va_end(args);
}

Sort::Sort(const char* sir)
{
	nr = 0;
	v[nr] = {};

	char aux[1001];
	strcpy(aux, sir);
	char* p = strtok(aux, ",");
	while (p)
	{
		int x = atoi(p);
		v[nr] = x;
		nr++;
		p = strtok(NULL, ",");
	}
}

void Sort::InsertSort(bool ascendent)
{
	if (ascendent == true)
	{
		for (int i = 1; i <= nr - 1; i++)
		{
			int j = i - 1;
			int temp = v[i];
			while (j >= 0 && v[j] > temp)
			{
				v[j + 1] = v[j];
				j--;
			}
			if (v[j + 1] != temp)
			{
				v[j + 1] = temp;
			}
		}
	}
	else
	{
		for (int i = 1; i <= nr - 1; i++)
		{
			int j = i - 1;
			int temp = v[i];
			while (j >= 0 && v[j] < temp)
			{
				v[j + 1] = v[j];
				j--;
			}
			if (v[j + 1] != temp)
			{
				v[j + 1] = temp;
			}
		}
	}
}

void Sort::QuickSort(int st, int dr, bool ascendent)
{
	if (ascendent == true)
	{
		if (st < dr)
		{
			int m = (st + dr) / 2;
			long aux = v[st];
			v[st] = v[m];
			v[m] = aux;
			int i = st, j = dr, d = 0;
			while (i < j)
			{
				if (v[i] > v[j])
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
					d = 1 - d;
				}
				i += d;
				j -= 1 - d;
			}
			QuickSort(st, i - 1, ascendent);
			QuickSort(i + 1, dr, ascendent);
		}
	}
	else
	{
		if (st < dr)
		{
			int m = (st + dr) / 2;
			long aux = v[st];
			v[st] = v[m];
			v[m] = aux;
			int i = st, j = dr, d = 0;
			while (i < j)
			{
				if (v[i] < v[j])
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
					d = 1 - d;
				}
				i += d;
				j -= 1 - d;
			}
			QuickSort(st, i - 1, ascendent);
			QuickSort(i + 1, dr, ascendent);
		}
	}
}

void Sort::BubbleSort(bool ascendent)
{
	if (ascendent == true)
	{
		int ultim = nr - 1;
		while (ultim > 0)
		{
			int n1 = ultim - 1;
			ultim = 0;
			for (int i = 0; i <= n1; i++)
			{
				if (v[i] > v[i + 1])
				{
					swap(v[i], v[i + 1]);
					ultim = i;
				}
			}
		}
	}
	else
	{
		int ultim = nr - 1;
		while (ultim > 0)
		{
			int n1 = ultim - 1;
			ultim = 0;
			for (int i = 0; i <= n1; i++)
			{
				if (v[i] < v[i + 1])
				{
					swap(v[i], v[i + 1]);
					ultim = i;
				}
			}
		}
	}
}

void Sort::Print()
{
	cout << "\nElementele vectorului sunt: ";
	for (int i = 0; i < nr; i++)
	{
		cout << v[i] << ' ';
	}
	cout << '\n';
}

int Sort::GetElementsCount()
{
	return nr;
}

int Sort::GetElementFromIndex(int index)
{
	if (index < nr)
	{
		return v[index];
	}
	return -1;
}

void Sort::Merge(Sort s)
{
	cout << "Interclasarea celor 2 instante este: ";
	int n = nr;
	int m = s.nr;

	int i = 0;
	int j = 0;

	while (i < n && j < m)
	{
		if (v[i] < s.v[j])
		{
			cout << v[i] << ' ';
			i++;
		}
		else
			if (s.v[j] < v[i])
			{
				cout << s.v[j] << ' ';
				j++;
			}
			else
			{
				cout << v[i] << ' ' << s.v[j] << ' ';
				i++;
				j++;
			}
	}

	while (i < n)
	{
		cout << v[i] << ' ';
		i++;
	}

	while (j < m)
	{
		cout << s.v[j] << ' ';
		j++;
	}

	cout << '\n';
}
