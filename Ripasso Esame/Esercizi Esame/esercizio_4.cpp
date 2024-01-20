/*
    Prepara una lista di caratteri, inizializzala con 8 lettere minuscole casuali:
        * Verifica se tutti i caratteri nella lista sono compresi nell'intervallo a-m
        * Verifica se c'è almeno un'occorenza di x, y, z
        * Verifica se c'è almeno un'occorenza di lettere uguali adiacenti, in caso affermativo, rimuovile
        * Verifica se la stringa formata dalla concatenazione di questi caratteri è una permutazione della stringa "bucefalo"
*/
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

bool is_intervallo_a_m(char carattere){
    if(carattere >= 'a' && carattere <= 'm'){
        return true;
    }else{
        return false;
    }
}

bool is_x_y_or_z(char carattere){
    if(carattere == 'x' || carattere == 'y' || carattere == 'z'){
        return true;
    }else{
        return false;
    }
}

void stampa_lista(list<char>& lista){
    for(auto& c : lista){
        cout << c << " ";
    }
    cout << endl;
}

int main(int argc, char ** argv){
    srand(time(NULL));

    list<char> lista_caratteri;
    for(int i = 0; i < 8; i++){
        char carattere_da_aggiungere = 'a' + rand()%26;
        lista_caratteri.push_back(carattere_da_aggiungere);
    }

    stampa_lista(lista_caratteri);

    cout << "Tutti i caratteri sono nell'intervallo a-m? " << bool(all_of(lista_caratteri.begin(), lista_caratteri.end(), is_intervallo_a_m)) << endl;
    cout << "C'e' almeno un'occorenza di x, y o z? " << bool(any_of(lista_caratteri.begin(), lista_caratteri.end(), is_x_y_or_z)) << endl;

    list<char> bucefalo;
    for(auto c : "bucefalo"){
        bucefalo.push_back(c);
    }
    cout << "La stringa e' permutazione di bucefalo? " << bool(is_permutation(lista_caratteri.begin(), lista_caratteri.end(), bucefalo.begin())) << endl;

    list<char>::iterator coppie_da_rimuovere;
    coppie_da_rimuovere = adjacent_find(lista_caratteri.begin(), lista_caratteri.end());
    while(coppie_da_rimuovere != lista_caratteri.end()){
        lista_caratteri.erase(coppie_da_rimuovere);
        coppie_da_rimuovere = adjacent_find(lista_caratteri.begin(), lista_caratteri.end());
    }
    
    stampa_lista(lista_caratteri);
}