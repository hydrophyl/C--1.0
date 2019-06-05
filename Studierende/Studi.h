/* Dies hier ist die h-Datei der Klasse Studi.
* In der h-Datei einer Klasse werden die Attribute definiert (aber nicht initialisiert)
* und die Prototypen der Methoden angegeben.
* Die Entscheidung ob die Elemente jeweils private oder public sind,
* wird dabei hier in der h-Datei getroffen.
* Unter public: definierte Attribute oder Methoden können von außerhalb der
* Klasse, also z.B. dem main()-Programmm aus aufgerufen und genutzt werden.
* Unter private: definierte Attribute oder Methoden können nur innerhalb der
* Klasse und ihrer Objekte genutzt werden.
* Faustregel:
* Attribute (= Variablen der Klasse) sind private
* Methoden (= Funktionen der Klasse): set- und get-Methoden immer public.
* Für alle weiteren Methoden: es kommt darauf an, wie sie genutzt werden sollen...
*/

/* Hinweis:
* Die folgende Praeprozessor-Direktive sollte immer die erste ausfuehrbare Zeile in
* einer h-Datei einer Klasse sein.
* Warum und was diese bewirkt, besprechen wir spaeter in der Vorlesung.
* Diese Zeile wird automatisch von der IDE eingefuegt. Wir aendern sie nicht.
*/
#pragma once 

/* Da wir Vorname und Nachname verwalten moechten, brauchen wir die Bibliothek <string>
* und muessen auch den namespace std angeben, damit "string" als Schluesselwort erkannt wird.
* string ist damit für uns einfach ein neuer Datentyp, der es erlaubt Zeichenketten zu speichern.
*/
#include <string>
using namespace std;

// hier beginnt die Klassendefinition
class Studi
{
/* Alles was hier hinter "private:" angegeben wird, egal ob Attribute oder Methoden,
* ist nur fuer die Klasse selbst sichtbar und nutzbar.
* Von der main()-Funktion aus hat man keinen Zugriff darauf.
*/
private:
/* Hinweis::
* Die Attribute werden hier grundsaetzlich nur definiert, aber nicht initialisiert.
* Die Zueisung der Initialwerte erfolgt ueber die Konstruktoren (= Methoden, die keinen
* Rückgabewert haben und heissen wie die Klasse selbst) und steht damit dann
* im Methodenrumpf des Konstruktors in der cpp-Datei der Klasse.
*/
	unsigned long m_matNr;
	string m_vorname;
	string m_nachname;
	bool m_isMale;
	string m_sFach;
	string m_eMail;

/* Alles was hier hinter "public:" angegeben wird, egal ob Attribute oder Methoden,
* ist auch ausserhalb der Klasse ansprechbar und kann aufgerufen werden, so auch von
* der main()-Funktion aus.
*/
public:
/* Hier folgen standardmaessig die Konstruktoren, deren haben wir zwei.
* Einen sogenannten Standard-Konstruktor gibt es immer: es heisst wie die Klasse,
* hat eine leere Parameterliste und gibt (wie alle Konstruktoren) nichts zurück, auch
* nicht void. Hier ist es also die Methode: Studi()
*/
	Studi();
	Studi(unsigned long matnr);

/* Und hier die Destruktoren. Ueber diese sprechen wir dann wieder spaeter.
* Davon kann es immer nur einen geben und wir aendern hier nichts.
*/
	~Studi();

/* Jetzt werden die weiteren Methoden deklariert.
* Hier in der h-Datei stehen immer nur die Prototypen, also die Methoden-Koepfe
* ohne den Methodenrumpf, der wird immer in der zugehörigen cpp-Datei der Klasse definiert.
*
* Hinweis:
* Die Methoden-Namen stehen hier ohne den vorangestellten Klassennamen,
* der in der cpp-Datei immer dazugehoert (siehe Text dort).
*/
	bool setMatNr(unsigned long matnr);
	void setVorname(string vorname);
	void setNachname(string nachname);
	void setIsMale(char geschl);
	void setsFach(string sFach);
	void setEmail(string eMail);

	unsigned long getMatNr(void);
	string getVorname(void);
	string getNachname(void);
	bool getIsMale(void);
	string getSFach(void);
	string getEmail(void);
};
