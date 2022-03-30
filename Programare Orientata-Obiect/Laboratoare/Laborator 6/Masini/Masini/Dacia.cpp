#include "Car.h"
#include "Dacia.h"
#include "Weather.h"

using namespace std;

Dacia::Dacia() 
{
	fuelCapacity = 54;
	fuelConsumption = 20;
	averageSpeed[Rain] = 40;
	averageSpeed[Sunny] = 60;
	averageSpeed[Snow] = 25;
	name = (char*)"Dacia";
}

float Dacia::GoCar(bool& b, int w, int circuitLength) 
{
	int speed = averageSpeed[w];

	float hours = fuelCapacity / fuelConsumption;
	float distance = hours * speed;

	b = distance > circuitLength;
	return (hours * circuitLength / distance);
}

char* Dacia::getName() 
{
	return name;
}
