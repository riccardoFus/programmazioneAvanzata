#ifndef STUDENTE_H
#define STUDENTE_H
#include "persona.h"

class Studente: public Persona{
    private:
        int matricola, esami;
    public:
        // esami parte da 0
        Studente(int matricola, string nome, string cognome, int eta = 0);
        ~Studente();
        void stampa() const;
        ostream& stampa_operator(ostream& os) const;
        // void test(){};
        friend ostream& operator << (ostream& os, const Studente& s);
};

ostream& operator << (ostream& os, const Studente& s);

#endif