#include <iostream>
#include <cstdlib>
#include "complesso.h"
using namespace std;

class A{
	int i;
	public:
		A(int _i){
			i = _i;
		}
		A operator + (const A&);
		int get_i() const{
			return i;
		}
		A& operator ++(); // prefisso
		A operator ++(int); // postfisso
};

class B{
	int x;
	public:
		B(int _x){
			x = _x;
		}
		int get_x() const{
			return x;
		}
		friend B operator +  (const B&, const B&); // operator + non è più un metodo
};

A A::operator +(const A& _a){
	return A(i + _a.i);
}

A& A::operator ++(){
	++i;
	return *this;
}

A A::operator ++(int){
	A temp(*this);
	i++;
	return temp;
}

B operator + (const B& b1, const B& b2){
	return B(b1.get_x() + b2.get_x());
}

int main(int argc, char** argv) {
	A a1(1), a2(2), a3(3);
	cout << "a1 : " << a1.get_i() << endl;
	cout << "a2 : " << a2.get_i() << endl;
	cout << "a3 : " << a3.get_i() << endl << endl;
	a1 = a2 + a3;
	cout << "a1 : " << a1.get_i() << endl;
	cout << "a2 : " << a2.get_i() << endl;
	cout << "a3 : " << a3.get_i() << endl << endl;
	// a1 = 2 + a3; ERRORE 
	a1 = a2 + 3; // compila -> conversione implicita di 3 (a1.operator = (a2.operator(A(3))) != (a1.operator = (2.operator(a3))
	cout << "a1 : " << a1.get_i() << endl;
	cout << "a2 : " << a2.get_i() << endl;
	cout << "a3 : " << a3.get_i() << endl << endl;
	B b1(1), b2(2), b3(3);
	cout << "b1 : " << b1.get_x() << endl;
	cout << "b2 : " << b2.get_x() << endl;
	cout << "b3 : " << b3.get_x() << endl << endl;
	b1 = b2 + b3;
	cout << "b1 : " << b1.get_x() << endl;
	cout << "b2 : " << b2.get_x() << endl;
	cout << "b3 : " << b3.get_x() << endl << endl;
	b1 = 2 + b3; // compila in entrambi i casi -> b1.operator + (operator + (B(2), b3)) = b1.operator + (operator + (b2, B(3)))
	cout << "b1 : " << b1.get_x() << endl;
	cout << "b2 : " << b2.get_x() << endl;
	cout << "b3 : " << b3.get_x() << endl << endl;
	b1 = b2 + 3;
	cout << "b1 : " << b1.get_x() << endl;
	cout << "b2 : " << b2.get_x() << endl;
	cout << "b3 : " << b3.get_x() << endl << endl;
	++a1;
	cout << "a1 : " << a1.get_i() << endl << endl;
	(a1++)++; // esce 7 perché il postfisso restituisce il valore vecchio -> 6 -> 6 -> 7
	cout << "a1 : " << a1.get_i() << endl << endl;
	cout << "Testiamo i complessi" << endl << endl;
	test_Complesso();
}
