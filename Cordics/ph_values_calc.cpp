#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>

int main()
{
	//double pi = 3.141592653589793238463;
	double ph = 1.;
	std::cout << ph << ", ";

	for (int i = 1; i < 201; i++)
	{
		ph = ph / 2;
		std::cout << ph << ", ";

	}
}