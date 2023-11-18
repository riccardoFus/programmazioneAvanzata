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
	A a; // A::A()
	cout << a.get_i() << endl; // 0
	A a3(3); // A::A(int)
	cout << a3.get_i() << endl; // 3
	cout << quadrato(a3) << endl; // 9
	cout << raddoppia(a3) << endl; // 6
}

int quadrato(A& a){
	int result = a.get_i();
	result *= a.get_i();
	return result;
}

int raddoppia(A a){
	return a.get_i()*2;
}
