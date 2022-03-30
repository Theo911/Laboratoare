#include "Car.h"
#include "Toyota.h"
#include "Weather.h"
#include <string>

using namespace std;

Toyota::Toyota() 
{
	fuelCapacity = 70;
	fuelConsumption = 3;
	averageSpeed[Rain] = 52;
	averageSpeed[Sunny] = 70;
	averageSpeed[Snow] = 45;
	name = (char*)"Toyota";
}

float Toyota::GoCar(bool& b, int w, int circuitLength) 
{
	int speed = averageSpeed[w];

	float hours = fuelCapacity / fuelConsumption;
	float distance = hours * speed;

	b = distance > circuitLength;
	return (hours * circuitLength / distance);
}

char* Toyota::getName()
{
	return this->name;
}

