#include <iostream>
#include <math.h>
#include <map>
using namespace std;

class A{
    int i;
    public:
        A(){
            i = 1;
        }
        A(int i){
            this->i = i;
        }
        double operator () (double d) const{
            return pow(d, i);
        }
        bool operator < (const A& a) const{
            return i < a.i;
        }
};

void test_A(){
    A a(3);
    cout << a(2.0) << endl;
    A a1;
    cout << a1(3) << endl;
}

int main(){
    test_A();

    map<A, double> ma;
    ma[A(1)] = 2;
    ma[A(3)] = 4;
    int somma = 0;
    map<A, double>::const_iterator itma;
    for(itma = ma.begin(); itma != ma.end(); itma++){
        somma += (itma->first)(2.0) * (itma->second);
    }
    cout << "prova map: " << somma << endl;
    return 0;
}