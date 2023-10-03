#include "a.h"
A::A(){
	i = 0;
	cout << "A::A()" << this << endl;
}

A::A(int _i){
	i = _i;
	cout << "A::A(int)" << this << endl;
}

A::A(const A& a){
	i = a.i;
	cout << "A::A(const A&)" << this << endl;
}

A::~A(){
	cout << "A::~A()" << this << endl;
}

int A::get_i(){
	return i;
}

void test_A(){
	A a;
	cout << a.get_i() << endl;
	A a3(3);
	cout << a3.get_i() << endl;
	cout << quadrato(a3) << endl;
	cout << raddoppia(a3) << endl;
}

int quadrato(A& a){
	int result = a.get_i();
	result *= a.get_i();
	return result;
}

int raddoppia(A a){
	return a.get_i()*2;
}
