#ifndef CLASSE_B
#define CLASSE_B
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class B{
    string s;
    shared_ptr<int> p;
    public:
        B(string s);
        string get_s();
        int get_p();
        shared_ptr<int> get_pointer();
        ~B();
};

#endif