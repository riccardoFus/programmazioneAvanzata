#include "cineteca.h"

cineteca::cineteca(){cp=0;}

void cineteca::add_film(const film& _f){
     m[++cp]=_f;
     }

film cineteca::get_film(int _cod){
     if (m.find(_cod)!=m.end()) return m[_cod];
         else return film();
     }
      
ostream& operator<<(ostream& os, const cineteca& _c){
         map<int,film>::const_iterator it;
         for(it=_c.m.begin();it!=_c.m.end();it++)
            os<<it->first<<" "<<it->second<<" ";
         return os;
         }
         
void test_cineteca(){
     cineteca c;
     c.add_film(film("Amarcord"));
     c.add_film(film("Duel"));
     c.add_film(film("Alien"));
     cout<<c;
     cout<<c.get_film(3);
     cout<<c.get_film(4);
     }
