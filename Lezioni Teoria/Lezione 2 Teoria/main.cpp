#include <cstdlib>
#include <iostream>
#include "a.h"
#include "b.h"

using namespace std;

int main(int argc, char ** argv){
	// cosa posso fare con la classe vuota?
	A a; // costruttore a zero param
	cout << a.get_i() << endl; // 0
	A a1; // costruttore a zero param
	cout << a1.get_i() << endl; // 0
	a1 = a; // operator =
	cout << a1.get_i() << endl; // 0
	A a2(a); // costruttore di copia
	cout << a2.get_i() << endl; // 0
	A* pa = new A(a); // costruttore di copia
	cout << pa->get_i() << endl; // 0
	delete pa; // distruttore di pa
	
	B b("prova"); // costruttore a un param
	cout << b.get_s() << endl; // prova
	
	A a3(1, "prova1"); // costruttore a due param
	cout << a3.get_i() << " " << a3.get_s() << endl; // 1 prova1
	
	a3.set_s("Cambiato"); 
	a2.set_s("Amilcare");
	
	cout << a3.get_s() << endl; // cambiato
	cout << a2.get_s() << endl; // amilcare
	
	a3 = a2; // a3 diventa amilcare
	
	cout << a3.get_s() << endl; // amilcare
	a2.set_s("Alfredo");
	
	cout << endl;
	cout << a2.get_s() << endl; // alfredo
	cout << a3.get_s() << endl; // amilcare
	
	return 0;
}
