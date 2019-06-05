#include <iostream>
#include <string>
#include "figure.h"

using namespace std;

int main(){
	string name = " " ;
	double height = 0;
	double width = 0;
	double area = 0;

	Figure fig;
	cout << "Name of figure: ";
	cin >> name;
	cout << "Height: ";
	cin >> height;
	cout << "Width: ";
	cin >> width;

	fig.setValues(name,height,width);
	cout << "\n" << "Information of figure"
		<< "Name: " << fig.getName() << "\n"
		<< "Height: " << fig.getHeight() << "\n"
		<< "Width: " << fig.getWidth() << "\n"
		<<  "Area: " << fig.getHeight() * fig.getWidth() << endl;
	return 0;
}
