#include <iostream>
#include <map>
#include <string>
#include <list>
using namespace std;

int main(int argc, char ** argv){
    multimap<string, int> multimap_lista_esami;
    multimap_lista_esami.insert(pair<string, int>("Riccardo", 30));
    multimap_lista_esami.insert(pair<string, int>("Riccardo", 18));
    multimap_lista_esami.insert(pair<string, int>("Cesare", 30));
    multimap_lista_esami.insert(pair<string, int>("Cesare", 29));
    /*
        NON POSSO PIU' SOVRASCRIVERE PERCHé HO UNA CHIAVE CON PIU' ISTANZE
        Quale sovrascrivo? NON FUNZIONA
        lista_esami["Riccardo"] = 30;
        lista_esami["Riccardo"] = 25;
        lista_esami["Cesare"] = 18;
        lista_esami["Cesare"] = 25;
    */
    for(auto& studente : multimap_lista_esami){
        cout << studente.first << " : " << studente.second << endl;
    }
    map<string, list<int>> mappa_lista_esami;
    mappa_lista_esami.insert(pair<string, list<int>>("Riccardo", {25, 18}));
    mappa_lista_esami["Cesare"].push_front(30);
    mappa_lista_esami["Cesare"].push_front(29);
    for(auto it = mappa_lista_esami.begin(); it != mappa_lista_esami.end(); it++){
        cout << it->first << " = ";
        for(auto voto = it->second.begin(); voto != it->second.end(); voto++){
            cout << *voto << " ";
        }
        cout << endl;
    }
    for(auto& studente : mappa_lista_esami){
        cout << studente.first << " = ";
        for(auto& voto : studente.second){
            cout << voto << " ";
        }
        cout << endl;
    }

    return 0;
}