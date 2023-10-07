#include <cstdlib>
#include <iostream>
#include <string>
// includo la libreria
#include "persona.h"

using namespace std;

int main(int argc, char *argv[])
{
    Persona mario;
    // mario.eta = 33;
    mario.setEta(33);
    // cout << mario.eta << endl;
    // cout << mario.getEta() << endl;
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
    cout << "Persona = " << mario << endl;
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
