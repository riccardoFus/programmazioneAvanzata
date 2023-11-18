#ifndef CLASSE_A
#define CLASSE_A
#include <iostream>
using namespace std;

class A{
    int i;
    public:
        A();
        A(int i);
        A(const A& a);
        A(A&& a);
        A& operator = (const A& a);
        A& operator = (A&& a);
        ~A();
        int get_i();
};

#endif