#ifndef CLASSE_A
#define CLASSE_A

#include <iostream>
#include <string>
using namespace std;

class A{
	int i;
	public:
		A();
		explicit A(int _i);
		A(const A& a);
		virtual ~A();
		int get_i();
};

void test_A();
int quadrato(A& a);
int raddoppia(A a);

#endif
