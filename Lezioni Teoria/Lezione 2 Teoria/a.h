#ifndef CLASSE_A
#define CLASSE_A
#include <iostream>
#include <string>
#include "b.h"

using namespace std;

// intendo realizzare una composizione facoltativa 0,1

class A{
	int i;
	// un puntatore ma in modo diverso rispetto all'aggregazione
	B* pb;
	public:
		A();
		A(int i, string _s);
		A(const A& a);
		// a = ( b = c )
		A& operator = (const A& _a);
		~A();
		int get_i();
		string get_s();
		void set_s(string _s);
};

#endif
