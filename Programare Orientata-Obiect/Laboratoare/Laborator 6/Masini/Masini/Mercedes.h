#pragma once
#include "Car.h"

class Mercedes : public Car
{
public:
	Mercedes();
	float GoCar(bool& b, int, int) override;
	char* getName() override;
};

