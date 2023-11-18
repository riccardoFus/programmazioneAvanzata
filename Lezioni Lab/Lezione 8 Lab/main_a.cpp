#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

void stampa_set(set<int>& set_da_stampare){
    for(auto& i : set_da_stampare){
        cout << i << " ";
    }
    cout << endl;
}

void stampa_unordered_set(unordered_set<int>& unordered_set_da_stampare){
    for(auto& i : unordered_set_da_stampare){
        cout << i << " ";
    }
    cout << endl;
}

void stampa_multiset(multiset<int>& multiset_da_stampare){
    for(auto& i : multiset_da_stampare){
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char ** argv){
    set<int> set_interi;
    set<int>::iterator set_iterator;
    set<int>::reverse_iterator set_reverse_iterator;
    int dato_rimosso;

    set_interi.insert(9);
    set_interi.insert(3);
    set_interi.insert(5);

    stampa_set(set_interi);

    // rimozione elemento
    set_iterator = set_interi.find(3);
    if(set_iterator != set_interi.end()){
        dato_rimosso = *set_iterator;
        cout << "E' stato rimosso " << dato_rimosso << endl;
        set_interi.erase(set_iterator);    
        stampa_set(set_interi);

        dato_rimosso++;
        set_interi.insert(dato_rimosso);
        stampa_set(set_interi);
    }

    for(set_reverse_iterator = set_interi.rbegin(); set_reverse_iterator != set_interi.rend(); set_reverse_iterator++){
        cout << *set_reverse_iterator << " ";
    }
    cout << endl;

    // con il set il const è di ufficio, il set di base non può essere modificato direttamente

    unordered_set<int> unordered_set_interi;

    unordered_set_interi.insert(9);
    unordered_set_interi.insert(3);
    unordered_set_interi.insert(4);

    stampa_unordered_set(unordered_set_interi);

    multiset<int> multiset_interi;

    cout << endl << endl;
    
    set_interi.clear();
    set_interi.insert(3);
    set_interi.insert(4);
    set_interi.insert(3);
    set_interi.insert(5);

    stampa_set(set_interi);

    multiset_interi.insert(3);
    multiset_interi.insert(4);
    multiset_interi.insert(3);
    multiset_interi.insert(5);

    stampa_multiset(multiset_interi);

    return 0;
}