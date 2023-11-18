#include <cstdlib>
#include <iostream>
#include <list>
#include "a.h"
using namespace std;

int main(){
    A a, a1(1);
    a = a1;

    cout << a.get_i() << endl;
    cout << a1.get_i() << endl;

    a = move(a1);
    cout << a.get_i() << endl;
    cout << a1.get_i() << endl;

    A a2(a);
    cout << a2.get_i() << endl;
    cout << a.get_i() << endl;

    A a3(move(a));
    cout << a3.get_i() << endl;
    cout << a.get_i() << endl;

    return 0;
}