/*
    Costruire una classe "Persona" contenente i campi nome, cognome ed età;
    Creare una mappa con chiave stringa e valore lista di Persona (map<string, list<Persona>>), e questa
    mappa dovrà contenere 3 valori diversi ("a", "b", "c") ed ogni lista dovrà contenere 2 persone diverse.
    La mappa sarà istanziata nel main e sarà l'unica variabile nel main;
    Iterare su tutti gli elementi della mappa e stampare tutte le persone di ogni lista (NON puoi usare un metodo stampa()
    in Persona)
    Alla fine itera su tutti gli elementi e rimuovi le persone con età maggiore di 30 (<algorithm>)
*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Persona{
    private:
        string nome, cognome;
        int eta;
    public:
        Persona(string nome, string cognome, int eta){
            this->nome = nome;
            this->cognome = cognome;
            this->eta = eta;
        }
        int get_eta() const {
            return eta;
        }
        friend ostream& operator << (ostream& os, const Persona& p);
};

bool is_maggiore_trenta_anni(const Persona& p){
    return p.get_eta() > 30 ? true : false;
}

ostream& operator << (ostream& os, const Persona& p){
    os << p.nome << " " << p.cognome << " di eta' " << p.eta;
    return os;  
}

int main(int argc, char ** argv){
    map<string, list<Persona>> mappa;
    mappa["a"].push_back(Persona("Riccardo", "Fusiello", 21));
    mappa["a"].push_back(Persona("Michele", "Matera", 31));
    mappa["b"].push_back(Persona("Giuseppe", "Liso", 33));
    mappa["b"].push_back(Persona("Salvatore", "Matera", 22));
    mappa["c"].push_back(Persona("Loredana", "Salvemini", 20));
    mappa["c"].push_back(Persona("Mario", "Sempronio", 19));

    map<string, list<Persona>>::const_iterator it;
    for(it = mappa.begin(); it != mappa.end(); it++){
        cout << "Key : " << it->first << endl;
        list<Persona>::const_iterator it2;
        for(it2 = it->second.begin(); it2 != it->second.end(); it2++){
            cout << "\tPersona : " << *it2 << endl;
        }
    }

    for(auto& map : mappa){
        cout << "Rimuovo le persone con eta' maggiore di 30 della mappa con chiave " << map.first << endl;
        map.second.erase(remove_if(map.second.begin(), map.second.end(), is_maggiore_trenta_anni), map.second.end());
    }

    for(it = mappa.begin(); it != mappa.end(); it++){
        cout << "Key : " << it->first << endl;
        list<Persona>::const_iterator it2;
        for(it2 = it->second.begin(); it2 != it->second.end(); it2++){
            cout << "\tPersona : " << *it2 << endl;
        }
    }
    
    return 0;
}