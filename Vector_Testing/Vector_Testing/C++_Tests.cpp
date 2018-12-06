#include <iostream>
using namespace std;

double mag(double vector[])
{
	double result = 0.0;

	for (int i = 0; i < 2; i++)
	{
		double temp = vector[i];
		result = result + temp * temp;
	}

	result = sqrt(result);

	return result;
}

void norm(double vector[])
{
	double magni = mag(vector);
	
}