#pragma once

#include <iostream>

using namespace std;

template<typename T>
class List
{
	T* v;
	int count;
	int size;
	void resize();
public:
	List();

	void push(T element);
	void print();
	void sort(int (*compare)(T a, T b) = nullptr);

	T pop();
	void remove(int index);
	void insert(int index, T a);

	T& get(int index);
	void set(T x, int index);

	int Count();

	int firstIndexOf(T x, bool (*functie)(T a, T b) = nullptr);

	List<T> sublist(int i, int j);
	List<T> filter(T a);
};


template<typename T>
void List<T>::sort(int (*compare)(T a, T b))
{
	// v[i] = *(v + i)
	for (int i = 0; i < count - 1; i++) 
	{
		for (int j = i + 1; j < count; j++)
		{
			if (compare == nullptr)
			{
				if (v[i] < v[j] == false)
				{
					T aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}
			}
			else 
			{
				if (compare(v[i], v[j]) > 0)
				{
					T aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}

			}
		}
	}
}

template<typename T>
T List<T>::pop()
{
	T a = v[count - 1];
	count--;
	return a;
}

template<typename T>
void List<T>::remove(int index)
{
	if (index >= 0 && index < count)
	{
		//delete v[index];

		while (index < count - 1) 
		{
			v[index] = v[index + 1];
			index++;
		}
		count--;
	}
	else
	{
		if (index == count)
		{
			count--;
		}
	}
}

template<typename T>
inline void List<T>::insert(int index, T a)
{
	for (int i = count - 1; i >= index; i--)
	{
		v[i + 1] = v[i];
	}
	v[index] = a;
	count++;
}

template<typename T>
T& List<T>::get(int index)
{
	return v[index];
}

template<class T>
void List<T>::set(T t, int i) 
{
	if (i >= 0 && i < count)
	{
		v[i] = t;
	}
}

template<typename T>
inline int List<T>::Count()
{
	return this->count;
}

template<typename T>
int List<T>::firstIndexOf(T x, bool(*functie)(T a, T b))
{
	for (int i = 0; i < count; i++) 
	{
		if (functie == nullptr)
		{
			if (x == v[i])
			{
				return i;
			}
		}
		else 
		{
			if (functie(v[i], x))
			{
				return i;
			}
		}
	}
	return -1;
}

template<typename T>
List<T> List<T>::sublist(int i, int j)
{
	List<T> sol;
	for (int index = i; index <= j; index++)
	{
		//sol.push(v[index]);
		cout << v[index] << ' ';
	}
	return sol;
}

template<typename T>
List<T> List<T>::filter(T a)
{
	List<T> sol;
	for (int i = 0; i < count; i++)
	{
		if (v[i] != a)
		{
			sol.push(v[i]);
		}
	}
	return sol;
}

template<typename T>
void List<T>::resize()
{
	T* newV = new T[2 * size];

	for (int i = 0; i < count; ++i)
	{
		newV[i] = v[i];
	}
	delete[] v;
	v = newV;
	size *= 2;
}

template<typename T>
List<T>::List()
{
	v = new T[5];
	size = 5;
	count = 0;
}

template<typename T>
void List<T>::push(T element)
{
	if (count == size)
	{
		resize();
	}
	v[count] = element;
	count++;
}

template<typename T>
void List<T>::print()
{
	for (int i = 0; i < count; i++)
	{
		cout << v[i] << ' ';
	}
	cout << '\n';
}