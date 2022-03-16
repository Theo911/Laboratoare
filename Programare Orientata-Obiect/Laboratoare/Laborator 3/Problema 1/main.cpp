#include <iostream>
#include "Math.h"

using namespace std;


int main()
{
	Math m;
	cout << m.Add(4, 5) << '\n';
	cout << m.Add(8, 9, 10) << '\n';
	cout << m.Add(1.2, 4.7) << '\n';
	cout << m.Add(9.2, 11.8, 5.5) << '\n';
	cout << m.Mul(2, 3) << '\n';
	cout << m.Mul(2, 3, 4) << '\n';
	cout << m.Mul(1.1, 1.1) << '\n';
	cout << m.Mul(3.0, 4.5, 2.8) << '\n';
	
	cout << m.Add(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << '\n';

	char p[10];
	strcpy(p, m.Add("100", "200"));
	cout << p;

	return 0;
}
