#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //definitions
    const int MAX = 200;
    unsigned int count;
    ifstream data1;
    double x[MAX];
    double y[MAX];
    string s,v;
    //read data
    data1.open("DatenEinlesen1.txt");
    data1 >> s >> v; 
    /* for(int i = 0; i < MAX; i++)
    {
        data1 >> x[i] >> y[i];
    } */

    //properly working
    int i = 0;
    while(data1.good()){
        data1 >> x[i] >> y[i];
        i++;
    }
    count = i;

    data1.close();
    for(int i = 0; i < count; i++)
    {
        cout << x[i] << "\t \t" << y[i] << "\n";
    }

    return 0;
}
