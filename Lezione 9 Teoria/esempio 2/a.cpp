#include "a.h"

A::A(){
    i = 0;
    puntatore_b = NULL;
    cout << "Costruttore a zero parametri" << endl;
}

A::A(int i, string s){
    this->i = i;
    puntatore_b = new B(s);
    cout << "Costruttore a due parametri" << endl;
}

A::A(const A& a){
    i = a.i;
    if(a.puntatore_b != NULL){
        puntatore_b = new B(*(a.puntatore_b));
    }else{
        puntatore_b = NULL;
    }
    cout << "Costruttore di copia" << endl;
}

A::A(A&& a){
    puntatore_b = a.puntatore_b;
    i = a.i;
    a.puntatore_b = NULL;
    a.i = 0;
    cout << "move costruttore" << endl;
}

A& A::operator= (const A& a){
    i = a.i;
    if(this->puntatore_b == NULL){
        if(a.puntatore_b != NULL){
            puntatore_b = new B(*(a.puntatore_b));
        }
    }else{
        if(a.puntatore_b != NULL){
            (*puntatore_b) = *(a.puntatore_b);
        }else{
            delete puntatore_b;
            puntatore_b = NULL;
        }
    }
    cout << "operator =" << endl;
    return *this;
}

A& A::operator=(A&& a){
    i = a.i;
    if(this == &a){
        return *this;
    }
    if(puntatore_b != NULL){
        delete puntatore_b;
    }
    puntatore_b = a.puntatore_b;
    a.puntatore_b = NULL;
    a.i = 0;
    cout << "move operator =" << endl; 
    return *this;
}

A::~A(){
    if(puntatore_b != NULL){
        delete puntatore_b;
    }
    cout << "Distruttore" << endl;
}

int A::get_i(){
    return i;
}

string A::get_s(){
    if(puntatore_b != NULL){
        return puntatore_b->get_s();
    }else{
        return "puntatore_b == NULL true";
    }
}

void A::set_s(string s){
    if(puntatore_b == NULL){
        puntatore_b = new B(s);
    }else{
        (*puntatore_b) = B(s);
    }
}