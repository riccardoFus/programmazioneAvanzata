#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void stampa1_vettore(vector<int>& vettore_da_stampare){
    vector<int>::iterator it;
    for(it = vettore_da_stampare.begin(); it != vettore_da_stampare.end() /*it < contenitore_interi.end()*/; it++){
        cout << "[" << *it << "] ";
    }
    cout << endl;
}

void stampa2_vettore(vector<int>& vettore_da_stampare){
    for(auto it = vettore_da_stampare.begin(); it != vettore_da_stampare.end(); it++){
        cout << "[" << *it << "] ";
    }
    cout << endl;
}

void stampa3_vettore(vector<int>& vettore_da_stampare){
    for(auto& it : vettore_da_stampare){
        cout << "[" << it << "] ";
    }
    cout << endl;
}

void stampa4_vettore(vector<int>& vettore_da_stampare){
    for(const auto& it : vettore_da_stampare){
        cout << "[" << it << "] ";
    }
    cout << endl;
}

void reverse_stampa_vettore1(vector<int>& vettore_da_stampare){
    reverse(vettore_da_stampare.begin(), vettore_da_stampare.end());
    for(const auto& it : vettore_da_stampare){
        cout << "[" << it << "] ";
    }
    cout << endl;
}

void reverse_stampa_vettore2(vector<int>& vettore_da_stampare){
    vector<int>::reverse_iterator riter;
    for(riter = vettore_da_stampare.rbegin(); riter != vettore_da_stampare.rend(); riter++){
        cout << "[" << *riter << "] ";
    }
    cout << endl;
}

void modifica_vettore(vector<int>& vettore_da_modificare){
    for(auto& it : vettore_da_modificare){
        ++it;
    }
}

void stampa1_lista(list<int>& lista_da_stampare){
    list<int>::iterator it;
    for(it = lista_da_stampare.begin(); it != lista_da_stampare.end(); it++){
        cout << "[" << *it << "] ";
    }
    cout << endl;
}

void stampa2_lista(list<int>& lista_da_stampare){
    for(auto it = lista_da_stampare.begin(); it != lista_da_stampare.end(); it++){
        cout << "[" << *it << "] ";
    }
    cout << endl;
}

void stampa3_lista(list<int>& lista_da_stampare){
    for(auto& it : lista_da_stampare){
        cout << "[" << it << "] ";
    }
    cout << endl;
}

void stampa4_lista(list<int>& lista_da_stampare){
    for(const auto& it : lista_da_stampare){
        cout << "[" << it << "] ";
    }
    cout << endl;
}

void modifica_lista(list<int>& lista_da_modificare){
    for(auto& it : lista_da_modificare){
        ++it;
    }
}

void reverse_stampa_lista1(list<int>& lista_da_stampare){
    // modifiche permanenti!
    reverse(lista_da_stampare.begin(), lista_da_stampare.end());
    for(const auto& it : lista_da_stampare){
        cout << "[" << it << "] ";
    }
    cout << endl;
}

void reverse_stampa_lista2(list<int>& lista_da_stampare){
    list<int>::reverse_iterator riter;
    for(riter = lista_da_stampare.rbegin(); riter != lista_da_stampare.rend(); riter++){
        cout << "[" << *riter << "] ";
    }
    cout << endl;
}

int main(int argc, char** argv){
    vector<int> vettore_interi;
    vettore_interi.push_back(23);
    vettore_interi.push_back(2);
    stampa1_vettore(vettore_interi);

    list<int> lista_interi;
    lista_interi.push_back(1);
    lista_interi.push_back(2);
    lista_interi.push_front(0);
    stampa1_lista(lista_interi);
    
    modifica_vettore(vettore_interi);
    stampa2_vettore(vettore_interi);
    stampa2_lista(lista_interi);
    modifica_lista(lista_interi);

    stampa3_vettore(vettore_interi);
    stampa3_lista(lista_interi);
    
    vector<int> v = {1,2,3,4,5};
    stampa4_vettore(v);
    stampa4_lista(lista_interi);

    reverse_stampa_vettore1(v);
    reverse_stampa_vettore2(v);

    reverse_stampa_lista1(lista_interi);
    reverse_stampa_lista2(lista_interi);

    return 0;
}