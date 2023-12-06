#include <iostream>
using namespace std;

int main(int argc, char ** argv){
    int a = 99;
    // int &b = 99;
    int &&c = 99;
    int &pa = a;
    // int &&ppa = a; // a non è un valore temporaneo
    int &&ppa = a + c;
    cout << ppa << endl;
    ppa++;
    cout << ppa << endl;
    // int& pa1 = a + c; // no, sto prendendo un riferimento di lvalue
    const int& pa1 = a + c;
    cout << pa1 << endl;
    return 0;
}