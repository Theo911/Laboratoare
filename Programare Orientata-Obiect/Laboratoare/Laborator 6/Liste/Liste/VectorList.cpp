#include "VectorList.h"
#include <iostream>

using namespace std;

VectorList::VectorList()
{
	n = 0;
}

int VectorList::operator[](unsigned index)
{
	return v[index];
}

void VectorList::push_front(int x)
{
	n++;
	for (int i = n - 1; i >= 0; i--)
		v[i + 1] = v[i];
	v[0] = x;

}

void VectorList::push_back(int x)
{
	v[n] = x;
	n++;
}

bool VectorList::empty()
{
	return n == 0;
}

int VectorList::size()
{
	return n;
}

int VectorList::front()
{
	int x = v[0];
	for (int i = 1; i <= n; i++)
	{
		v[i - 1] = v[i];
	}
	n--;
	return x;
}

int VectorList::back()
{
	int x = v[n];
	n--;
	return x;
}
