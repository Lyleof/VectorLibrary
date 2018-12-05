/*Source.cpp
This file is going to have a series of vector math functions, to be used as a comparison to an assembly version*/

#include <iostream>
#include <vector>
using namespace std;

//Simple function to just print a vector
void printVect(vector<double> vect) {
	cout << "< ";
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << ", ";
	}
	cout << ">" << endl;
}

//Function that find the magnitude of a vector
double mag(vector<double> vect) {
	double result = 0;

	for (int i = 0; i < vect.size(); i++) {
		int temp;
		temp = vect[i];
		result = result + temp * temp;
	}

	result = sqrt(result);

	return result;
}

//Function that normalizes a vector
vector<double> norm(vector<double> vect) {
	double magnitude = mag(vect);
	vector<double> newVect(vect.size());

	for (int i = 0; i < vect.size(); i++) {
		newVect[i] = vect[i] / magnitude;
	}

	return newVect;
}

//Function that uses a scalar on a vector
vector<double> scalar(vector<double> vect, double scalar) {
	vector<double> newVect(vect.size());

	for (int i = 0; i < vect.size(); i++) {
		newVect[i] = vect[i] * scalar;
	}

	return newVect;
}

//Function that adds two vectors together
vector<double> add(vector<double> vect1, vector<double> vect2) {
	vector<double> newVect(vect1.size());

	for (int i = 0; i < vect1.size(); i++) {
		newVect[i] = vect1[i] + vect2[i];
	}

	return newVect;
}

//Function that finds the dot product of two vectors
double dot(vector<double> vect1, vector<double> vect2) {
	double result = 0;

	for (int i = 0; i < vect1.size(); i++) {
		result = result + vect1[i] * vect2[i];
	}

	return result;
}

//Main used to simply test and print the vector math functions
int main() {
	vector<double> vect1{ 1.2, 3.4 }, vect2{ 5.6, 7.8}, resultVect;
	double scalar = 3.0;


	cout << "Magnitude: " << mag(vect1) << endl;

	resultVect = norm(vect1);
	cout << "Normalized: ";
	printVect(resultVect);

	resultVect = scalar(vect1, 3);
	cout << "Scalar: ";
	printVect(resultVect);

	resultVect = add(vect1, vect2);
	cout << "Add: ";
	printVect(resultVect);

	cout << "Dot Product: " << dot(vect1, vect2) << endl;

	cin.get();
	return 0;
}
