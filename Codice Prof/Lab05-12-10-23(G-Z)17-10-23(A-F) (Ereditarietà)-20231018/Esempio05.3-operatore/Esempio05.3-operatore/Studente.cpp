//Autore: Roberti Pierluigi
//Data: 06-05-2010

//contiene l'impementazione dell'interfaccia
#include "Studente.h"

#include <iostream>
using namespace std;

Studente::Studente(const string &_nome, const string &_cognome, 
				   int _matricola, int _eta):Persona (_nome, _cognome, _eta), matricola(_matricola)
 {
//devo prima costruire l'istanza della classe Persona
//uso il suo costruttore di Persona
//il body dele construttore viene eseguito quando la classe è già in memoria
//serve solo per inizializzare i campi
//per questo motivo aggiungo dopo la dichiarazione del costruttore
//:Persona (_nome, _cognome, _eta)
//se aggiungo di seguito , matricola(_matricola) inizializzo il campo matricola evitando l'istruzione che segue
	matricola=_matricola;
	esami=0;
}

void Studente::Stampa() const{ 
//	cout << "Studente::Stampa " << nome << " " << cognome << " " << eta << " " << matricola;
	// NON POSSO ACCEDERE A MEMBRI PRIVATI DICHIARATI NELLA CLASSE PERSONA!!!
	 //oppure utilizzo il metodo dalla classe originale 
	cout << "Studente::Stampa "; 
	Persona::Stampa();
	cout << " matricola:" << matricola <<endl;
}

ostream& operator << (ostream& os, Studente& s){
   os << "Studente:" << s.get_nome() << " " << s.get_cognome() << " " << s.get_eta(); 
   os << " matricola:" << s.matricola; 
   return os;       
}

