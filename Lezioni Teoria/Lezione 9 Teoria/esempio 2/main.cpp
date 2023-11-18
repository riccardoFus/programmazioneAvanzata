#include <cstdlib>
#include <iostream>
#include <list>
#include "a.h"
#include "b.h"
using namespace std;

int main(int argc, char ** argv){
    A a;
    cout << a.get_i() << endl;

    A a1;
    cout << a1.get_i() << endl;

    a1 = a;
    cout << a1.get_i() << endl;

    A a2(a);
    cout << a2.get_i() << endl;

    A* puntatore_a = new A(a);
    cout << puntatore_a->get_i() << endl;
    delete puntatore_a;

    B b("prova");
    cout << b.get_s() << endl;

    A a3(1, "prova1");
    cout << a3.get_i() << " " << a3.get_s() << endl;
    cout << a2.get_s() << endl;

    a3.set_s("Cambiato");
    a2.set_s("Amilcare");
    cout << a3.get_s() << endl;
    cout << a2.get_s() << endl;

    a3 = a2;
    cout << a3.get_s() << endl;
    
    a2.set_s("Alfredo");
    cout << endl;
    cout << a2.get_s() << endl;
    cout << a3.get_s() << endl;

    cout << endl;
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
    cout << l.size() << endl;
    return 0;
}