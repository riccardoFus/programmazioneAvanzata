#include <cstdlib>
#include <iostream>

using namespace std;

#include "a.h"
#include "b.h"
int main(int argc, char ** argv){
	test_A();
	cout << endl << endl;
	test_B();
	cout << endl << endl;
	B* pb = new B(7, "note"); // B::B(int, string)&pb
	cout << quadrato(*pb) << endl; // 49
	delete pb; // B::~B()&pb
	cout << endl << endl; 
	A* pa = new A(11); // A::A(int)&pa
	cout << quadrato(*pa) << endl; // 121
	delete pa; //A::~A()&pa
	cout << endl << endl;
	
	pa = new B(13, "giorni");  // A::A(int), B::B(int, string)
	cout << quadrato(*pa) << endl; // 169
	delete pa; // B::~B(), A::~A()
	cout << endl << endl;
	
	A a; // A::A()
	B b; // A::A()
	a = b; // B::B()
	// b = a;
	A a2(b); // costruttore di copia  A::A(const A& a)
}
