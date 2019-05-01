#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (true)
    {
        cout << "Zahl N: ";
        cin >> n;
        if (n > 10000)
        {
            cout << "N ist zu gross, lauft das Programm bitte erneut!" << endl;
        }
        else
        {
            break;
        }
    }
    cout << "N ist: " << n << endl;
    double fakultat = 1;
    double summe = 0;
    double N = 1;
    double e = 1;
    double prozent;
    for (int i = 1; i <= n; i++)
    {
        fakultat = fakultat * i;
        N = 1 / fakultat;
        e = e + N;
        prozent = ((e - M_E) / M_E) * 100;
        cout << "Fakultat: " << fixed << setprecision(2) << fakultat << "\t\t\t"
             << "N: " << N << "\t\t\t"
             << "e ist von M_E " << prozent << "\% abgeweichert!"
             << "\t\t\t"
             << "e ist: " << e << endl;
    }
    cout << endl
         << "e: " << fixed << setprecision(10) << e << endl;
	system("pause");
    return 0;
}
