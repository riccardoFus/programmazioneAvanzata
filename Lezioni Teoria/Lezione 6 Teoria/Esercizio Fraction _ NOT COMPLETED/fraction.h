#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <set>
#include <math.h>
using namespace std;

class Fraction{
    multiset<unsigned int> num, den;
    bool zero;
    public:
        Fraction();
        Fraction set_zero();
        void mul(unsigned int _i);
        void div(unsigned int _i);
        Fraction& operator *= (const Fraction& _f);
        friend ostream& operator << (ostream& os, const Fraction& _f);
        long double compute();
        long double compute2();
        Fraction simplify_as_factorial();
        Fraction simplify_with_primes();
        bool is_zero();
};

ostream& operator << (ostream& os, const Fraction& _f);
unsigned long long int fact(unsigned int _i);
multiset<unsigned int> primeFactors(int n);
Fraction hg(unsigned int _x, unsigned int _r, unsigned int _n, unsigned int _N);

#endif