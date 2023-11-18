#ifndef SPETTATORE_H
#define SPETTATORE_H

#include <iostream>
#include<set>
using namespace std;

#include "film.h"
class spettatore{
      string nome;
      //film preferito; // ogni spettatore ha un film preferito
      //list<film> l;
      //set<film> s; definendo operator<
      set<film*> sfp;
      film *pp;// ogni spettatore ha un film preferito
      //list<pair<int,int> > l; // il primo cod del film secondo e' il voto
      //list<pari<film*,int> > lp;
      public:
      spettatore();
      spettatore(string _s, film& f);
      spettatore(string _s);
      void add_film_gradito(film& f);
      friend ostream& operator<<(ostream& os, const spettatore& _s);
      };

ostream& operator<<(ostream& os, const spettatore& _s);
void test_spettatore();

#endif
