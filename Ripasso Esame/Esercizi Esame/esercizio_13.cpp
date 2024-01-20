/*
    Crea un bitset di 64 bits poi:
        * inizializzalo con una stringa
        * stampalo
        * shiftalo a sinistra di 4 posizioni
        * interpretalo come un long long e stampa
        * resetta il bit 17
*/
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main(int argc, char ** argv){
    string init = "10101001010101010100100010010010100";
    bitset<64> b(init);
    cout << b << endl;
    b = b <<= 4;
    cout << b << endl;
    long long val = b.to_ullong();
    cout << val << endl;
    b.reset(17);
    cout << b << endl;
    b.flip();
    cout << b << endl;
}