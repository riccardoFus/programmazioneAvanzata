/*
    Creare una multimap<string, int> e inserisci 10 elementi (dati sotto); crea una multimappa "inversa"
    che mappa <int, string> gli stessi elementi con valori e chiavi scambiati
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

template <typename T1, typename T2>
void stampa_multimap(multimap<T1, T2>& multimap_da_stampare){
    for(auto& coppia : multimap_da_stampare){
        cout << coppia.first << " " << coppia.second << endl;
    }
}

// VANNO MESSE A INIZIO DI OGNI FUNZIONE, ECC... 
template <typename T1, typename T2>
multimap<T2, T1> reverse_multimap(multimap<T1, T2>& multimap_da_invertire){
    multimap<T2, T1> multimap_invertita;
    for(auto& coppia : multimap_da_invertire){
        multimap_invertita.insert(pair<T2, T1>(coppia.second, coppia.first));
    }
    return multimap_invertita;
}

int main(int argc, char ** argv){
    multimap<string, int> starting_multimap;
    starting_multimap.insert(pair<string, int>(string("A"), 3));
    starting_multimap.insert(pair<string, int>(string("A"), 4));
    starting_multimap.insert(pair<string, int>(string("C"), 3));
    starting_multimap.insert(pair<string, int>(string("W"), 12));
    starting_multimap.insert(pair<string, int>(string("Fsad"), 13));
    starting_multimap.insert(pair<string, int>(string("CCC"), 13));
    starting_multimap.insert(pair<string, int>(string("A"), 13));
    starting_multimap.insert(pair<string, int>(string("NN"), 33));
    starting_multimap.insert(pair<string, int>(string("B"), 3));
    starting_multimap.insert(pair<string, int>(string("A"), 16));
    cout << "Multimap di partenza : " << endl;
    stampa_multimap(starting_multimap);
    cout << "\nEffettuo il 'reverse' del multimap" << endl;
    multimap<int, string> reversed_multimap;
    reversed_multimap = reverse_multimap(starting_multimap);
    stampa_multimap(reversed_multimap);

}