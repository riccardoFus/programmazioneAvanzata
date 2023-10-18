#ifndef CINETECA_H
#define CINETECA_H

#include <iostream>
using namespace std;
#include "Film.h"
#include <map>

class Cineteca{
    int codice_progressivo;
    map<int, Film> mappa_film;
    public:
        Cineteca();
        void add_film(const Film& _f);
        Film get_film(int _cod);
        friend ostream& operator << (ostream& os, const Cineteca& _c);
};

ostream& operator << (ostream& os, const Cineteca& _c);
void test_Cineteca();

#endif