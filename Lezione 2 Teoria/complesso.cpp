#include "complesso.h"
#include <iostream>

Complesso::Complesso(double _re, double _im){
	re = _re;
	im = _im;
}

/*
Complesso Complesso::operator + (const Complesso& _c) const{
	return Complesso(re + _c.re, im + _c.im);
}


Complesso Complesso::operator * (const Complesso& _c) const{
	return Complesso(re*_c.re - im * _c.im, re*_c.re + _c.re*im);
}
*/
Complesso& Complesso::operator +=(const Complesso& c){
	re += c.re;
	im += c.im;
	return *this;
}

Complesso& Complesso::operator *=(const Complesso& c){
	(*this) = (*this) * c;
	return *this;
}

Complesso Complesso::operator - () const{
	return Complesso(-re, -im);
} 

Complesso operator - (const Complesso& c1, const Complesso& c2){
	return c1 + (-c2);
}

Complesso operator + (const Complesso& c1, const Complesso& c2){
	return Complesso(c1.re + c2.re, c1.im + c2.im);
}

Complesso operator * (const Complesso& c1, const Complesso& c2){
	return Complesso(c1.re*c2.re - c1.im*c2.im, c1.re*c2.im + c2.re*c1.im);
}

ostream& operator << (ostream& os, const Complesso& c){
	os << c.re << " + " << c.im << "i ";
	return os;
}

void test_Complesso(){
	Complesso c3;
	cout << c3 << endl; // 0 + 0i
	cout << Complesso(3,2) << endl; // 3 + 2i
	cout << Complesso(3,2) + Complesso(2,3) << endl; // 5 + 5i
	cout << Complesso(3,2) * Complesso(2,3) << endl; // 0 + 13i
	Complesso c(3,2); 
	cout << c + 1 << endl; // 4 + 2i
	Complesso c1;
	cout << 1 + c << endl; // 4 + 2i
	cout << -c << endl; // -4 + -2i
}
