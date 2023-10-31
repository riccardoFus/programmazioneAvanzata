#include <iostream>
#include <map>
using namespace std;

int f(int i, int j){
    return i*j;
}

double media(int i, int j, int (*pf) (int, int)){
    return double(pf(i,j))/2;
}

int f2(int i, int j){
    return i+j;
}

typedef double (*P) (double);

double f0(double x){
    return 1;
}

double f1(double x){
    return x;
}

double f2(double x){
    return x*x;
}

double f3(double x){
    return x*x*x;
}

int main(){
    int (*pf) (int, int);
    pf = f;
    cout << pf(2,3) << endl;
    cout << media(2,3,f) << endl;
    cout << media(2,3,f2) << endl;

    map<P, double> m;
    m[f1] = 2;
    m[f3] = 4;
    double somma = 0;
    map<P, double>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        somma += (it->first)(2.0) * (it->second);
    }
    cout << "prova map: " << somma << endl;
}