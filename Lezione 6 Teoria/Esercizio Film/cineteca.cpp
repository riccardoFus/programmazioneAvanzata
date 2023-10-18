#include "cineteca.h"

Cineteca::Cineteca(){
    codice_progressivo = 0;
}

void Cineteca::add_film(const Film& _f){
    mappa_film[++codice_progressivo] = _f;
}

Film Cineteca::get_film(int _cod){
    if(mappa_film.find(_cod) != mappa_film.end()){
        return mappa_film[_cod];
    }else{
        return Film();
    }
}

ostream& operator << (ostream& os, const Cineteca& _c){
    map<int, Film>::const_iterator it;
    for(it = _c.mappa_film.begin(); it != _c.mappa_film.end(); ++it){
        os << it->first << " " << it->second << " ";
    }
    return os;
}

void test_Cineteca(){
    Cineteca c;
    c.add_film(Film("Amarcord"));
    c.add_film(Film("Duel"));
    c.add_film(Film("Alien"));
    cout << c << endl;
    cout << c.get_film(4) << endl;
    cout << c.get_film(3) << endl;
}