#ifndef COMPLESSO
#define COMPLESSO

#include <iostream>
using namespace std;

class Complesso{
	double re, im;
	public:
		Complesso(double re = 0, double im = 0);
		// Complesso operator + (const Complesso & _c) const;
		// Complesso operator * (const Complesso & _c) const;
		Complesso& operator += (const Complesso & c);
		Complesso& operator *= (const Complesso & c);
		Complesso operator - () const;
		friend ostream& operator << (ostream& os, const Complesso& c);
		friend Complesso operator + (const Complesso& c1, const Complesso& c2);
		friend Complesso operator * (const Complesso& c1, const Complesso& c2);
		friend Complesso operator - (const Complesso& c1, const Complesso& c2);
};

ostream& operator << (ostream& os, const Complesso& c);
Complesso operator + (const Complesso& c1, const Complesso& c2);
Complesso operator * (const Complesso& c1, const Complesso& c2);
Complesso operator - (const Complesso& c1, const Complesso& c2);

void test_Complesso();

#endif
