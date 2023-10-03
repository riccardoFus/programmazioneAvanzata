#include <iostream>
using namespace std;

class Intero{
	private:
		int val;
	public:
		Intero(): val(0){
			cout << "Costruttore default" << endl;
		}
		Intero(int _val): val(_val){
			cout << "Costruttore ad un parametro" << endl;
		}
		~Intero(){
			cout << "Distruttore eseguito" << endl;
		}
		Intero operator % (const Intero& i) const{ 
			return Intero(this->val % i.val);
		}
		friend ostream& operator << (ostream& os, const Intero& i);
		// friend Intero operator % (const Intero& i1, const Intero& i2);
};

ostream& operator << (ostream& os, const Intero& i){
	os << "Valore intero: " << i.val;
	return os;
}
/*
Intero operator % (const Intero& i1, const Intero& i2){
	return Intero(i1.val % i2.val);
}
*/

int main(int argc, char ** argv){
	Intero a1(4), a2(3);
	cout << a1 << endl;
	cout << a2 << endl;
	cout << a1 % a2 << endl;
	return 0;
}
