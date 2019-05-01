#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	unsigned int i = 0;
	float attack, defense, HP, Lvl;
	bool justdoit = false;

	cout << fixed;
	cout << setprecision(5);
	cout << "Level of Bulbasur is: ";
	cin >> Lvl;
	attack = Lvl*10. + 50.;
	defense = attack/10.;
	HP = Lvl*100. + defense;
	do{
		cout << left << setw(15) << "Pokemon";
		cout << left << setw(15) << "Level";
		cout << left << setw(15) << "HP";
		cout << left << setw(15) << "Attack";
		cout << left << setw(15) << "Defense";
		cout << "\n" << endl;

		cout << left << setw(15) << "Bulbasur";
		cout << left << setw(15) << Lvl;
		cout << left << setw(15) << HP;
		cout << left << setw(15) << attack;
		cout << left << setw(15) << defense;
		cout << "\n" << endl;

		cout << endl << endl;
		i++;
		justdoit = (i < 5) ? false:true;
	}
	while(!justdoit);
	return 0;
}
