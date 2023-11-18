#include "film.h"

film::film(){nome="";}

film::film(string _s){nome=_s;}

void film::add_spettatore(spettatore& _s)
 {ls.push_back(&_s);}

ostream& operator<<(ostream& os, const film& _s){
         return os<<_s.nome;
         }
         
void test_film(){
     film f;
     cout<<f;
     film f1("Amarcord");
     cout<<f1;
     }
