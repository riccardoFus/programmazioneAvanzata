#include "film.h"

Film::Film(){
    nome = "";
}

Film::Film(string _s){
    nome = _s;
}

void Film::add_spettatore(Spettatore& _s){
    lista_spettatori.push_back(&_s);
}

void Film::stampa_spettatori(){
    for(auto spettatore : lista_spettatori){
        cout << spettatore << " ";
    }
    cout << endl;
}

ostream& operator << (ostream& os, const Film& _s){
    return os << _s.nome;
}

void test_Film(){
    Film f;
    cout << f << endl;
    Film f1("Amarcord");
    cout << f1 << endl;
}