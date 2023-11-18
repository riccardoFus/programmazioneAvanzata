#include "a.h"

A::A(){
    i = 0;
    cout << "Costruttore a zero parametri" << endl;
}

A::A(int i, string s){
    this->i = i;
    this->unique_pointer_b.reset(new B(s));
    cout << "Costruttore a due parametri" << endl;
}

A::A(const A& a){
    i = a.i;
    if(a.unique_pointer_b) unique_pointer_b.reset(new B(*(a.unique_pointer_b)));
    cout << "Costruttore di copia" << endl;
}

A::A(A&& a){
    unique_pointer_b = move(a.unique_pointer_b);
    i = a.i;
    a.i = 0;
    cout << "Move costruttore" << endl;
}

A& A::operator=(const A& a){
    i = a.i;
    if(!unique_pointer_b){
        if(a.unique_pointer_b) unique_pointer_b.reset(new B(*(a.unique_pointer_b)));
    }else{
        if(a.unique_pointer_b) (*unique_pointer_b) = *(a.unique_pointer_b);
        else unique_pointer_b.reset(NULL);
    }
    cout << "operator = " << endl;
    return *this;
}

A& A::operator=(A&& a){
    i = a.i;
    a.i = 0;
    unique_pointer_b = move(a.unique_pointer_b);
    cout << "move operator = " << endl;
    return *this;
}

A::~A(){
    if(unique_pointer_b) unique_pointer_b.reset(NULL);
    cout << "Distruttore " << endl;
}

int A::get_i(){
    return i;
}

string A::get_s(){
    if(unique_pointer_b) return unique_pointer_b->get_s();
    else return "";
}

void A::set_s(string s){
    if(!unique_pointer_b) unique_pointer_b.reset(new B(s));
    else (*unique_pointer_b) = B(s);
}