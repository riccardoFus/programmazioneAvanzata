#ifndef STUDENTE_H
#define STUDENTE_H
#include "persona.h"

// eredito gli attributi pubblici SOLO
class Studente: public Persona{
    private:
        int matricola, esami;
    public:
        // esami parte da 0
        Studente(int _matricola, string _nome, string _cognome, int _eta = 0);
        ~Studente();
        void stampa();
        ostream& stampaOperator(ostream& os) const; // const è fondamentale!!! DEVE ESSERE UGUALE A QUELLO DI PERSONA
        void test(){};
        friend ostream& operator << (ostream& os, const Studente& s);
};

ostream& operator << (ostream& os, const Studente& s);

#endif
