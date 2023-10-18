#include <cstdlib>
#include <iostream>
using namespace std;
#include "Persona.h"
#include "Studente.h"
int main(int argc, char *argv[]){
    {
	Persona p("Una", "Persona", 22);
    p.Stampa(); cout << endl;
   	cout << p << endl;
	
    Studente s("Mario", "Studente", 129345, 30);
    s.Stampa(); cout << endl;
    cout << s << endl;
	//RISULTATI:
	//Persona:Stampa Una Persona 22
	//Persona:Stampa Uno Studente 30
	//se non ho inserito in Studente.cpp l'implementazione di void stampa() const
	//altrimenti ottengo
	//Studente:Stampa Persona:Stampa Uno Studente 30 129345
	Persona* sp;
	sp = new Studente("Luca", "Studente", 129345, 30);
	sp->Stampa();

	//devo mettere virtual sul metodo di stampa di Persona affinchè
	//venga richiamato il metodo di stampa di Studente
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}
