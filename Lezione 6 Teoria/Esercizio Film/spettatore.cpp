#include "spettatore.h"

// Spettatore::Spettatore(){nome = "";}

// andrebbe tolto se volessimo implementare in modo stretto 1,1 nella relazione
Spettatore::Spettatore(){
    nome = "";
    pp = NULL;
}

Spettatore::Spettatore(string _s){
    nome = _s; // sbagliato
    pp = NULL;
}

Spettatore::Spettatore(string _s, Film& f){
    nome = _s;
    pp = &f;
}

void Spettatore::add_film_gradito(Film &f){
    set_film_preferiti.insert(&f);
    f.add_spettatore(*this);
}

ostream& operator << (ostream& os, const Spettatore& _s){
    os << _s.nome << " ";
    if(_s.pp != NULL){
        os << *(_s.pp) << " ";
    }
    set<Film*>::iterator it;
    for(it = _s.set_film_preferiti.begin(); it != _s.set_film_preferiti.end(); ++it){
        os << **it << " ";
    }
    return os;
}

void test_Spettatore(){
    Spettatore s;
    cout << s << endl;
    Spettatore s2("Indeciso");
    cout << s2 << endl;
    Film m("Duel");
    Spettatore s1("Pinco", m);
    cout << s1 << endl;
    Film m1("Bambi");
    Film m2("Vattelapesca");
    s1.add_film_gradito(m1);
    s1.add_film_gradito(m2);
    cout << endl;
    cout << s1 << endl;
}