#include <iostream>
#include <string>

using namespace std;

class Karte{
private:
	string m_vorname;
	string m_nachname;
	unsigned long m_matNr;

public:
	Karte();
	~Karte();

bool setValues(unsigned long matnr, string vorname, string nachname);
unsigned long getMatNr(void);
bool setKonto(double neukonto);

string getVorname(void);
string getNachname(void);
double getKonto();
double getRestguthaben(double konto, double auszahlen);
};


