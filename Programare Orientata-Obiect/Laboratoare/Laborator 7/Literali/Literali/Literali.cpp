#include <iostream>

using namespace std;


float operator"" _Kelvin(unsigned long long int x)
{
    float celsius = (float)x;
    celsius -= 273.15;
    return celsius;
}

float operator"" _Fahrenheit(unsigned long long int x)
{
    float celsius = (float)x;
    celsius -= 32;
    celsius /= 1.8;
    return celsius;
}



int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout << "300 de Kelvin in Celsius: " << a << '\n';
    cout << "120 de grade Fahrenheit in Celsius: " << b << '\n';

    return 0;

}