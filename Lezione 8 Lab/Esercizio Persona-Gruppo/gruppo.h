#ifndef GRUPPO_H
#define GRUPPO_H
#include <set>
#include <string>
#include "persona.h"

class Gruppo{
    private:
        set<Persona> set_persona; // composizione 0...*
        set<Persona*> set_puntatori_persona; // aggregazione 0...*
    public:
        Gruppo();
        ~Gruppo();
        // sbagliato: inserisco nel main la classe Persona
        void add_persona1(Persona p);
        // sbagliato: stessa cosa più passo una copia comunque
        void add_persona2(const Persona& p);
        void add_persona3(string nome);
        void add_persona4(Persona* p);
        friend ostream& operator << (ostream& os, const Gruppo& g);
        void remove_persona(string nome);
};

ostream& operator << (ostream& os, const Gruppo& g);

#endif