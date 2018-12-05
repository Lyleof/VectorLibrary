//Vector Fucntion Testing (Assembly Version)
#include <iostream>
using namespace std;

extern "C" void _normalize();
extern "C" void _magnitude();
extern "C" void _scalar();
extern "C" void _vectorAdd();
extern "C" void _dotProduct();


int main() {
	int scalar = 3;
	double vector1[2] = { 1.2, 3.4 };
	double vector2[2] = { 5.6, 7.8 };
	double resultVector[2];
	double result;


	//normalize
	_asm {movaps xmm0, vector1}
	_normalize();
	_asm {movaps resultVector, xmm0}
	for (int i = 0; i < 1; i++)
	{
		cout << resultVector[i] << endl;
	}

	//Magnitude
	_asm {movaps xmm0, vector1}
	_magnitude();
	_asm {movaps result, xmm0}
	cout << result << endl;

	//Scalar
	_asm {movaps xmm0, vector1
		  movaps xmm1, scalar}
	_scalar();
	_asm {movaps resultVector, xmm0}
	for (int i = 0; i < 2; i++)
	{
		cout << resultVector[i] << endl;
	}

	//Vector Addition
	_asm {movaps xmm0, vector1
		  movaps xmm1, vector2}
	_vectorAdd();
	_asm {movaps resultVector, xmm0}
	for (int i = 0; i < 2; i++)
	{
		cout << resultVector[i] << endl;
	}

	//Dot Product
	_asm {movaps xmm0, vector1
	      movaps xmm1, vector2}
	_dotProduct();
	_asm {movaps result, xmm0}
	cout << result << endl;

	return 0;
}