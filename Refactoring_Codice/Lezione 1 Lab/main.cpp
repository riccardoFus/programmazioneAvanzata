#include <cstdlib>
#include <iostream>
#include <string>
#include "persona.h"
using namespace std;

int main(int argc, char ** argv){
    Persona persona_1;
    persona_1.set_eta(33);

    Persona persona_2("Anna", "Rossi", 39);
    persona_2.stampa();

    stampa_con_copia(persona_2);
    stampa_con_riferimento(persona_1);
    stampa_con_puntatore(&persona_2);

    cout << persona_1 << endl;
    cout << persona_2 << endl;

    Persona *puntatore_persona;
    puntatore_persona = new Persona("Luca", "Verdi");
    puntatore_persona->stampa();
    stampa_con_puntatore(puntatore_persona);
    stampa_con_riferimento(*puntatore_persona);
    delete puntatore_persona;
}