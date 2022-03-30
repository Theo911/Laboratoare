#include <iostream>
#include "Car.h"
#include "Weather.h"
#include "Circuit.h"
#include <string>
using namespace std;

Circuit::Circuit() 
{
	circuitLength = 0;
	cars = 0;
}

void Circuit::SetLength(int l) 
{
	circuitLength = l;
}

void Circuit::SetWeather(int w)
{
	weather = w;
}

void Circuit::AddCar(Car* c) 
{
	car[cars++] = c;
}

void Circuit::Race() 
{
	for (int i = 0; i < cars; i++) 
	{
		bool b = false;
		timeToFinish[i] = car[i]->GoCar(b, weather, circuitLength);
		finish[i] = b;
	}
}

void Circuit::ShowFinalRanks() 
{
	for (int i = 0; i < cars - 1; i++)
	{
		if (finish[i])
		{
			for (int j = i + 1; j < cars; j++)
			{
				if (finish[j])
				{
					if (timeToFinish[i] > timeToFinish[j])
					{
						swap(car[i], car[j]);
						swap(timeToFinish[i], timeToFinish[j]);
					}
				}
			}
		}
	}
	cout << "Timpul masinilor care au terminat cursa: \n";
	for (int i = 0; i < cars; i++) 
	{
		if (finish[i])
		{
			cout << car[i]->getName() << " : " << timeToFinish[i] << '\n';
		}
	}
	cout << '\n';
}

void Circuit::ShowWhoDidNotFinish()
{
	cout << "Timpul masinilor care NU au terminat cursa: \n";
	for (int i = 0; i < cars; i++)
	{
		if (!finish[i]) 
		{
			cout << car[i]->getName() << " : " << timeToFinish[i] << ' ';
		}
	}
	cout << '\n';
}

