#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Dies ist ein text \nUeber 2 Zeilen!" << endl //new line
         << "Spalte 1\tSpalte 2\n100" << "\t\t" <<200 << endl // tab
         << "Text1\fnach Seitenvorschub weiter!" << endl 
         << "Hier kommt ein \"Text\" in Anfuerungszeichen" << endl
         << "Maus \b\b\b\b\bH ist ein Text!" << endl; //backspace
    return 0;
}
