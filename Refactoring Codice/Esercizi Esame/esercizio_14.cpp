/*
    Crea una lista di stringhe, tale lista deve contenere 5 nomi di persone poi eseguire
    le seguenti operazioni, curandoti di stampare la lista alla fine di ciascuna:
        * inserisci nella lista due Paolo e tre Giovanni in posizioni casuali
        * usando funzioni di algorithm ruota la lista nelle posizioni [0 - 7] usando come perno
        la posizione 3
        * rimpiazza tutti i Paolo con Franco
        * rimuovi tutti i Franchi nelle prime 6 posizioni
        * usando una lambda stampa tutti i nomi con lunghezza minore o uguale a 5
*/
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

void print(list<string>& l){
    for(const auto& v : l){
        cout << v << " ";
    }
    cout << endl;
}

list<string>::iterator get_it(list<string>& l, const int& n){
    list<string>::iterator it = l.begin();
    for(int i = 0; i < n; i++){
        ++it;
    }
    return it;
}

int main(int argc, char ** argv){
    srand(time(NULL));
    list<string> nomi = {"Luca", "Franco", "Mimmo", "Giuseppe", "Leo"};
    print(nomi);
    for(int i = 0; i < 2; i++){
        nomi.insert(get_it(nomi, rand() % nomi.size() + 1), "Paolo");
    }
    for(int i = 0; i < 3; i++){
        nomi.insert(get_it(nomi, rand() % nomi.size() + 1), "Giovanni");
    }
    print(nomi);
    rotate(nomi.begin(), get_it(nomi, 3), get_it(nomi, 7));
    print(nomi);
    replace(nomi.begin(), nomi.end(), string("Paolo"), string("Franco"));
    print(nomi);
    nomi.erase(remove(nomi.begin(), get_it(nomi, 6), "Franco")), nomi.end();
    print(nomi);
    for_each(nomi.begin(), nomi.end(), [](const string& nome){
        if(nome.size() <= 5){
            cout << nome << " ";
        }
    });
    return 0;
}