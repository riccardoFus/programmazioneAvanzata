#ifndef CLASSE_B
#define CLASSE_B

#include <iostream>
#include <string>
using namespace std;

#include "a.h"

class B: public A{
	string s;
	public:
		B();
		B(int _i, string _s);
		~B();
		string get_s();
};

void test_B();

#endif
