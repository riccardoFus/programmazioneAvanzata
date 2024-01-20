/*
    Crea una mappa parcheggi di <string, int> e popolala di tre elementi 
    ("FIERA", 200), ("FLAVIO", 250) e ("FLUENTE", 200).
    Crea una funzione StampaOrdineDec che stampi questi elementi in ordine 
    decrescente secondo il numero di posti (si consiglia l'utilizzo di una
    struttura di supporto); se due parcheggi hanno lo stesso numero di posti
    non è necessario fare ulteriori elucubrazioni su quale stampare prima,
    qualsiasi ordine andrà bene.
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

void stampa_ordine_dec(map<string, int>& parcheggi){
    multimap<int, string> parcheggi_ordinati_per_posti;
    for(auto p : parcheggi){
        parcheggi_ordinati_per_posti.insert(pair<int, string>(p.second, p.first));
    }
    for(auto it = parcheggi_ordinati_per_posti.rbegin(); it != parcheggi_ordinati_per_posti.rend(); it++){
        cout << it->second << " " << it->first << endl;
    }
}

int main(int argc, char ** argv){
    map<string, int> parcheggi;
    parcheggi["FIERA"] = 200;
    parcheggi["FLAVIO"] = 250;
    parcheggi["FLUENTE"] = 200;
    parcheggi["ANNA"] = 300;
    parcheggi["MICHELE"] = 250;
    parcheggi["LUCA"] = 150;

    stampa_ordine_dec(parcheggi);

    return 0;
}