#include <iostream>
using namespace std;

// va definito prima per far capire ad A chi è B
class B;
class A{
	private:
		int val;
	public:
		A(){
			val = 1;
		}
		/*
		bool operator == (const A& a) const{
			return val == a.val;
		}
		// != potrebbe coinvolgere attributi diversi di ==, se coinvolge gli stessi attributi, possiamo usare il prec
		bool operator != (const A& a) const{
			// return val != a.val;
			return !(a == *this);
			// se non va in questo modo -> !(*this == a), questo viene gestito sempre!!!
		}
		*/
		/*
		bool operator == (const B& b) const{
			// non sa come è fatto b
			return val == b.val;
		}
		NON SI PUO FARE
		*/
		bool operator == (const B& b) const;
		friend bool operator == (const A& a1, const A& a2);
		// che cavolo è B?
		friend bool operator == (const B& b, const A& a);
};

class B{
	private:
		int val;
	public:
		B(){
			val = 2;
		}
		friend bool operator == (const B& b, const A& a);
		friend A;
};

// E' ESTREMAMENTE CONVENIENTE DICHIARARE METODO ESTERNO PER CONFRONTARE DUE ISTANZE DI CLASSE !=

bool operator == (const A& a1, const A& a2){
	return a1.val == a2.val;
}

bool operator != (const A& a1, const A& a2){
	return !(a1 == a2);
}

bool operator == (const B& b, const A& a){
	return b.val == a.val;
}

bool A::operator == (const B& b) const{
			// non sa come è fatto b
			return val == b.val;
		}

int main(int argc, char ** argv){
	A a1, a2;
	B b1, b2;
	if(a1 == a2){
		cout << "Istanze di A uguali" << endl << endl;
	}else{
		cout << "Istanze di A non uguali" << endl << endl;
	}
	if(a1 != a2){
		cout << "Istanze di A non uguali" << endl << endl;
	}else{
		cout << "Istanze di A uguali" << endl << endl;
	}
	if(b1 == a1){
		cout << "Istanze di B e A uguali" << endl << endl;
	}
	if(a1 == b1){
		cout << "Istanze di A e B uguali" << endl << endl;
	}
	
	
	return 0;
}
