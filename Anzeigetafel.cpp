// Anzeigetafel.cpp : Definiert den Einstiegspunkt fuer die Konsolenanwendung.
//

#include <iostream>
#include <iomanip>

using namespace std;

// zwei globale Variablen fuer die Groesse der Anzeigetafel
const int Breite = 120;
const int Hoehe = 11;

// Die Anzeige wird komplett geleert, indem Leerzeichen eingesetzt werden.
// ueber den Parameter kann gesteuert werden, ob ein Rahmen um das Feld gezeichnet werden soll, oder nicht.
void AnzeigeLeeren(char Anzeige[Hoehe][Breite], bool bRahmen)
{
	// Variante ueber die Indices des Arrays
	for (int Zeile = 0; Zeile<Hoehe; Zeile++)
		for (int Spalte = 0; Spalte<Breite; Spalte++)
			Anzeige[Zeile][Spalte] = ' ';

	// optional ergaenzen: Variante ueber Pointer, geht schneller
	// ...

	// Rahmen um das Anzeigefeld zeichnen.
	// Hierzu kann man einfache Striche nutzen, oder die Blocksymbole aus der ASCII-Tabelle.
	if (bRahmen)
	{
		// einfacher Rahmen
		char hZchn = '-'; // hier koennte man den ASCII-Code des Blocksymbols eingeben
		char vZchn = '|'; // dann koennte man die vier Ecken anders behandeln und muesste den folgenden Code ergaenzen.

						  // optional ergaenzen: Rahmen aus Blockgrafik-Symbolen des ASCII-Codes
						  // ...

		for (int Spalte = 1; Spalte<(Breite - 1); Spalte++)
		{
			Anzeige[0][Spalte] = hZchn;
			Anzeige[Hoehe - 1][Spalte] = hZchn;
		}

		for (int Zeile = 0; Zeile<Hoehe; Zeile++)
		{
			Anzeige[Zeile][0] = vZchn;
			Anzeige[Zeile][Breite - 1] = vZchn;
		}

		// optional ergaenzen: bei Blockgrafik-Symbolen hier ggf. Code fuer die vier Ecken ergaenzen
		//...
	}

	return;
}

void ZeichenHolen(char Zeichen[8][8], const char Zchn)
{
	/* Diese Funktion erstellt die Muster fuer die zu druckenden Zeichen.
	Sie koennte ergaenzt werden auf das gesamte Alphabet.
	*/

	// zun?chst Feld leeren

	// Variante ueber die Indices des Arrays
	for (int Zeile = 0; Zeile < 8; Zeile++) {
		for (int Spalte = 0; Spalte < 8; Spalte++) {
			Zeichen[Zeile][Spalte] = ' ';
		}
	}

	// optional ergaenzen: Variante ueber Pointer, geht schneller
	// .....

	// dann Muster setzen
	switch (Zchn)
	{
	case 'F':
		for (int Zeile = 1; Zeile<8; Zeile++)
			for (int Spalte = 1; Spalte<3; Spalte++)
				Zeichen[Zeile][Spalte] = Zchn;

		for (int Spalte = 3; Spalte<8; Spalte++)
		{
			Zeichen[1][Spalte] = Zchn;
			Zeichen[4][Spalte] = Zchn;
		}
		break;

	case 'I':
		for (int Zeile = 1; Zeile<8; Zeile++)
			for (int Spalte = 6; Spalte<8; Spalte++)
				Zeichen[Zeile][Spalte] = Zchn;

		Zeichen[1][3] = Zchn;
		Zeichen[1][4] = Zchn;
		Zeichen[1][5] = Zchn;
		Zeichen[7][3] = Zchn;
		Zeichen[7][4] = Zchn;
		Zeichen[7][5] = Zchn;
		break;

	case 'N':
		for (int Zeile = 1; Zeile<8; Zeile++)
		{
			for (int Spalte = 1; Spalte<3; Spalte++)
				Zeichen[Zeile][Spalte] = Zchn;
			Zeichen[Zeile][7] = Zchn;
		}
		Zeichen[1][2] = Zchn;
		Zeichen[2][2] = Zchn;
		Zeichen[3][3] = Zchn;
		Zeichen[4][4] = Zchn;
		Zeichen[4][5] = Zchn;
		Zeichen[5][5] = Zchn;
		Zeichen[6][6] = Zchn;
		Zeichen[7][6] = Zchn;
		break;

	case '2':
		for (int Spalte = 1; Spalte<8; Spalte++)
		{
			Zeichen[1][Spalte] = Zchn;
			Zeichen[7][Spalte] = Zchn;
		}
		Zeichen[1][1] = ' ';
		Zeichen[1][7] = ' ';
		Zeichen[2][1] = Zchn;
		Zeichen[2][2] = Zchn;
		Zeichen[2][6] = Zchn;
		Zeichen[3][5] = Zchn;
		Zeichen[2][7] = Zchn;
		Zeichen[3][6] = Zchn;
		Zeichen[4][4] = Zchn;
		Zeichen[4][5] = Zchn;
		Zeichen[5][3] = Zchn;
		Zeichen[6][3] = Zchn;
		Zeichen[5][4] = Zchn;
		Zeichen[6][2] = Zchn;
		break;

	case 'P':
		for (int Zeile = 1; Zeile<8; Zeile++)
			for (int Spalte = 1; Spalte<3; Spalte++)
				Zeichen[Zeile][Spalte] = Zchn;

		for (int Spalte = 3; Spalte<8; Spalte++)
		{
			Zeichen[1][Spalte] = Zchn;
			Zeichen[4][Spalte] = Zchn;
		}
		Zeichen[1][7] = ' ';
		Zeichen[4][7] = ' ';
		Zeichen[2][7] = Zchn;
		Zeichen[3][7] = Zchn;
		Zeichen[2][6] = Zchn;
		Zeichen[3][6] = Zchn;
		break;

	case 'S':
		for (int Zeile = 1; Zeile < 8; Zeile = Zeile + 3) {
			for (int Spalte = 2; Spalte < 8; Spalte++) {
				Zeichen[Zeile][Spalte] = Zchn;
			}
		}
		Zeichen[2][2] = Zchn;
		Zeichen[3][2] = Zchn;
		Zeichen[2][3] = Zchn;
		Zeichen[3][3] = Zchn;
		Zeichen[5][6] = Zchn;
		Zeichen[6][6] = Zchn;
		Zeichen[5][7] = Zchn;
		Zeichen[6][7] = Zchn;
		Zeichen[4][2] = Zchn;
		Zeichen[4][7] = Zchn;
		break;

	case 'A':
		for (int Zeile = 1; Zeile<8; Zeile++)
			for (int Spalte = 1; Spalte<3; Spalte++)
				Zeichen[Zeile][Spalte] = Zchn;
		for (int Zeile = 2; Zeile<8; Zeile++)
			for (int Spalte = 6; Spalte<8; Spalte++)
				Zeichen[Zeile][Spalte] = Zchn;

		for (int Spalte = 3; Spalte<8; Spalte++)
		{
			Zeichen[1][Spalte] = Zchn;
			Zeichen[4][Spalte] = Zchn;
		}

		Zeichen[1][1] = ' ';
		Zeichen[1][7] = ' ';
		Zeichen[2][7] = Zchn;
		Zeichen[3][7] = Zchn;
		break;

	default:
		// dieses Zeichen ist noch nicht definiert.
		cout << "\nFehler: Das Muster fuer\' " << Zchn << "\' wurde noch nicht definiert." << endl;
	}

	return;
}

void ZeichenSetzen(char Anzeige[Hoehe][Breite], const char Zeichen[8][8], const int Pos)
{
	int SpOffset = 1 + Pos * 8;
	int ZeiOffset = 0;

	for (int Zeile = 0; Zeile<8; Zeile++)
	{
		ZeiOffset = 1 + Zeile;
		for (int Spalte = 0; Spalte<8; Spalte++)
			Anzeige[ZeiOffset][SpOffset + Spalte] = Zeichen[Zeile][Spalte];
	}

	return;
}

void Ausgabe(char Anzeige[Hoehe][Breite])
{
	// Variante ueber Indices des Array
	for (int Zeile = 0; Zeile<Hoehe; Zeile++)
	{
		for (int Spalte = 0; Spalte<Breite; Spalte++)
			cout << Anzeige[Zeile][Spalte];
	}

	// optional ergaenzen: Variante ueber Zeiger ist schneller
	// ...

	return;
}


// ************************************
int main()
{
	char Anzeige[Hoehe][Breite];
	char Zeichen[8][8];
	bool Rahmen = true;
	int Pos = 0;

	// Anzeige leeren, d.h. hier Initialisieren
	AnzeigeLeeren(Anzeige, Rahmen);

	// Ausgabe zeichenweise zusammensetzen

	Pos = 0;
	ZeichenHolen(Zeichen, 'I');
	ZeichenSetzen(Anzeige, Zeichen, Pos);
	Pos = 1;
	ZeichenHolen(Zeichen, 'N');
	ZeichenSetzen(Anzeige, Zeichen, Pos);
	Pos = 2;
	ZeichenHolen(Zeichen, 'F');
	ZeichenSetzen(Anzeige, Zeichen, Pos);
	Pos = 3;
	ZeichenHolen(Zeichen, '2');
	ZeichenSetzen(Anzeige, Zeichen, Pos);

	Pos = 4;

	Pos = 5;
	ZeichenHolen(Zeichen, 'S');
	ZeichenSetzen(Anzeige, Zeichen, Pos);
	Pos = 6;
	ZeichenHolen(Zeichen, 'P');
	ZeichenSetzen(Anzeige, Zeichen, Pos);
	Pos = 7;
	ZeichenHolen(Zeichen, 'A');
	ZeichenSetzen(Anzeige, Zeichen, Pos);
	Pos = 8;
	ZeichenHolen(Zeichen, 'S');
	ZeichenSetzen(Anzeige, Zeichen, Pos);
	Pos = 9;
	ZeichenHolen(Zeichen, 'S');
	ZeichenSetzen(Anzeige, Zeichen, Pos);
	// Ausgabe der fertigen Anzeige
	Ausgabe(Anzeige);

	// Optional ergaenzen: Ausgabe als Laufband
	// ...

	return 0;
}
