// Euler2.cpp : Definiert den Einstiegspunkt fuer die Konsolenanwendung.
//

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	unsigned int N = 0;
	unsigned long Fak = 0;
	const unsigned int Nmax = 12; // in unsigned long kann maximal 12! gespeichert werden
	bool bNok = false;
	double meinE = 0.0;
	double Proz = 0.0;
	unsigned int TabOpt = 0;
	bool bTab = false;
	unsigned int ExtraStellen = 0;

	cout << "Euler2: Ich berechne fuer Sie die Eulerzahl ueber eine Reihendarstellung." << endl;

	do
	{
		cout << endl << "Bitte geben Sie die Anzahl N der zu nutzenden Reihenglieder an: \n N = ";
		cin >> N;
		if (N <= Nmax) bNok = true;
		if (!bNok) cout << "\nFehler: der Wert von N darf maximal " << Nmax << " sein. Bitte erneute Eingabe..." << endl;

	} while (!bNok);
	ExtraStellen = (N > 6) ? 5 : 0;

	cout << endl << "Moechten Sie die Berechnungstabelle sehen? (0...nein, 1...ja) \n Wahl = ";
	cin >> TabOpt;
	bTab = (TabOpt == 0) ? false : true;
	// optionale Tabellenausgabe - Kopf
	if (bTab) 
	{
		cout << setw(5) << "n" << setw(10 + ExtraStellen) << "Naeherung" << setw(10 + ExtraStellen) << "Diff." << setw(10 + ExtraStellen/2) << "Proz." << endl;
		cout << setfill('-') << setw(35 + ExtraStellen * 2) << "" << setfill(' ') << endl;
	}

	Fak = 1;
	meinE = 1.0;

	//optionale Tabellenausgabe - Inhalt
	if (bTab) cout << setw(5) << 0 << setw(10 + ExtraStellen) << fixed << setprecision(5 + ExtraStellen) << meinE << setw(10 + ExtraStellen)
		<< M_E - meinE << setw(10 + ExtraStellen/2) << setprecision(2 + ExtraStellen/2) << abs(1. - meinE / M_E) * 100. << endl;

	for (int n = 1; (n <= N); n++)	// Def. der Schleifenvariablen, Bedingung und Inkrementierung in einem Statement
	{
		Fak = Fak * n;

		meinE = meinE + 1. / double(Fak);

		// optionale Tabellenausgabe
		if (bTab) cout << setw(5) << n << setw(10 + ExtraStellen) << fixed << setprecision(5 + ExtraStellen) << meinE << setw(10 + ExtraStellen)
			<< M_E - meinE << setw(10 + ExtraStellen/2) << setprecision(2 + ExtraStellen/2) << abs(1. - meinE / M_E) * 100. << endl;
	}

	//optionale Tabellenausgabe - Abschluss
	if (bTab) cout << setfill('-') << setw(35 + ExtraStellen * 2 + ExtraStellen/2) << "" << setfill(' ') << endl;

	//Ausgabe der reinen Fakulaet aus dem ersten Arbeitsschritt
	// cout << N << "! = " << Fak << endl;

	Proz = abs(1. - meinE / M_E) * 100.;

	cout << endl << "Mit " << N + 1 << " Summengliedern ergibt sich:  " << "e = " << setprecision(5 + ExtraStellen) << meinE << endl;
	cout << endl << "Das sind " << setprecision(2 + ExtraStellen/2) << fixed << Proz << setprecision(5 + ExtraStellen) 
		 << " % Abweichung vom echten Wert e = " << M_E << "\n" << endl;

	//system("pause");
    return 0;
}