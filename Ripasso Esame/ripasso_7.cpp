/*
    Questo file contiene:
    1) map
    2) multimap
*/
#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

int main(){
    map<string, int> mappa_interi;
    mappa_interi.insert(pair<string, int>("Mario", 34));
    mappa_interi["Luca"] = 12;
    for(const auto& it : mappa_interi){
        cout << it.first << " " << it.second << endl;
    }
    cout << mappa_interi["Luca"] << endl;
    if(mappa_interi.count("Carlo") > 0){
        cout << "TROVATO" << endl;
    }else{
        cout << "NON TROVATO" << endl;
    }

    auto it = mappa_interi.find("Luca");
    if(it != mappa_interi.end()){
        cout << "TROVATO" << endl;
        mappa_interi.erase(it);
    }else{
        cout << "NON TROVATO" << endl;
    }
    for(const auto& it : mappa_interi){
        cout << it.first << " " << it.second << endl;
    }

    multimap<string, int> multimap_esami;
    multimap_esami.insert(pair<string, int>("Riccardo", 25));
    multimap_esami.insert(pair<string, int>("Riccardo", 30));
    multimap_esami.insert(pair<string, int>("Riccardo", 18));
    multimap_esami.insert(pair<string, int>("Cesare", 18));
    multimap_esami.insert(pair<string, int>("Cesare", 30));
    for(const auto& it : multimap_esami){
        cout << it.first << " " << it.second << endl; 
    }
    map<string, list<int>> mappa_esami;
    mappa_esami.insert(pair<string, list<int>>("Riccardo", {25, 19}));
    mappa_esami["Cesare"].push_back(30);
    mappa_esami["Cesare"].push_back(29);
    for(const auto& it : mappa_esami){
        cout << it.first << endl;
        for(const auto& it2 : it.second){
            cout << it2 << " ";
        }
        cout << endl;
    }
    return 0;
}