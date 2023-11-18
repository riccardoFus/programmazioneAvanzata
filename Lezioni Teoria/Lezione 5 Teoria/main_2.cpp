#include <iostream>
#include <string>
#include <utility>
using namespace std;
class A{
	public:
		virtual A& operator = (const A& _a) = 0;
		virtual A* clone() const = 0;
		virtual ~A(){
		};
};

class B:public A{
	int i;
	public:
		B(int _i){
			i = _i;
		}
		B& operator = (const A& _b){
			A* temp = _b.clone();
			B b(*((B*)temp));
			*this = b;
			return *this;
		}
		B& operator = (const B& _b){
			i = _b.i;
			return *this;
		}
		B* clone() const{
			return new B(*this);
		}
		friend ostream& operator << (ostream& os, const B& _b);
};

ostream& operator << (ostream& os, const B& _b){
	return os << _b.i;
}

void my_swap(A &f, A &s){
	A* temp = f.clone();
	f = s;
	s = *temp;
	delete temp;
}

int main(){
	B x(33);
	B y(44);
	cout << x << " " << y << endl;
	my_swap(x,y);
	cout << x << " " << y << endl;
	return 0;
}
