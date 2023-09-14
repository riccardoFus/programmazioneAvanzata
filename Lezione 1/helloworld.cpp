#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// class : costruttore default, distruttore, costruttore copia

// mettere sempre gli attributi sempre privati
class Persona{
    // by default : nella classe tutto è privato
private: 
    // char *nome, *cognome;
    string nome, cognome;
    int eta;
    // su b voglio allocare un array di interi
    int *b;
public:  
	 // un solo costruttore inibisce il costruttore di default di partenza
	Persona(){
       // diverso da quello standard -> non metteva il valore di eta
       cout << "Costruttore standard" << endl;
       nome = "Gianni";
       cognome = "Verdi";
       eta = 18;          
       b = NULL;
	}
	Persona(string _nome, string _cognome, int _eta=0){
	    cout << "Costruttore specifico " << nome << cognome << endl;
	    eta = _eta;
        nome = _nome;	
        cognome = _cognome;
        b = new int[5]; // array di 5 interi
        for(int i = 0; i < 5; i++){
        	b[i] = i;
		}
	}
	Persona(const Persona& p){ // costruttore copia PROFONDA + passaggio riferimento
		nome = p.nome;
	 	cognome = p.cognome;
	 	eta = p.eta;
	 	// b = p.b;
	 	if(p.b == NULL){
	 		b = NULL;
		}else{
			b = new int [5];
			for(int i = 0; i < 5; i++){
				b[i] = p.b[i];
			}
		}
	 	cout << "Costruttore copia" << endl;
	}
	// alt + 126
	// distruttore
	~Persona(){
		if(b != NULL){
			delete[] b;
		}
		cout << "Distrutto: " << nome << " " << cognome << endl;
	}
	// non deve modificare gli attributi -> metto const
	void stampa() const{
	    cout << nome << " " << cognome << " di eta: " << eta << endl;
	    if(b != NULL){
		    for(int i = 0; i < 5; i++){
		    	cout << b[i] << " ";
			}
			cout << endl;	
		}
	}
	void setEta(int _eta){
	    eta = _eta;
	}    
	int getEta() const{
	    return eta;    
	} 
	void setNome(string _nome){
		nome = _nome;
	}
	string getNome() const{
		return nome;
	}
	void setCognome(string _cognome){
		cognome = _cognome;
	}
	string getCognome() const{
		return cognome;
	}
protected:
};

// IMPORTANTE : PER OGNI FUNZIONE/PROCEDURA/METODO CHE NON DEVE MODIFICARE VARIABILI
// PASSARE TUTTO CONST!!!!!!!

void stampa1(const Persona p){
	//cout << p.nome << " " << p.cognome << " di eta: " << p.eta << endl;
	p.stampa();
}

void stampa2(const Persona* p){
	p->stampa();
}

void stampa3(const Persona& p){
	p.stampa();
}

// overload degli operatori -> devo definire come comportarsi quando riceve un determinato operatore
// per fare questo devono esserci using namespace std; e <iostream>
// attenzione : è un operatore
ostream& operator <<(ostream& os, const Persona& p){
	// errore grave : p.stampa()
	return os << p.getNome() << " " << p.getCognome() << " di eta: " << p.getEta();
}

int main(int argc, char *argv[])
{
    Persona mario;
    // mario.eta = 33;
    mario.setEta(33);
    // cout << mario.eta << endl;
    //cout << mario.getEta() << endl;
    Persona anna("Anna", "Rossi", 39);
    // memoria stack -> viene uccisa prima anna e poi mario -> l'ultima ad essere modificata è la prima ad essere eliminata
    anna.stampa();
    // reminder : c'è una copia non degli elementi ma dell'indirizzo,
	// quando viene distrutta quest'anna viene distrutto anche l'array
	// se passiamo una copia di una struct/class con elementi allocati dinamicamente : CASINO -> BISOGNA FARE COPIA PROFONDA
    stampa1(anna);
    stampa3(mario);
    stampa2(&anna);
    stampa3(anna);
    cout << "Persona = " << anna << endl;
    Persona *p;
    p = new Persona("Luca", "Verdi"); // esempio di parametro opzionale, NB: non possono essere scaglionati, solo gli ultimi
    p->stampa();
    stampa2(p);
    stampa3(*p);
    // ricorda di eliminare sempre qualsiasi cosa dinamica
	// AD OGNI NEW ASSOCIARE UN DELETE
    delete p;
    // TO-DO: modificare << per stampare anche il contenuto dell'array
    return 0;
}
