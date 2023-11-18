#include "b.h"

B::B(string s):p(new int(0)){
    this->s = s;
    cout << "*p="<<*p<<endl;
}

string B::get_s(){
    (*p)++;
    cout << "*p="<<*p<<endl;
    return s;
}

int B::get_p(){
    return *p;
}

B::~B(){
    cout << "B distructor: p use count : " << p.use_count() << endl;
}

shared_ptr<int> B::get_pointer(){
    return p;
}