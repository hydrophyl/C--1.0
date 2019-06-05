// Studierende.cpp : Definiert den Einstiegspunkt fuer die Konsolenanwendung.
//
/* Dies ist hier unsere ganz normale Programmdatei.
 * Diese weiss zunaechst von der Klasse Studi, die ueber die 
 * Studi.h und Studi.cpp - Dateien definiert ist, nichts.
 */

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

/* Durch Einbinden der h-Datei der Klasse, wird diese hier verfuebar gemacht, 
 * so dass man nun Objekte anlegen kann (d.h. die Klasse als Datentyp nutzen kann)
 * und auf die mit "public" gekennzeichneten Attribute und Methoden zugreifen kann. 
 */
#include "Studi.h"

using namespace std;

int main()
{
	/* Wenn wir mit den Attributen des Objektes hier im Programm arbeiten wollen,
	 * brauchen wir dazu entsprechende Variablen, sinnvollerweise vom gleichen Typ.
	 */
	unsigned long MatNr = 0;
	string Vorname = "";
	string Nachname= "";
	bool isMale = false;
	char geschl = ' ';
	string sFach = "";
	string eMail = "";
	bool weiter = false;


	cout << endl
		<< "Herzlich willkommen bei der Studierendenverwaltung!" << endl
		<< "===================================================" << endl << endl;

	// Wir erzeugen das erste Studi-Objekt
	Studi stud1;
	/* Ab jetzt ist im Speicher ein entsprechendes Objekt angelegt.
	 * Fuer die 4 definierten Attribute wurde der entsprechende Speicher reserviert.
	 * Die Referenzvariable "stud1" verweist nun auf diesen Bereich und das Objekt
	 * kann ueber diese Namen aufgerufen werden.
	 */

	cout << "Bitte geben Sie den Vornamen des 1.Studis an:" << endl;
	cin >> Vorname;
	// jetzt koennen wir den Vornamen ueber die set-Methode im Objekt speichern
	stud1.setVorname(Vorname);

	cout << "Bitte geben Sie den Nachnamen des 1.Studis an:" << endl;
	cin >> Nachname;
	// jetzt koennen wir den Nachnamen ueber die set-Methode im Objekt speichern
	stud1.setNachname(Nachname);

	do
	{
		weiter = true;
		cout << "Bitte geben Sie die 7-stellige Matrikelnummer des 1.Studis an:" << endl;
		MatNr = 0;
		cin >> MatNr;
		if (!stud1.setMatNr(MatNr))
		{
			cout << "Falsche Eingabe. Gueltig sind nur Werte > 1700000 und < 2999999." << endl;
			weiter = false;
		}
	} while (!weiter);

	do
	{
		cout << "Bitte geben Sie das Geschlecht des Studis an: m...männlich, w...weiblich." << endl;
		cin >> geschl;
		if (geschl != 'm' && geschl != 'w')
		{
			cout << "Falsche Eingabe. Bitte erneute Eingabe..." << endl;
		}
	} while (geschl != 'm' && geschl != 'w');
	stud1.setIsMale(geschl);

	cout << "Bitte geben Sie das Studienfach des 1.Studis an:" << endl;
	cin >> sFach;
	stud1.setsFach(sFach);

	cout << "Bitte geben Sie die eMail-Adresse des 1.Studis an:" << endl;
	cin >> eMail;
	stud1.setEmail(eMail);

	/* Und nun geben wir mit Hilfe der get-Methoden die Inhalte des 1.Studi-Objektes wieder aus
	 */
	cout << endl;
	cout << "Die Daten des 1.Studis lauten:" << endl
		<< ((stud1.getIsMale()) ? "Herr " : "Frau ")
		<< stud1.getVorname() << " " <<  stud1.getNachname() << endl
		<< "Matrikelnummer = " << stud1.getMatNr() << endl
		<< "studiert: " << stud1.getSFach() << endl
		<< "eMail-Adresse lautet: " << stud1.getEmail() << endl << endl;


/* Hier kommt der optionale Teil
 */

	cout << "Bitte geben Sie den Vornamen des 2.Studis an:" << endl;
	cin >> Vorname;

	cout << "Bitte geben Sie den Nachnamen des 2.Studis an:" << endl;
	cin >> Nachname;

	do
	{
		cout << "Bitte geben Sie die 7-stellige Matrikelnummer des 2.Studis an:" << endl;
		cin >> MatNr;
		if (!(MatNr > 1700000 && MatNr < 2999999))
		{
			cout << "Falsche Eingabe, bitte wiederholen. Fuer gueltige MatNr gilt: 1700000 < MatNr < 2999999." << endl;
		}
	} while (!(MatNr > 1700000 && MatNr < 2999999));

	do
	{
		cout << "Bitte geben Sie das Geschlecht des Studis an: m...männlich, w...weiblich." << endl;
		cin >> geschl;
		if (geschl != 'm' && geschl != 'w')
		{
			cout << "Falsche Eingabe. Bitte erneute Eingabe..." << endl;
		}
	} while (geschl != 'm' && geschl != 'w');

	cout << "Bitte geben Sie das Studienfach des 2.Studis an:" << endl;
	cin >> sFach;

	cout << "Bitte geben Sie die eMail-Adresse des 2.Studis an:" << endl;
	cin >> eMail;

	/* Hier werden nun alle Werte gespeichert.
	 * Das Problem ist hier, dass die Ueberpruefung der Matr.Nr. hier nicht über den 
	 * Konsstruktor möglich ist. Also muss die Abfrage hier beim Einlesen durchgefuehrt werden. 
	 */
	Studi stud2(MatNr);
	stud2.setVorname(Vorname);
	stud2.setNachname(Nachname);
	stud2.setIsMale(geschl);
	stud2.setsFach(sFach);
	stud2.setEmail(eMail);

	cout << "Die Daten des 2.Studis lauten:" << endl
		<< ((stud2.getIsMale()) ? "Herr " : "Frau ")
		<< stud2.getVorname() << " " << stud2.getNachname() << endl
		<< "Matrikelnummer = " << stud2.getMatNr() << endl
		<< "studiert: " << stud2.getSFach() << endl
		<< "eMail-Adresse lautet: " << stud2.getEmail() << endl << endl;

	system("pause");
    return 0; 
}
