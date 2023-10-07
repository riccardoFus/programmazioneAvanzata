#include <iostream>
// le librerie del c++ sono classi che contengono metodi
#include <fstream>
using namespace std;

// const, static, static const
class A{
	private:
		int dato;
		// attributo costante: attributo che all'interno dell'istanza non può cambiare valore
		// è possibile assegnare un valore a livello di attributo, problemi con static e const -> comportamenti != tra int e float
		const float miaCostante;
		// attributo static: attributo comune a tutte le istanze della classe A
		// ad esempio posso usarlo come contatore di istanze attive della classe
		// NI = NUMBER OF ISTANCES
		static int ni;
		// DIPENDE DAL COMPILATORE SE POSSO INIZIALIZZARE ALLA DICHIARAZIONE
		// static const: attributo comune alle istanze che non può cambiare una volta inizializzato
		static const int sci;// = 3;
		static const float scf;// 3.14; non funziona!!
	public:
		// cosi funziona -> nasce l'oggetto con la costante = ok
		A(): miaCostante(0.0){
			cout << "Costruttore zero parametri" << endl;
			dato = 0;
			// errore: una volta creata l'istanza, non lo puoi modificare più
			// miaCostante = 0.0;
			// ni = 1; questo genera problemi -> va inizializzato una sola volta per tutte le istanze -> FUORI DALLA CLASSE
			ni = ni + 1;
			// sci = 2; errore
		}
		// come un determinato attributo deve essere inizializzato
		// dato è intero -> inizializzo dato con il costruttore degli interi
		A(int d): dato(d), miaCostante(1.1){
			cout << "Costruttore specifico chiamato di: " << d << endl;
			// dato = d;
			ni = ni + 1;
		}
		A(const A& a): dato(a.dato), miaCostante(a.miaCostante){
			cout << "Costruttore copia chiamato di: " << a.dato << endl;
			// se facessi miaCostante = a.miaCostante -> problema
			// dato = a.dato;
			ni = ni + 1;
		}
		~A(){
			cout << "Distruttore chiamato di: " << dato << endl;
			ni = ni - 1;
			ofstream myFile;
			myFile.open("numIstanze.txt", ios::app);
			myFile << "Numero di istanze = " << ni << endl;
			// NON LASCIARE MAI UNO STREAM APERTO
			myFile.close();
		}
		// se definisco un metodo static -> elimino const!!
		static int getNI(){
			return ni;
		}
		friend ostream& operator << (ostream& os, const A& a);
};
// è una promessa: mi serve il tipo -> una sola volta viene creata l'attributo static
int A::ni = 0;
const int A::sci = 3;
// la f alla fine serve per decodificare in float il 3.14
const float A::scf = 3.14f;

// stream: flusso di dati che finiscono in stdout/file

ostream& operator << (ostream& os, const A& a){
	// MAI METTERE L'END OF LINE QUI
	os << " dato = " << a.dato << ", miaCostante = " << a.miaCostante << ", numero di istanze attive = " << a.getNI();
	return os;
}

int main(int argc, char** argv) {
	// doppio passaggio -> creata l'istanza -> inizializziamo
	// costruttore 0 parametri + assegnazione
	int d = 3;
	// nasce già inizializzato
	int r(3);
	// ni esiste a prescindere, getNI funziona iif esiste un'istanza della classe associato
	cout << "Numero di istanze attive: " << A::getNI() << endl;
	A a;
	cout << "Parametro a:" << a << endl;
	A b(2);
	cout << "Parametro b:" << b << endl;
	return 0;
}
