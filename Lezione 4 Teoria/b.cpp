#include "b.h"

B::B(){
	s = "";
	cout << "B::B()" << this << endl;
}

B::B(int _i, string _s):A(_i){
	s = _s;
	cout << "B::B(int, string)" << this << endl;
}

B::~B(){
	cout << "B::~B()" << this << endl;
}

string B::get_s(){
	return s;
}

void test_B(){
	B b; // A::A(), B::B()
	cout << b.get_s() << " " << b.get_i() << endl; // 0
	B b2(3, "Moli"); // A::A(int), B::B(int, string)
	cout << b2.get_s() << " " << b2.get_i() << endl; // Moli 3
	cout << quadrato(b2) << endl; // 9
	cout << raddoppia(b2) << endl; // 6
}
