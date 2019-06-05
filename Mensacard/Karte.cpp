#include <Karte.h>

Karte::Karte(){
	m_matNr = 1234567;
	m_vorname = "John";
	m_nachname = "Wick";
	m_konto = 50.00;
}

Karte::~Karte(){}

bool setValues(unsigned long matnr, string vorname, string nachname){
	if (matnr > 1700000 && matnr < 2999999){
		m_matNr = matnr;
		return true;
	}
	return false;
	m_vorname = vorname;
	m_nachname = nachname;
}
bool setKonto(double neukonto){
	m_konto = neukonto;
}
unsigned long Karte::getMatNr(){
	return m_matNr;
}
string Karte::getVorname(){
	return m_vorname;
}
string Karte::getNachname(){
	return m_nachname;
}
double Karte::getKonto(){
	return m_konto;
}
double Karte::getRestguthaben(double konto, double auszahlen){
	konto = konto - auszahlen;
	return konto;
}

