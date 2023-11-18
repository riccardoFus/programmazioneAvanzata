#ifndef CLASSE_A
#define CLASSE_A

#include <iostream>
using namespace std;
#include "b.h"

class A{
    int i;
    B* puntatore_b; // un puntatore ma in modo diverso all'aggregazione
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