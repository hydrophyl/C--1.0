#include <iostream>
using namespace std;

// Variables here are constantly stay in Memory (not just in main-function)
// moeglichst nicht
int n;

int main(int argc, char const *argv[])
{
    //Typ   Name = Wert;
    //Datentyp -> Speicherplatz, Rechnen. * Definition
    //Name Schluesselwort
    //Wert Konstante * Initialisierung
    // Variables here are saved just in main-function 
    int a = 1;
    int b(10);
    cout << a << endl 
        << b << endl;
    // char-number ist in ASCII definiert. 
    char z = char(120);
    cout << "Char nummer 120 is: " << z << endl;
    // aktuelle char or kleine String wird durch 'char' die nummer wiedergegeben.
    // cout << "x ist: " << 'C++' << endl; // NOT WORKING
    return 0;
}
