#include <iostream>
using namespace std;

class A{
	private:
		int dato;
		/*const*/int miaCostante; // rimuovo const per evitare rotture
	public:
		A(): dato(0), miaCostante(3){
			cout << "Costruttore di default" << endl << endl;
		}
		// evito conversioni implicite
		explicit A(int d): dato(d), miaCostante(9){
			cout << "Costruttore specifico con un parametro" << endl << endl;
		}
		A(int d, int c): dato(d), miaCostante(c){
			cout << "Costruttore specifico con due parametri" << endl << endl;
		}
		A(const A& a): dato(a.dato), miaCostante(a.miaCostante){
			// miaCostante = a.miaCostante; NON FUNZIONA -> una volta che entro nel costruttore lo spazio è allocato = non posso più fare modifiche alle const
			cout << "Costruttore di copia" << endl << endl;
		}
		~A(){
			cout << "Eliminato oggetto della classe A con " << *this << endl << endl;
		}
		int getDato() const{
			return dato;
		}
		int getMiaCostante() const{
			return miaCostante;
		}
		void setDato(int _dato){
			dato = _dato;
		}
		// l'operatore = viene implementato come metodo
		A& operator = (const int k){
			dato = k;
			miaCostante = k;
			cout << "Operator = eseguito int" << endl << endl;
			// devo restituire qualcosa -> noi a priori non sappiamo in che operazione ci siamo trovati
			// a2 = a1 + (a2 = 3); -> a2 = a1 + (nuovo valore di a2 -> lo devo ritornare per riferimento, NON PER COPIA!!!!)
			// this è un puntatore all'istanza corrente -> dereferenzio this (l'istanza corrente)
			return *this;
		}
		A& operator = (const A& a){
			dato = a.dato;
			miaCostante = a.miaCostante;
			cout << "Operator = eseguito A" << endl << endl;
			return *this;
		}
		
		A operator + (const A& a) const{
			//dato += a.dato; dato = dato + a.dato
			// a1 + a2 non modifica ne a1 ne a2 => devo tornare una nuova istanza di A!!!!
			// sbagliatissimo quello che abbiamo fatto
			cout << "Operator + eseguito A" << endl << endl;
			A temp;
			temp.dato = /*this->*/dato + a.dato;
			temp.miaCostante = this->miaCostante + a.miaCostante;
			return temp;
			// la variabile è locale, a riga 58 muore, per questo devo restituire la copia della variabile!!!!
		}
		A& operator += (const A& a){
			dato += a.dato;
			miaCostante += a.miaCostante;
			cout << "Operator += eseguito A" << endl << endl;
			return *this;
		}
		A& operator ++(){
			++dato;
			++miaCostante;
			cout << "Operator ++ prefisso eseguito A" << endl << endl;
			return *this;
		}
		A operator ++(int){
			/*
				A temp = *this;
				dato++; miaCostante++;
			*/
			A temp;
			temp.dato = dato++;
			temp.miaCostante = miaCostante++;
			cout << "Operator ++ postfisso eseguito A" << endl << endl;
			return temp;
		}
		A& operator --(){
			--dato;
			--miaCostante;
			cout << "Operator -- prefisso eseguito A" << endl << endl;
			return *this;
		}
		A operator --(int){
			/*
				A temp = *this;
				dato--; miaCostante--;
			*/
			A temp;
			temp.dato = dato--;
			temp.miaCostante = miaCostante--;
			cout << "Operator -- postfisso eseguito A" << endl << endl;
			return temp;
		}
		friend ostream& operator << (ostream& os, const A& a);
};

// questo metodo riesce a vedere gli attributi privati perché è impostato a friend nella definizione di A
ostream& operator << (ostream& os, const A& a){
	os << "a.dato = " << a.dato << " e a.miaCostante = " << a.miaCostante;
	return os;
}

void boh(A a){
	cout << "BOH: " << a << endl << endl;
}

/*
without friend
ostream& operator << (ostream& os, const A& a){
	os << "a.getDato() = " << a.dato << " a.getMiaCostante() = " << a.miaCostante;
	return os;
}
*/

int main(int argc, char ** argv){
	A a1, a2(3), a3(4, 5);
	
	cout << a1 << endl << endl;
	/*
	boh(a2);
	
	a1 = 5; // c'è un membro costante -> non posso fare quest'operazione altrimenti avrebbe fatto la conversione implicita
	cout << a1 << endl << endl;
	// a1 = a2; -> non posso usare con variabile costante
	a1 = a2;
	cout << a1 << endl << endl;
	
	// viene chiamato l'operatore = e +
	a1 = a1 + a2;
	cout << a1 << endl << endl;
	// != da + -> prende due istanze mentre += prende solo una
	a1 += a2; // a1 = a1 + a2
	// alla luce di ciò, è più veloce l'operatore +=
	// non viene creata una copia che usa memoria
	cout << a1 << endl << endl;
	*/
	cout << ++a1 << endl << endl; // prefisso -> stampa 1 4
	cout << a1 << endl << endl; // stampa 1 4
	cout << a1++ << endl << endl; // postfisso -> stampa 1 4
	cout << a1 << endl << endl;	// stampa 2 5
	// costa di più un post incremento che un pre incremento
	cout << --a1 << endl << endl; // prefisso -> stampa 1 4
	cout << a1 << endl << endl; // stampa 1 4
	cout << a1-- << endl << endl; // postfisso -> stampa 1 4
	cout << a1 << endl << endl;	// stampa 0 3
	return 0;
}
