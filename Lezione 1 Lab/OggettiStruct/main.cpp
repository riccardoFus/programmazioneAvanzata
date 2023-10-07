//Autore: Roberti Pierluigi
#include <cstdlib>
#include <iostream>
using namespace std;

//il main sa come � fatta una persona non come � implementata!!!
#include "Persona.h"

//per compilare:
//g++ main.cpp
//ERRORE: il linker ha un riferimento non definito ai metodi (manca infatti Persona.cpp)
//g++ main.cpp persona.cpp
//creo un file a.out
//l'ordine dei FILE non � importante
//i file H non vengono MAI compilati

//OPPURE
//g++ -c main.cpp
//produce main.o
//g++ -c persona.cpp
//produce persona.o
//chiamo infine il linker
//g++ main.o persona.o
//creo un file a.out

int main()
{	
	//Anna non esiste all'infuori del blocco delle {}
	//visibilit� ristretta dell'istanza dell'oggetto Anna
	{
	Persona Anna("Anna", "Rossi", 22);
    Anna.Stampa();
	Anna.eta += 20;  //PERICOLOSO
	Anna.Stampa();
	Stampa(Anna);
	//nascondo il modo con cui una classe � implementata
	//quello che voglio rendere pubblico � l'interfaccia
	//ogni classe mette a disposizione dei metodi
	//main accede ad un campo della classe, la cosa non va bene perch� non 
	//� detto che sia lecito, l'istanza di Anna potrebbe in questo caso non essere pi�
	//lecito. ESEMPIO, cambio data di nascita e cambio anche l'et�
	//in questo modo non ottengo questa doppia modifica
	// => Anna potrebbe trovarsi in uno stato "inconsistente"
	//per questo motivo so toglie l'accesso ai campi e si da un metodo che cambia i campi
	}
	//Anna viene distrutta dopo il blocco che la contiene
    system("pause"); 
	return 0;
}
