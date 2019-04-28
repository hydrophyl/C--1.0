// MonteCarloPi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _USE_MATH_DEFINE
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double Koordinate(double radius) {
	double zufallszahl;
	zufallszahl = double(rand()) / double(RAND_MAX) * radius;
	return zufallszahl;
}

int main()
{
	double r;
	int tropf;
	srand(unsigned int(time(0)));
    cout << "Hello World!\n"; 
	cout << "Radius des Kreises: ";
	cin >> r;
	if (r < 0) {
		cout << "FALSCHE Radius!"; 
		cout << "Radius: "; cin >> r;
	}
	cout << "radius: " << r << endl;
	cout << "Anzahl der Regentropfen: ";
	cin >> tropf;
	if (tropf < 0) {
		cout << "FALSCHE Anzahl der Tropfchen" << endl
			<< "Anzahl der Tropfen: ";
		cin >> tropf;
	}

	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
