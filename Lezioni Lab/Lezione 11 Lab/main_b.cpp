#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

bool is_greater_than(int valore){
    return valore > 5;
}

int main(int argc, char ** argv){
    vector<int> vettore = {1,2,3,4,5,6,7,8,9};
    auto iter = find_if(vettore.begin(), vettore.end(), is_greater_than);
    cout << *iter << endl;

    int soglia = 5;
    // posso cambiare il valore di soglia senza modificare il codice
    iter = find_if(vettore.begin(), vettore.end(),
        [soglia](int valore)-> bool{ return valore > soglia; }
    );
    cout << *iter << endl;

    // overlapping del vettore in base ad un criterio oppure mettere in un altro vettore
    vector<int> vettore_modificato(vettore.size());
    transform(vettore.begin(), vettore.end(), vettore_modificato.begin(), [soglia](int valore){return valore * soglia;});
    for(const auto& v : vettore){
        cout << v << " ";
    }
    cout << endl;
    for(const auto& v : vettore_modificato){
        cout << v << " ";
    }
    cout << endl;

    vettore.erase(remove_if(vettore.begin(), vettore.end(), [soglia](int valore){ return valore < soglia; }), vettore.end());
    for(const auto& v : vettore){
        cout << v << " ";
    }
    cout << endl;

    vector<int> vettore_2 = {3,213,21,3123,21,3,23,12,31,24,34,65,86,7,42,4,2346,45,654};
    auto rimuovi = [&vettore_2](){
        for(auto it = vettore_2.begin(); it != vettore_2.end(); ){
            if(*it < 200){
                auto iter_da_rimuovere = it;
                //it++;
                vettore_2.erase(iter_da_rimuovere);
            }else{
                it++;
            }
        }
    };
    rimuovi();
    for(const auto& v : vettore_2){
        cout << v << " ";
    }
    cout << endl;

    list<int> lista = {543,53,5,345,34,63,6,235,346,45,75};
    auto rimuovi_2 = [&lista](){
        for(auto it = lista.begin(); it != lista.end(); ){
            if(*it < 200){
                auto iter_da_rimuovere = it;
                it++;
                lista.erase(iter_da_rimuovere);
            }else{
                it++;
            }
        }
    };
    rimuovi_2();
    for(const auto& v : lista){
        cout << v << " ";
    }
    cout << endl;

    list<int> lista_2 = {1342,3,342,342,3,3,45345,346,45,645,7,6,56,867,8,65,634,24,12};
    lista_2.remove_if([](int valore){ return valore % 2 == 0; });
    for(const auto& valore : lista_2){
        cout << valore << " ";
    }
    cout << endl;
    
    return 0;
}