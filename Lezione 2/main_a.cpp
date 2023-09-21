#include <iostream>
using namespace std;

// costruttore esplicito o non esplicito
class Prova{
	private:
		int dato;
	public:
		// il costruttore può essere richiamato iif chiamato esplicitamente
		explicit Prova(int d){
			dato = d;
			cout << "Costruttore specifico: " << d << endl;
		}
		// ricorda sempre il const NomeClasse& nomeOggetto
		// nel caso di una variabile temporanea non viene utilizzato il costruttore di copia
		Prova(const Prova& p){
			dato = p.dato;
			cout << "Costruttore di copia" << endl; 
		}
		~Prova(){
			cout << "Distruttore di: " << dato << endl;
		}
		int getDato() const{
			return dato;
		}
		// amico della classe -> mi fido e quindi posso accedere agli attributi privati
		friend ostream& operator << (ostream& os, const Prova& p);
		// metodo inline -> tecnica che arriva al compilatore, per capire come utilizzare le funzioni, ottimizza i tempi della funzione
		// sostituisce le definizioni di funzione ovunque vengano chiamate
		// il compilatore sostituisce la definizione delle funzioni inline in fase di compilazione invece di fare riferimento alla definizione
};

// scopeClasse::nomeMetodo(param1, ..., paramN)

// indirizzo della funzione -> la mette nello stack -> passa parametri -> esegue -> toglie dallo stack
// prendi il codice e sostituisce nella chiamata semplicemente -> il compilatore può decidere se accettare o non -> il compilatore nel caso
// accetta non deve spostarsi -> problemi: metodi virtuali non devono essere inline -> LO VEDREMO MEGLIO

// PRO: veloce, risparmio spazio di memoria
// CONTRO: eseguibile più grande (es: tante volte richiamata una funzione x), memorie virtuali

// oggetto passato per copia, se passiamo una variabile temporanea per riferimento c'è un problema
void test(Prova p){
	// non è amico della classe Prova
	// p.dato = 2;
	cout << p.getDato() << endl;
}

// overload dell'operatore <<
ostream& operator << (ostream& os, const Prova& p){
	// questo è possibile iif c'è friend nella classe
	return os << " " << p.dato << endl;
	// return os << " " << p.getDato() << endl;
}

int main(int argc, char** argv) {
	// useremo una funzione che riceve un'istanza di Prova
	// normalmente avremmo Prova P = new Prova(2) oppure Prova p(2) -> allocate nello stack in questo stack
	test( Prova(2) );
	// stranamente non si arrabbia -> il compilatore cerca di aiutare -> mi aspetto un'istanza di Prova che posso ottenere da un numero intero
	// quindi gcc ovvia a questo problema -> il 9 lo utilizza con il costruttore specifico arraggiandosi
	// si può evitare questa cosa mettendo il termine explicit
	
	// take-home message: sempre conveniente mettere explicit con costruttore a 1 parametro
	
	// test( 9 );
	
	Prova miaP(5);
	test(miaP);
	
	cout << "L'oggetto di prova creato e': " << miaP;
	return 0;
}
