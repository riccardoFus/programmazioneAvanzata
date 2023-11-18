#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>

using namespace std;

#include <list>

class Spettatore;

class Film{
    string nome;
    list<Spettatore*> lista_spettatori;
    public:
        Film();
        Film(string _s);
        friend ostream& operator << (ostream& os, const Film& _s);
        void add_spettatore(Spettatore& _s);
        void stampa_spettatori();
};

ostream& operator << (ostream& os, const Film& _s);
void test_Film();

#endif