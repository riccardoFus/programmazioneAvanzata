#include <cstdlib>
#include <iostream>
#include "persona.h"
using namespace std;

// un solo costruttore inibisce il costruttore di default di partenza
Persona::Persona(){
   // diverso da quello standard -> non metteva il valore di eta
   cout << "Costruttore standard" << endl;
   nome = "Gianni";
   cognome = "Verdi";
   eta = 18;          
   b = NULL;
}

// quando mettiamo param=value intendiamo che vogliamo dare un valore default al parametro iif non riceve nessun valore come parametro nella chiamata al metodo
Persona::Persona(string _nome, string _cognome, int _eta){
    cout << "Costruttore specifico " << nome << cognome << endl;
    eta = _eta;
    nome = _nome;	
    cognome = _cognome;
    b = new int[5]; // array di 5 interi
    for(int i = 0; i < 5; i++){
    	b[i] = i;
	}
}

// alt + 126
// distruttore
Persona::~Persona(){
	if(b != NULL){
		delete[] b;
	}
	cout << "Distrutto: " << nome << " " << cognome << endl;
}	

// costruttore copia PROFONDA + passaggio riferimento
Persona::Persona(const Persona& p){ 
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

// non deve modificare gli attributi -> metto const
void Persona::stampa() const{
    cout << nome << " " << cognome << " di eta: " << eta << endl;
    if(b != NULL){
	    for(int i = 0; i < 5; i++){
	    	cout << b[i] << " ";
		}
		cout << endl;	
	}
}
void Persona::setEta(int _eta){
    eta = _eta;
}    
int Persona::getEta() const{
    return eta;    
} 
void Persona::setNome(string _nome){
	nome = _nome;
}
string Persona::getNome() const{
	return nome;
}
void Persona::setCognome(string _cognome){
	cognome = _cognome;
}
string Persona::getCognome() const{
	return cognome;
}
int* Persona::getB() const{
	return b;
}

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
	int* tmp = p.getB();
	ostream& returnValue = os << p.getNome() << " " << p.getCognome() << " di eta: " << p.getEta() << ", l'array e': ";
	if(tmp != NULL){
		return returnValue << tmp[0] << " " << tmp[1] << " " << tmp[2] << " " << tmp[3] << " " << tmp[4];
	}else{
		return returnValue;
	}
}
