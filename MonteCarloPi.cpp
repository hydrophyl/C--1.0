// MonteCarloPi.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double Koordinate(double radius){
	double zufallszahl;
	zufallszahl = double(rand()) / double(RAND_MAX) * radius;
	return zufallszahl;
}

int main()
{
	//einmalig oder mehrmals wählen
	int howmuch;
	cout << "Wie oft? Einmalig Ausfuehrung [1], bestimmte Anzahl [n] eingeben: ";
	cin >> howmuch;

	switch (howmuch)
	{
	// n Mals als default
		default:
		{
			cout << "Programm wird " << howmuch << " mals durchlaufen !" << endl;
			//Radius
			double r;
			float anzahl;
			float pi;
			cout << "Radius: ";
			cin >> r;
			if (r < 0) {
				cout << "Radius muss groesser als 0!" << endl << "Radius: ";
				cin >> r;
			}
			//Erste Mal laufen
				cout << "Anzahl der Regentropfen: ";
				cin >> anzahl;
				if (anzahl < 0) {
					cout << "Anzahl der Regentropfen muss groesser als 0!" << endl << "Anzahl der Regentropfen: ";
					cin >> anzahl;
				}
				//Für jeden Punkt zufällige x, y Werte
				double x, y;
				float imKreis = 0;
				for (int i = 1; i <= anzahl; i++)
				{
					x = Koordinate(r);
					y = Koordinate(r);
					if (x*x + y*y <= r*r) {
						imKreis++;
					}
				}
			float pineu;
			pineu = 4 * (imKreis / anzahl);
			pi = pineu;
			cout << "Pineu 1: " << pineu << endl;
			//Naeherungswert pi definieren = Mittelwert aller PiNeus
			for (int i = 1; i < howmuch; i++)
			{
				//Anfang des ersten Teils
				cout << "Anzahl der Regentropfen: ";
				cin >> anzahl;
				if (anzahl < 0) {
					cout << "Anzahl der Regentropfen muss groesser als 0!" << endl << "Anzahl der Regentropfen: ";
					cin >> anzahl;
				}
				//Für jeden Punkt zufällige x, y Werte
				imKreis = 0;
				for (int i = 1; i <= anzahl; i++)
				{
					x = Koordinate(r);
					y = Koordinate(r);
					if (x*x + y*y <= r*r)
					{
						imKreis++;
					}
				}
				// Nachrechnungen
				float pineu;
				pineu = 4 * (imKreis / anzahl);
				pi = (pi + pineu);
				//Ende des ersten Teils
				// Zum Testen
				cout << "Pineu " << i << ": " << pineu << endl
					<< "Anzahl der erzeugten Tropfen: " << anzahl << endl
					<< "Anzahl der Tropfen im Kreis: " << imKreis << endl
					<< "Summe Pi: " << pi << endl;
			}

			//Ausgabe
			cout << "Pi: " << pi/howmuch << endl
				<< "Wahrer Wert von PI: " << M_PI << endl
				<< "Unterschied \"PI - Naherungswert\": " << M_PI / pi << endl
				<< "Prozentualer Fehler: " << (1.0 - (pi/howmuch) / M_PI)*100.0 << " %" << endl;
			break;
		}
		// 1 Mal
		case 1:
		{
			double r;
			float anzahl;
			float pi;
			cout << "Programm wird nur 1 mal durchfuehren! " << endl;
			//Anfang des ersten Teils
			cout << "Radius: ";
			cin >> r;
			if (r < 0) {
				cout << "Radius muss groesser als 0!" << endl << "Radius: ";
				cin >> r;
			}
			cout << "Anzahl der Regentropfen: ";
			cin >> anzahl;
			if (anzahl < 0) {
				cout << "Anzahl der Regentropfen muss groesser als 0!" << endl << "Anzahl der Regentropfen: ";
				cin >> anzahl;
			}
			cout << "Test Koordinate: " << Koordinate(r) << endl;
			//Für jeden Punkt zufällige x, y Werte
			float imKreis = 0;
			double x, y;
			for (int i = 1; i <= anzahl; i++)
			{
				x = Koordinate(r);
				y = Koordinate(r);
				if (x*x + y*y <= r*r) {
					imKreis++;
				}
			}
			pi = 4 * (imKreis / anzahl);

			//Ende des ersten Teils

			cout << "Anzahl der erzeugten Tropfen: " << anzahl << endl
				<< "Anzahl der Tropfen im Kreis: " << imKreis << endl
				<< "Pi: " << pi << endl
				<< endl
				<< "Wahrer Wert von PI: " << M_PI << endl
				<< "Unterschied \"PI - Naherungswert\": " << M_PI / pi << endl
				<< "Prozentualer Fehler: " << (1.0 - pi / M_PI)*100.0 << " %" << endl;
			break;
		}
	}
    return 0;
}

