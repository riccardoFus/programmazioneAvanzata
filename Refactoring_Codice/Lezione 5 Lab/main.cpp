#include <iostream>
#include "persona.h"
#include "studente.h"
using namespace std;

int main(int argc, char ** argv){
    Persona persona_1("Riccardo", "Fusiello", 20);
    cout << persona_1 << endl;

    Persona persona_2("Appena", "Nato");
    cout << persona_2 << endl;

    persona_2.stampa();

    Studente studente_1(123456, "Michele", "Matera", 22);
    studente_1.stampa();

    Persona* puntatore_persona;
    puntatore_persona = new Persona("Michele", "Misseri", 77);
    delete puntatore_persona;

    puntatore_persona = new Studente(123555, "Nome", "Cognome", 99);
    puntatore_persona->stampa();
    cout << *puntatore_persona << endl;
    puntatore_persona->Persona::stampa();
    delete puntatore_persona;

    persona_1 = studente_1;
    persona_1.stampa();
}