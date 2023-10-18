#include "spettatore.h"

//spettatore::spettatore(){nome="";}

// andrebbe tolto se volessimo implementare in modo stretto 1,1 nella relazione
spettatore::spettatore(){nome="";pp=NULL;}

spettatore::spettatore(string _s){nome=_s;}

spettatore::spettatore(string _s,film& f){nome=_s;pp=&f;}

//ostream& operator<<(ostream& os, const spettatore& _s){
//         return os<<_s.nome;
//         }
 
void spettatore::add_film_gradito(film& f)
   {sfp.insert(&f);
    f.add_spettatore(*this);}
    
ostream& operator<<(ostream& os, const spettatore& _s){
         os<<_s.nome;
         if (_s.pp!=NULL) os<<*(_s.pp);
         set<film*>::iterator it;
         for(it=_s.sfp.begin();it!=_s.sfp.end();it++)
           os<<**it;
        return os;
         } 
         
void test_spettatore(){
     spettatore s;
     cout<<s;
     spettatore s2("Indeciso");
     cout<<s2;
     film m("Duel");
     spettatore s1("Pinco",m);
     cout<<s1;
     film m1("Bambi");
     film m2("Vattelapesca");
     s1.add_film_gradito(m1);
     s1.add_film_gradito(m2);
     cout<<endl;
     cout<<s1;
     }
