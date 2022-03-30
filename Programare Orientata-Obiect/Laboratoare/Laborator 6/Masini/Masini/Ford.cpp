#include "Car.h"
#include "Ford.h"
#include "Weather.h"

using namespace std;

Ford::Ford() {
	fuelCapacity = 68;
	fuelConsumption = 6;
	averageSpeed[Rain] = 65;
	averageSpeed[Sunny] = 95;
	averageSpeed[Snow] = 45;
	name = (char*)"Ford";
}

float Ford::GoCar(bool& b, int w, int circuitLength) 
{
	int speed = averageSpeed[w];

	float hours = fuelCapacity / fuelConsumption;
	float distance = hours * speed;

	b = distance > circuitLength;
	return (hours * circuitLength / distance);
}

char* Ford::getName()
{
	return name;
}

