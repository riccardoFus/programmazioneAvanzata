#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>
#include <iostream>
#include "motore.h"
using namespace std;

class Automobile{
    private:
        string marca, modello;
        Motore motore;
        Motore* motore_scorta;
    public:
        // Automobile(string _marca, string _modello, int cilindrata, tipo_combustibile combustibile);
        Automobile(string _marca, string _modello, int cilindrata, Tipo_Combustibile* tipo_combustibile);
        ~Automobile();
        void add_motore_scorta(int cilindrata, Tipo_Combustibile* tipo_combustibile);
        friend ostream& operator << (ostream& os, const Automobile& automobile);
};

ostream& operator << (ostream& os, const Automobile& automobile);

#endif