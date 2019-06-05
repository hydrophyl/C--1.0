/* Dies ist nun die cpp-Datei der Klasse.
 * Hier werden die Methodenruempfe der Klasse definiert.
 * Zusammen mit der h-Datei bildet die cpp-Datei die vollstaendige Beschreibung der Klasse.
 */

#include "stdafx.h"
/* Hier muss immer die h-Datei der Klasse eingebunden werden, damit man auf
 * die Attribute und Methoden zugreifen kann.
 * Wir werden spaeter sehen: wenn man die Klasse mit Hilfe der IDE angelegt,
 * wird diese include-Zeile immer automatisch eingefuegt.
 */
#include "Studi.h"

 /* Für die cpp-Dateien gilt grundsaetzlich:
 * den Methodennamen muss immer der Klassenname mit zwei Doppelpunkten vorangestellt
 * werden, hier also: Studi::
 * Auf diese Weise kann der Compiler die Mehtoden immer eindeutig erkennen.
 */

 /* Hier folgt nun der Methodenrumpf des Standard-Konstruktors
 */
Studi::Studi()
{
	m_matNr = 0;
	m_vorname = "";
	m_nachname = "";
	m_isMale = false;
	m_sFach = "";
	m_eMail = "";
}

/* Und hier kommt der zweite Konstuktor, mit dessen Hilfe das erzeugte Objekt
* immer gleich eine uebergebene Matrikelnummer zugewiesen bekommt, sowie weitere
* Attribute mit Werten versehen werden.
* Ob das hier sinnvoll ist, wird noch in der Bearbeitung geklaert und ggf. angepasst.
*/
Studi::Studi(unsigned long matnr)
{
	m_matNr = matnr;
	m_vorname = "Hans";
	m_nachname = "Raubein";
	m_isMale = true; // das sollte dann schon richtig sein, also angepasst auf true
	m_sFach = "";
	m_eMail = "";
}

/* Hier folgt nun der Methodenrumpf des Standard-Destruktors.
* Der Destruktor ist eine Methode, die heisst wie die Klasse, jedoch mit einer Tilde
* vorangestellt. Sie gibt (wie die Konstruktoren auch) keinerlei Wert zurueck (auch nicht void)
* und hat eine leere Parameterliste.
* Den Methodenrumpf lassen wir bis auf weiteres auch einfach leer so wie er ist.
* Auch dieser Teil wird spaeter automatisch erzeugt und von uns zunaechst
* nicht veraendert. Aber er wird gebraucht.
*/
Studi::~Studi()
{
}

/* Hier definieren wir nun die Methodenruempfe der set- und get-Methoden.
*
* Wichtig ist hier immer:
* Wenn man eine Methode definiert, beginnt der Nanem hier immer mit
* Klassenname:: - hier also Studi::
* dann weiss der Compiler, dass hier die Methode aus dieser Klasse gemeint ist,
* die in der entsprechenden h-Datei als Prototyp deklariert wurde.
*/
bool Studi::setMatNr(unsigned long matnr)
{
	if (matnr > 1700000 && matnr < 2999999)
	{
		m_matNr = matnr;
		return true;
	}
	return false;
}

void Studi::setVorname(string vorname)
{
	m_vorname = vorname;
}

void Studi::setNachname(string nachname)
{
	m_nachname = nachname;
}

void Studi::setIsMale(char geschl)
{
	if (geschl == 'm')
	{
		m_isMale = true;
	}
	else
	{
		m_isMale = false;
	}
}

void Studi::setsFach(string sFach)
{
	m_sFach = sFach;
}

void Studi::setEmail(string eMail)
{
	m_eMail = eMail;
}



unsigned long Studi::getMatNr()
{
	return m_matNr;
}

string Studi::getVorname()
{
	return m_vorname;
}

string Studi::getNachname()
{
	return m_nachname;
}

bool Studi::getIsMale()
{
	return m_isMale;
}

string Studi::getSFach()
{
	return m_sFach;
}

string Studi::getEmail()
{
	return m_eMail;
}
