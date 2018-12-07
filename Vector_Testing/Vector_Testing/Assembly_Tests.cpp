//Vector Function Testing (Assembly Version)
#include <iostream>
#include "timerSystem.h"
#include <time.h>
using namespace std;

//Assembly Prototypes
extern "C" void _normalize();
extern "C" void _magnitude();
extern "C" void _scalar();
extern "C" void _vectorAdd();
extern "C" void _dotProduct();


double mag(double vector[2])
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

void norm(double vector[2])
{
	double magni = mag(vector);

	for (int i = 0; i < 2; i++)
		vector[i] = vector[i] / magni;

	for (int i = 0; i < 2; i++)
		cout << vector[i] << ", ";
	cout << endl;

	return;

}

void scalar(double vector[2], double scalarNum)
{
	for (int i = 0; i < 2; i++)
		vector[i] = vector[i] * scalarNum;

	for (int i = 0; i < 2; i++)
		cout << vector[i] << ", ";
	cout << endl;

	return;
}

void add(double vector1[2], double vector2[2])
{
	for (int i = 0; i < 2; i++)
		vector1[i] = vector1[i] + vector2[i];

	for (int i = 0; i < 2; i++)
		cout << vector1[i] << ", ";
	cout << endl;

	return;
}

double dot(double vector1[2], double vector2[2])
{
	double result = 0.0;

	for (int i = 0; i < 2; i++)
		result = result + vector1[i] * vector2[i];

	return result;
}

int main() {
	double scalarNum = 3.0;
	double vector1[2] = { 1.2, 3.4 };
	double vector2[2] = { 5.6,7.8 };
	double resultVector[2] = { 0.0, 0.0 };
	double result;
	double time = 0;
	TimerSystem timer;

	cout << "Assembly Results" << endl;
	cout << "-----------------" << endl;

	//Normalize 
	cout << "Normalized (assembly):  " << endl;
	_asm {movupd xmm0, vector1}
	timer.startClock();
	_normalize();
	_asm{movupd resultVector, xmm0}
	time += timer.getTime();
	for (int i = 0; i < 2; i++)
		cout << resultVector[i] << ", ";
	cout << endl;

	cout << "-----------------" << endl;

	//Magnitude
	cout << "Magnitude(assembly):  " << endl;
	_asm{movupd xmm0, vector1}
	timer.startClock();
	_magnitude();
	_asm{movupd result, xmm0}
	time += timer.getTime();
	cout << result << endl;

	cout << "-----------------" << endl;

	//Scalar
	cout << "Scalar (assembly): " << endl;
	_asm{movupd xmm0, vector1
		movsd xmm1, scalarNum}
	timer.startClock();
	_scalar();
	_asm{movupd resultVector, xmm0}
	time += timer.getTime();
	for (int i = 0; i < 2; i++)
		cout << resultVector[i] << ", ";
	cout << endl;

	cout << "-----------------" << endl;

	//Vector Addition
	cout << "Vector Addition (assembly):   " << endl;
	_asm{movupd xmm0, vector1
		movupd xmm1, vector2}
	timer.startClock();
	_vectorAdd();
	_asm{movupd resultVector, xmm0}
	time += timer.getTime();
	for (int i = 0; i < 2; i++)
		cout << resultVector[i] << ", ";
	cout << endl;

	cout << "-----------------" << endl;

	//DotProduct
	cout << "Dot Product (assembly):   " << endl;
	_asm{movupd xmm0, vector1
		movupd xmm1, vector2}
	timer.startClock();
	_dotProduct();
	_asm{movupd result, xmm0}
	time += timer.getTime();
	cout << result << endl;

	cout << "-----------------" << endl;
	cout << "Total Assembly Calculation Time: " << time << endl;
	cout << "-----------------" << endl;


	cout << "C++ Results" << endl;
	cout << "-----------------" << endl;
	time = 0.0;

	cout << "Normalized:  " << endl;
	timer.startClock();
	norm(vector1);
	time += timer.getTime();

	vector1[0] = 1.2;
	vector1[1] = 3.4;
	vector2[0] = 5.6;
	vector2[1] = 7.8;

	cout << "-----------------" << endl;

	cout << "Magnitude:   " << endl;
	timer.startClock();
	result = mag(vector1);
	time += timer.getTime();
	cout << result << endl;

	vector1[0] = 1.2;
	vector1[1] = 3.4;
	vector2[0] = 5.6;
	vector2[1] = 7.8;

	cout << "-----------------" << endl;

	cout << "Scalar:  " << endl;
	timer.startClock();
	scalar(vector1, scalarNum);
	time += timer.getTime();

	vector1[0] = 1.2;
	vector1[1] = 3.4;
	vector2[0] = 5.6;
	vector2[1] = 7.8;

	cout << "-----------------" << endl;

	cout << "Vector Addition:   " << endl;
	timer.startClock();
	add(vector1, vector2);
	time += timer.getTime();

	vector1[0] = 1.2;
	vector1[1] = 3.4;
	vector2[0] = 5.6;
	vector2[1] = 7.8;

	cout << "-----------------" << endl;

	cout << "Dot Product:  " << endl;
	timer.startClock();
	result = dot(vector1, vector2);
	time += timer.getTime();
	cout << result << endl;

	cout << "-----------------" << endl;
	cout << "Total C++ Calculation Time: " << time << endl;
	cout << "-----------------" << endl;
	cin.get();
	cin.get();


	return 0;
}