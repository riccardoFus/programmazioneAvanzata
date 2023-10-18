#include <cstdlib>
#include <iostream>
using namespace std;

class Foo{
private:
  	int dato;
public:
  	// single parameter constructor, can be used as an implicit conversion
  	/*explicit*/ Foo (int _dato) : dato (_dato){
    	cout << "costruttore specifico, dato="  << dato << endl;    
  		/*
    	oppure 
    	Foo (int _dato){ dato=_dato; }
  		*/
	}
  	Foo(const Foo& f){
  		dato = f.dato;
	  	cout << "costruttore copia, dato="  << dato << endl;    	
  	}
  	~Foo(){
  		cout << "distruttore per dato="  << dato << endl; 
	}
  	int GetDato () { 
      	return dato; 
  	}
  	friend ostream& operator << (ostream& s, const Foo& f);
};
ostream& operator << (ostream& os, const Foo& f){
	os << f.dato;
	//posso accedere agli attributi provati perchè funzione/operatore 
	//è friend della classe
	return os;
}

void DoBar (Foo myfoo){
  int val = myfoo.GetDato ();
  cout << "dato=" << val << endl;
  cout << "foo=" << myfoo << endl;
}

int main(int argc, char *argv[]){
   DoBar (42);          //non può essere utilizzata se costruttore "explicit"
   DoBar (Foo (33));	//non è invocato il costruttore di copia
   Foo f(0);			//invocato il costruttore specifico
   DoBar (f);			//è invocato il costruttore di copia
   /*
    L'argomento non è un oggetto Foo, ma un int. 
    Tuttavia, esiste un costruttore per Foo che prende un int:
    questo costruttore può essere utilizzato per convertire il parametro per il tipo corretto.
    Anteponendo la parola chiave explicit al costruttore, si impedisce al compilatore di utilizzare 
    quel costruttore per le conversioni implicite. 
    L'aggiunta alla classe precedente creerà un errore di compilazione alla chiamata di funzione Dobar(42). 
    Ora è necessario chiamare per la conversione in modo esplicito con DoBar (Foo (42))
   */
   /*
    Se si dispone di una classe MyString(int size) con un costruttore che costruisce una stringa della dimensione data. 
    Hai una funzione di stampa(const MyString &), e si chiama con stampa(3). 
    Ci si aspetta che la funzioni stampi "3", ma invece stampa una stringa vuota di lunghezza 3.
   */
   system("PAUSE");
   return EXIT_SUCCESS;
}
