// Der Praeprozessor bearbeitet die PRogrammdatei, bevor der Compiler sie zu lesen bekommt. - Textdatei lesen/wiedergeben.
// wird durch eine Direktiven # gesteuert.

// <Datei> wird in Standardverzeichnissen gesucht
// "Datei" wird zuerst im Verzeichnis der Programmdatei gesucht
#include <iostream>     // Ein-/Ausgabesstrom Code bereistellen
using namespace std;    // notwendig, mehr dazu spaeter....

// void: nichts
// main: Standard Einstiegspunkt
// {} Rumpf der Funktion
int main(){ 
    cout << "Size of Bool: " << sizeof(bool) << " Bytes!" << endl;    // Rueckgabewert (muss zum Typ der main-function pass)
    cout << "Int-min= " << INT8_MIN << " Bytes" << endl;
    return 0;
}