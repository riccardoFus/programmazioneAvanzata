#include <iostream>
#include "my_array.h"
using namespace std;

int main(int argc, char ** argv){
    My_array<double> a;
    My_array<int> a2(10);

    cout << a2[4] << endl;
    // non sto cambiando l'istanza, sto cambiando quello che punta 'a'
    // ecco perché const funziona comunque
    a2[4] = 99;
    cout << a2[4] << endl;
    a2[9] = 1;
    cout << a2[33] << endl;

    cout << a << endl;
    cout << a2 << endl;
    return 0;
}