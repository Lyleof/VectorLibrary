//Vector Function Testing (Assembly Version)
#include <iostream>
using namespace std;

extern "C" void _normalize();
extern "C" void _magnitude();
extern "C" void _scalar();
extern "C" void _vectorAdd();
extern "C" void _dotProduct();

int main() {
	double scalarNum = 3.0;
	double vector1[2] = { 1.2, 3.4 };
	double vector2[2] = { 5.6,7.8 };
	double resultVector[2];
	double result;

	//Normalize
	_asm {movapd xmm0, vector1}
	_normalize();
	_asm{movapd resultVector, xmm0}
	for (int i = 0; i < 2; i++)
		cout << resultVector[i] << endl;

	//Magnitude
	_asm{movapd xmm0, vector1}
	_magnitude();
	_asm{movapd result, xmm0}
	cout << result << endl;

	//Scalar
	_asm{movapd xmm0, vector1
		movsd xmm1, scalarNum}
	_scalar();
	_asm{movapd resultVector, xmm0}
	for (int i = 0; i < 2; i++)
		cout << resultVector[i] << endl;

	//Vector Addition
	_asm{movapd xmm0, vector1
		movapd xmm1, vector2}
	_vectorAdd();
	_asm{movapd resultVector, xmm0}
	for (int i = 0; i < 2; i++)
		cout << resultVector[i] << endl;

	//DotProduct
	_asm{movapd xmm0, vector1
		movapd xmm1, vector2}
	_dotProduct();
	_asm{movapd result, xmm0}
	cout << result << endl;

	return 0;
}