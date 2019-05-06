// DateiPlotter.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Prototyp der Funktionsauswahl-Funktion
double f(double x, unsigned int iFun);

// Prototyp der Plotter-Funktion
void Plotter(const double xWerte[], const double yWerte[], int AnzWerte, bool bFuellen);


int main()
{
	const unsigned int FunAnzahl = 4;
	unsigned int iFunk = 0;

	const int MaxAnzWerte = 70;
	double xmin = 0.0;
	double xmax = 0.0;
	double xStep = 0.0;

	int AnzWerte = 0;
	double xWerte[MaxAnzWerte];
	double yWerte[MaxAnzWerte];

	unsigned int Darstellung = 0;

	string FunkText[FunAnzahl] = { "sin(x)","cos(x)","x*exp(x)","ln(x)" };

	cout << "\nProgramm zum Plotten einer Funktion"
		<< "\n===================================" << endl;

	// gewünschte Funktion abfragen
	do
	{
		cout << "\nWelche Funktion soll dargestellt werden?"
			<< "\n1..." << FunkText[0]
			<< "\n2..." << FunkText[1]
			<< "\n3..." << FunkText[2]
			<< "\n4..." << FunkText[3]
			<< "\n" << endl;
		cin >> iFunk;

		if ((iFunk <= 0) || (iFunk > FunAnzahl))
			cout << "\nWaehlen Sie zwischen 1 bis " << FunAnzahl << "."
			<< "\nErneute Eingabe erforderlich."
			<< endl;

	} while ((iFunk <= 0) || (iFunk > FunAnzahl));

	// Abfrage des Bereichs der x-Werte
	do
	{
		cout << "\nBitte geben Sie die linke Grenze der x-Werte ein: ";
		cin >> xmin;

		cout << "\nBitte geben Sie die rechte Grenze der x-Werte ein: ";
		cin >> xmax;

		if (xmin >= xmax)
			cout << "\n\nDie linke Grenze muss kleiner sein als die rechte Grenze, bitte erneut eingeben.\n" << endl;

	} while (xmin >= xmax);


	cout << "\nAnzahl der x-Werte <= 70 : ";
	cin >> AnzWerte;
	AnzWerte = (AnzWerte < MaxAnzWerte) ? AnzWerte : MaxAnzWerte;
	xStep = abs(xmax - xmin) / (AnzWerte - 1);

	bool bFuellen = false;
	cout << "\nWas soll gezeichnet werden?"
		<< "\n1...Kurve\n2...Flaeche ? " << endl;
	cin >> Darstellung;
	bFuellen = (Darstellung == 2); // bei Fehleingabe wird immer die Kurve dargestellt

	for (int i = 0; i<AnzWerte; i++)
	{
		xWerte[i] = xmin + i * xStep;
		yWerte[i] = f(xWerte[i], iFunk);
	}

	// Aufruf der Plotter-Funktion
	Plotter(xWerte, yWerte, AnzWerte, bFuellen);


	system("pause");
	return 0;
}
