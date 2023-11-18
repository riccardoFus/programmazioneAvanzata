#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include<iostream>
#include<set>
#include<math.h>
using namespace std;

class fraction{
    multiset<unsigned int> num,den;
    bool zero;
public:
    fraction() {zero=false;}
    fraction set_zero(){zero=true;num.clear();den.clear();return *this;}
    void mul(unsigned int _i);
    void div(unsigned int _i);
    fraction& operator*=(const fraction& _f);
friend ostream& operator<<(ostream& os,const fraction& _f);
long double compute();
long double compute2();//versione forse più precisa
fraction simplify_as_factorial();
fraction simplify_with_primes();
bool is_zero()const{return zero;};
   };

ostream& operator<<(ostream& os,const fraction& _f);
unsigned long long int fact(unsigned int _i);
multiset<unsigned int> primeFactors(int n);
fraction hg(unsigned int _x, unsigned int _r, unsigned int _n, unsigned int _N);// following wu's notation
fraction coeff_binom(unsigned int n, unsigned int k); //following wikipedia's notation
void test_fraction();
#endif // FRACTION_H_INCLUDED
