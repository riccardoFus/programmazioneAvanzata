#include "a.h"
#include <cstdlib>
#include <iostream>
#include <list>
#include "b.h"
using namespace std;

int main(int argc, char ** argv){
    A a8(8, "prova unique pointer 8");
    cout << a8.get_s() << endl;

    A a2;
    A a3(1, "prova1");
    cout << a3.get_i() << " " << a3.get_s() << endl;
    cout << a2.get_s() << endl;
    a3.set_s("cambiato");
    a2.set_s("amilcare");
    cout << a3.get_s() << endl;
    cout << a2.get_s() << endl;
    a3 = a2;
    cout << a3.get_s() << endl;

    a2.set_s("Alfredo");
    cout << a2.get_s() << endl;
    cout << a3.get_s() << endl;

    A a4(4, "Pinco");
    cout << a4.get_s() << endl;
    A a5(move(a4));
    cout << a5.get_s() << endl;
    cout << a4.get_s() << endl;

    A a6;
    a6 = move(a5);
    cout << a6.get_s() << endl;
    cout << a5.get_s() << endl;

    list<A> l;
    l.push_back(a6);
    A a7(move(l.front()));
    cout << a7.get_s() << endl;
    cout << "get wp : " << a7.get_wp() << endl;
}