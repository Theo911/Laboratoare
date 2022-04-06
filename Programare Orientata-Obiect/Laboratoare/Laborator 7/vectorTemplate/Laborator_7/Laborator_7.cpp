#include <iostream>
#include "Liste.h"

using namespace std;

int my_compare(double a, double b)
{
	if (a < b)
		return -1;
	else
		if (a == b)
			return 0;
		else
			return 1;
}

int my_compare_2(double a, double b)
{
	if (a < b)
		return 1;
	else
		if (a == b)
			return 0;
		else
			return -1;
}

bool egal(double a, double b)
{
	return a == b;
}


int main()
{
	List<double> l;
	
	for (int i = 1; i < 10; i++)
	{
		l.push(i);
	}
	l.print();

	l.remove(5);

	l.print();

	double x = l.pop();
	cout << x << '\n';
	l.print();

	l.insert(0, 88);
	l.print();

	cout << "\n\n";

	double y = l.get(3);
	cout << y << '\n';

	cout << l.Count() << '\n';

	List<double> l2;
	l2 = l.sublist(0, 2);
	l2.print();		//1 2 3

	l.push(1.0);
	l.push(1.0);
	l.print();
	List<double> l3 = l.filter(1);		
	l3.print();		

	l.sort(my_compare);
	l.print();

	l.sort(my_compare_2);
	l.print();

	double foo = 50;
	l.set(foo, 8);
	l.print();

	double c = 4;
	cout << "indexul este " << l.firstIndexOf(c, egal);

	return 0;
}

