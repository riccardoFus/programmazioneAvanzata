#include "a.h"

A::A(){
    i = 0;
    cout << "Costruttore a zero parametri" << endl;
}

A::A(int i){
    this->i = i;
    cout << "Costruttore a un parametro" << endl;
}

A::A(const A& a){
    i = a.i;
    cout << "Costruttore copia" << endl;
}

A::A(A&& a){
    i = a.i;
    a.i = 0;
    cout << "move costruttore" << endl;
}

A& A::operator= (const A& a){
    i = a.i;
    cout << "operator = " << endl;
    return *this;
}

A& A::operator= (A&& a){
    i = a.i;
    a.i = 0;
    cout << "move operator = " << endl;
    return *this;
}

A::~A(){
    cout << "Distruttore" << endl;
}

int A::get_i(){
    return i;
}