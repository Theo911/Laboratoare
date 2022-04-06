#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
	//prim = new Nod;
	//prim->element = 0;
	//prim->next = NULL;
	prim = NULL;
}


int LinkedList::operator[](unsigned index)
{
	Nod* pr = prim;
	int k = 0;
	while (k != index  && pr != NULL)
	{
		pr = pr->next;
		k++;
	}
	return pr->element;
}

void LinkedList::push_front(int x)
{
	Nod* aux = new Nod;
	aux->element = x;
	aux->next = prim;
	prim = aux;
}

void LinkedList::push_back(int x)
{
	Nod* aux = new Nod;
	aux->element = x;
	aux->next = NULL;
	if (prim == NULL)
	{
		prim = aux;
	}
	else
	{
		Nod* p = prim;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = aux;
	}
}

bool LinkedList::empty()
{
	return prim == NULL;
}

int LinkedList::size()
{
	int k = 0;
	Nod* aux = prim;
	while (aux)
	{
		aux = aux->next;
		k++;
	}
	return k;
}

int LinkedList::front()
{
	Nod* aux = prim;
	prim = prim->next;
	return aux->element;
}

int LinkedList::back()
{
	Nod* aux = prim;
	while (aux->next->next != NULL)
	{
		aux = aux->next;
	}
	int x = aux->next->element;
	aux->next = NULL;
	return x;
}
