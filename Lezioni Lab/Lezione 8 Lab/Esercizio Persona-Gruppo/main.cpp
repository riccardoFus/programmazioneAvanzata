#include <iostream>
#include <set>
#include "persona.h"
#include "gruppo.h"
using namespace std;

void stampa_set(set<Persona>& set_da_stampare){
    for(auto& i : set_da_stampare){
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char ** argv){
    /*
    set<Persona> set_persone;
    Persona persona_1("Mario");
    set_persone.insert(persona_1);
    set_persone.insert(Persona("Anna"));
    // set_persone.insert(Persona("Anna"));
    stampa_set(set_persone);

    set<Persona>::iterator set_persone_iterator;
    set_persone_iterator = set_persone.find(Persona("Anna")); // non serve l'==
    if(set_persone_iterator != set_persone.end()){
        set_persone.erase(set_persone_iterator);
    }
    stampa_set(set_persone);
    */

    Gruppo gruppo;
    gruppo.add_persona3("Anna");
    gruppo.add_persona3("Michele");
    gruppo.add_persona3("Riccardo");

    cout << gruppo << endl;

    gruppo.remove_persona("Anna");
    
    cout << gruppo << endl;

    Persona p_1("Mirko");
    Persona p_2("Caio");
    gruppo.add_persona4(&p_1);
    gruppo.add_persona4(&p_2);

    cout << gruppo << endl;

    return 0;
}