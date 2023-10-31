#ifndef MOTORE_H
#define MOTORE_H
#include <iostream>
#include "tipocomb.h"
using namespace std;

class Motore{
    private:
        int cilindrata;
        Tipo_Combustibile* tipo1;
        Tipo_Combustibile* tipo2;
    public:
        // Motore(int _cilindrata, tipo_combustibile _tipo_combustibile);
        Motore(int _cilindrata, Tipo_Combustibile* _tipo1);
        ~Motore();
        friend ostream& operator << (ostream& os, const Motore& motore);
};

ostream& operator << (ostream& os, const Motore& motore);

#endif