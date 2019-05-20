// Lotto.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(NULL));
	unsigned int lottozahlen[6];
	double ratszahl, geld, x;
	bool test;
	geld = 5.;
	x = 0;
	cout << "6 zufaellige Zahlen werden generiert (von 1 bis 49)\n";
	//Generate Zufallszahl
	for (int i = 0; i < 6; i++) {
		lottozahlen[i] = rand() % 49 + 1;
		if (lottozahlen[i] == lottozahlen[i - 1]) {
			lottozahlen[i] = rand() % 49 + 1;
		}
		cout << lottozahlen[i] << "\t";
	}
	//Spielen
	while (true)
	{
		cout << "\nRaten: " << endl;
		cin >> ratszahl;
		for (int i = 0; i < 6; i++) {
			if (ratszahl == lottozahlen[i])
			{
				test = true; break;
			}
		}
		if (test == true) {
			cout << "Gewonnen! " << x << "Euros\n";
			break;
		}
		else {
			x = x + geld;
		}
	}
    return 0;
}

