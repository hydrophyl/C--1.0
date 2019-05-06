#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    unsigned int iWert;
    unsigned int anzahl = 0;
    float summe = 0;
    unsigned int min = 1000;
    unsigned int max = 0;
    unsigned int gerade = 0;
    unsigned int ungerade = 0;
    double mittelwert;

    cout << fixed << setprecision(2); 

    ifstream LeseDatei ("Zufallszahlen.csv");
    while(LeseDatei.good()){
        /* code */
        LeseDatei >> iWert;
        anzahl++;
        summe = summe + iWert;
        min = (iWert < min) ? iWert : min;
        max = (iWert > max) ? iWert : max;
        gerade = (iWert % 2 == 0) ? (gerade + 1) : gerade;
        ungerade = (iWert % 2 == 1) ? (ungerade+1) : ungerade;
    }
    LeseDatei.close();

    mittelwert = summe / anzahl;
    
    ofstream Antwort;
    Antwort.open("Ergebnis_zu_Zufallszahlen.csv");

    Antwort << "Anzahl der Werte in Datei: " << anzahl << endl 
         << "Summe der Werte: " << summe << endl
         << "Kleinsten Wert: " << min << endl
         << "Groessten Wert: " << max << endl
         << "Anzahl gerader Zahlen: " << gerade << endl
         << "Anzahl ungerader Zahlen: " << ungerade << endl
         << "Mittelwert: " << mittelwert << endl;
        Antwort.close();
    return 0;
}