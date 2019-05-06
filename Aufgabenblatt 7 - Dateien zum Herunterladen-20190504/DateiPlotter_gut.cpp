// DateiPlotter.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Plotter.cpp"
using namespace std;

// Prototyp der Plotter-Funktion
void Plotter(const double xWerte[], const double yWerte[], int AnzWerte, bool bFuellen);


int main()
{
	const int MaxAnzWerte = 100;
	double xmin = 0.0;
	double xmax = 0.0;
	double xStep = 0.0;

	int AnzWerte = 0;
	double xWerte[MaxAnzWerte];
	double yWerte[MaxAnzWerte];

	unsigned int Darstellung = 0;

	cout << "\nProgramm zum Plotten einer Funktion"
		<< "\n===================================" << endl;

	// Abfrage des Bereichs der x-Werte
    unsigned int count;
    ifstream data1;
    string s,v;
    //read data
    data1.open("DatenEinlesen1.txt");
    data1 >> s >> v; 

    int i = 0;
    while(data1.good()){
        data1 >> xWerte[i] >> yWerte[i];
        i++;
    }
    count = i;
    data1.close();
	
	cout << "Counted: " << count << endl;
	do
	{
		cout << "\nBitte geben Sie die linke Grenze der x-Werte ein: ";
		cin >> xmin;

		cout << "\nBitte geben Sie die rechte Grenze der x-Werte ein: ";
		cin >> xmax;

		if (xmin >= xmax)
			cout << "\n\nDie linke Grenze muss kleiner sein als die rechte Grenze, bitte erneut eingeben.\n" << endl;

	} while (xmin >= xmax);

	cout << "\nAnzahl der x-Werte <= 100 : ";
	cin >> AnzWerte;
	AnzWerte = (AnzWerte < MaxAnzWerte) ? AnzWerte : MaxAnzWerte;
	
	xStep = abs(xmax - xmin) / (AnzWerte - 1);

	bool bFuellen = false;
	cout << "\nWas soll gezeichnet werden?"
		<< "\n1...Kurve\n2...Flaeche ? " << endl;
	cin >> Darstellung;
	bFuellen = (Darstellung == 2); // bei Fehleingabe wird immer die Kurve dargestellt
	
	//Write results to file
	ofstream data2;
	data2.open("Plot_zu_DatenEinlesen1.txt");
	

	// Aufruf der Plotter-Funktion
	Plotter(xWerte, yWerte, AnzWerte, bFuellen);

	return 0;
}
