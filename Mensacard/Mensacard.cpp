// Mensacard.cpp : Definiert den Einstiegspunkt fuer die Konsolenanwendung.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "Karte.h"

using namespace std;

void myPause(){
	cout << "Press ENTER to continue...";
	cin.clear();
	cin.sync();
	cin.get();
}

int main()
{
	char opt;
	double Betrag = 0.0;
	// Karte wird erzeugt, jedoch noch ohne Daten
	// jede neu erstellte Karte hat 50.00 Euro Guthaben
	// (1) ... Karte erzeugen
	Karte karte1;
	cout << "********************"
		<< "* Mensacard-Dialog *"
		<< "********************" << endl << endl;

	{ // ein Block zur Kartenbefuellung
		string Vorname = "";
		string Nachname = "";
		unsigned int MatNr = 0;

		cout << "Zur Generierung Ihrer Mensacard benoetige ich einige Daten:"
			<< "\n\nBitte geben Sie Ihren Vornamen ein: ";
		cin >> Vorname;
		cout << "\nBitte geben Ihren Nachnamen ein: ";
		cin >> Nachname;
		cout << "\nUnd Ihre Matrikelnummer: ";
		cin >> MatNr;

		// Karte wird mit den persoenlichen Daten gefuellt
		// (2) ... Daten speichern
		karte1.setValues(MatNr,Vorname,Nachname);
	}

	do {
		system("clear");
		cout << "Sie haben folgende Moeglichenkeiten:\n\n"
			<< "a...Guthaben anzeigen lassen\n\n"
			<< "b...Mahlzeit zahlen\n\n"
			<< "x...Dialog beenden\n\n"
			<< "Ihre Wahl: ";
		cin >> opt;

		bool genugGeld;
		switch (opt)
		{
		case 'A': // fall-through
		case 'a':
			// (3)... Ausgabe ergaenzen
			cout << "\n\nDie Karte gehoert: " << karte1.getVorname() << " " << karte1.getNachname() << " mit der Matrikelnummer: " << karte1.getMatNr() << "\n"
				<< "Ihr Guthaben auf der Karte betraegt aktuell: " << setprecision(2) << fixed << karte1.getKonto() << " Euro.\n" << endl;
			myPause();
			break;
		case 'B': // fall-through
		case 'b':
			cout << "\nWie viel kostet diese Mahlzeit in Euro\n(Dezimaltrenner ist der Punkt): ";
			cin >> Betrag;
			// Pruefen des Kartenguthabens
			// (4) ... Pruefung ergaenzen
			genugGeld = (karte1.getKonto() > Betrag) ? true:false;
			cout << "Ihre Konto hat noch: " << karte1.getKonto() << " Euros" << endl;
			if (genugGeld == true)
			{
				// Geld von Karte buchen
				// (5)... Ausgabe ergaenzen
				cout << "\nDer Betrag von " << setprecision(2) << fixed << Betrag << " Euro wurde von Ihrer Karte abgebucht."
					<< "\nIhr Restguthaben auf der Karte betraegt nun: " << karte1.getKonto() - Betrag << " Euro.\n" << endl;
				karte1.setKonto(karte1.getKonto() - Betrag);
			}
			else
			{
				// Geld reicht nicht aus
				cout << "\nLeider reicht das Guthaben Ihrer Karte nicht mehr aus.\n"
					<< "Bitte zahlen Sie jetzt in bar und laden Sie die Karte spaeter auf.\n" << endl;
			}
			myPause();
			break;
		case 'x':
			break;
		default:
			cout << "\nFEHLER: Diese Option steht leider nicht zur Verfuegung.\n\n" << endl;
			opt = ' ';
			break;
		}
	} while (opt != 'x');

	// (6) ....Ausgabe ergaenzen
	cout << "\n\nDie Karte von " << karte1.getVorname() << " " << karte1.getNachname()  << " mit der Matrikelnummer " << karte1.getMatNr()
		<< "\nweist noch ein Guthaben von " << setprecision(2) << fixed << karte1.getKonto() << " auf."
		<< "\nDie Karte wird nun vernichtet." << endl;

	cout << "\nAuf Wiedersehen in der Mensa Ihre Wahl...\n\n" << endl;
	myPause();
	return 0;
}
