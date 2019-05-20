// Integral.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

double f1(double x){
	double funktion;
	funktion = sin(x);
	return funktion;
}
double f2(double x){
	double funktion;
	funktion = cos(x);
	return funktion;
}
double f3(double x){
	double funktion;
	funktion = exp(x);
	return funktion;
}
double f4(double x){
	double funktion;
	funktion = log(x);
	return funktion;
}

double numIntegral(double xmin, double xmax, unsigned int n, unsigned int iFunk) {

	double integral;
	double h = (xmax - xmin) / n;
	double x, f;
	double ungerade = 0;
	double gerade = 0;
	for (unsigned int i = 1; i < n; i++) {

		x = xmin + i*h;

		switch (iFunk)
		{
		case 1:
			f = f1(x);
			break;
		case 2:
			f = f2(x);
			break;
		case 3:
			f = f3(x);
			break;
		case 4:
			f = f4(x);
			break;
		default:
			cout << "Irgendwas ist schief gegangen!FIXME \n";
			break;
		}

		if (i % 2 == 0) {
			gerade = gerade + f;
		}
		else {
			ungerade = ungerade + f;
		}
	}
	integral = (h / 3) * ( sin(xmin) + 4 * ungerade + 2 * gerade + sin(xmax) );
	return integral;
}

int main()
{
	//Define variables
	double integral_min, integral_max;
	unsigned int n;									//Intervalle n
	unsigned int iFunk;											//Funktion? 1 - 4 #sin, cos, exp, log

	//Anfang Funktion?
	while (true)
	{
		cout<< "Programm zur numerischen Integration\n"
		   		 "====================================\n"
		<< "Welche Funktion soll integriert werden?\n"
		<< "1... sin(x)\n2... cos(x)\n3... x*exp(x)\n4... ln(x)\n";
		cin >> iFunk;
		if (iFunk == 1 || iFunk == 2 || iFunk == 3 || iFunk == 4){
			break;
		}
	}
	
	//Min, max input
	while (true)
	{
		cout << "Integral min: "; cin >> integral_min;
		cout << "Integral max: "; cin >> integral_max;
		cout << "Intervalle n: "; cin >> n;
		if (integral_max > integral_min && n%2 == 0) {
			break;
		}
		cout << "Falsche Eingabe!\n";
	}
	//printf("min = %.3f \nmax = %.3f\n", integral_min, integral_max);
	switch (iFunk)
	{
	case 1:
		cout << "Funktion: " << setw(20) << left << "sin(x)" << endl;
		break;
	case 2:
		cout << "Funktion: " << setw(20) << left << "cos(x)" << endl;
		break;
	case 3:
		cout << "Funktion: " << setw(20) << left << "exp(x)" << endl;
		break;
	case 4:
		cout << "Funktion: " << setw(20) << left << "log(x)" << endl;
		break;
	
	default:
		break;
	}
	
	cout << "linke Grenze: " << setw(20) << left << integral_min << endl
		<< "rechte Grenze: " << setw(20) << left << integral_max << endl
		<< "Intervalle: " << setw(20) << left << n << endl
		<< "Integralwert: " << setw(20) << left << fixed << setprecision(5) << numIntegral(integral_min, integral_max, n, iFunk) << endl << endl;
    return 0;
}

