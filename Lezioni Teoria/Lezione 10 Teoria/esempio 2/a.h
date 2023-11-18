#ifndef CLASSE_A
#define CLASSE_A
#include <iostream>
#include <memory>
using namespace std;
#include "b.h"

class A{
    int i;
    unique_ptr<B> unique_pointer_b;
    public:
        A();
        A(int i, string s);
        A(const A& a);
        A(A&& a);
        A& operator = (const A& a);
        A& operator = (A&& a);
        ~A();
        int get_i();
        string get_s();
        void set_s(string s);
};

#endif