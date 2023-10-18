#ifndef SPETTATORE_H
#define SPETTATORE_H

#include <iostream>
#include <set>
using namespace std;

#include "film.h"

class Spettatore{
    string nome;
    // Film preferito;
    // list<Film> lista_film;
    // set<Film> s;
    set<Film*> set_film_preferiti;
    Film *pp;
    // list<pair<int, int> > l;
    // list<pair<Film*, int>> lp;
    public:
        Spettatore();
        Spettatore(string _s, Film& f);
        Spettatore(string _s);
        void add_film_gradito(Film& f);
        friend ostream& operator << (ostream& os, const Spettatore& _s);
};

ostream& operator << (ostream& os, const Spettatore& _s);
void test_Spettatore();

#endif