#include <iostream>
using namespace std;

// const, static, static const
class A{
	private:
		int dato;
	public:
		A(int d){
			cout << "Costruttore specifico chiamato di: " << d << endl;
			dato = d;
		}
		A(const A& a){
			cout << "Costruttore copia chiamato di: " << a.dato << endl;
			dato = a.dato;
		}
		~A(){
			cout << "Distruttore chiamato di: " << dato << endl;
		}
		friend ostream& operator << (ostream& os, const A& a);
};

ostream& operator << (ostream& os, const A& a){
	// MAI METTERE L'END OF LINE QUI
	return os << " " << a.dato;
}

int main(int argc, char** argv) {
	A a(3);
	cout << "Parametro a: " << a << endl;
	return 0;
}
