#include <cstdlib>
#include <iostream>

using namespace std;

#include "a.h"
#include "b.h"
int main(int argc, char ** argv){
	//test_A();
	//cout << endl << endl;
	//test_B();
	//cout << endl << endl;
	B* pb = new B(7, "note");
	cout << quadrato(*pb) << endl;
	delete pb;
	cout << endl << endl;
	A* pa = new A(11);
	cout << quadrato(*pa) << endl;
	delete pa;
	cout << endl << endl;
	
	pa = new B(13, "giorni");
	cout << quadrato(*pa) << endl;
	delete pa;
	cout << endl << endl;
	
	A a;
	B b;
	a = b;
	// b = a;
	A a2(b); // costruttore di copia
}
