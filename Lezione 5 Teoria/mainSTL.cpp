#include <iostream>
#include <list>
using namespace std;

class A{
	int i;
	public:
		A(int _i){
			i = _i;
		}
		void stampa(){
			cout << i;
		}
		friend ostream& operator << (ostream& os, const A& _a);
		bool operator < (const A& _a) const {
			return (i < _a.i);
		}
};

ostream& operator << (ostream& os, const A& _a){
	return os << _a.i;
}

class B{
	// A *pa;  voglio AGGREGGARE un solo A
	// list<A> la; questo va bene per la composizione, non per l'aggregazione
	list<A*> lpa;
	public:
		B(A& _a){
			add(_a);
		}
		void add(A& _a){
			lpa.push_front(&_a);
		}
		void stampa() const {
			list<A*>::const_iterator it;
			for(it = lpa.begin(); it != lpa.end(); it++){
				(*it)->stampa();
				cout << endl;
			}
		}
};

void test_B(){
	A a1(5), a2(7);
	B b(a1);
	b.add(a1);
	b.add(a2);
	b.stampa();
}

int main(int argc, char** argv) {
	test_B();
	return 0;
}
