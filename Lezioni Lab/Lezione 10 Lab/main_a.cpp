#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <random>
using namespace std;

void stampa(int i){
    cout << i << " ";
}

int my_function(int x, int y){
    return x * y;
}

bool compare_ascending(const int& first, const int& second){
    return first < second;
}

bool compare_descending(const int& first, const int& second){
    return first > second;
}

int random(){
    return rand() % 101;
}

bool is_even(int n){
    return (n % 2 == 0);
}

int main(int argc, char ** argv){
    vector<int> s;
    s.push_back(11);
    s.push_back(22);
    s.push_back(33);
    s.push_back(44);

    // definiamo esplicitamente l'inizio e la fine dell'intervallo
    for_each(s.begin(), s.end(), &stampa);
    cout << endl;

    for_each(s.begin(), s.begin()+3, &stampa);
    cout << endl;

    vector<int> v(15);
    iota(v.begin(), v.end(), 4);
    for_each(v.begin(), v.end(), &stampa);
    cout << endl;

    vector<int> v_copia(7);
    copy(v.begin(), v.begin()+7, v_copia.begin());
    for_each(v_copia.begin(), v_copia.end(), &stampa);
    cout << endl;

    cout << "Sum : " << accumulate(v_copia.begin(), v_copia.end(), 0) << endl;
    cout << "Prod : " << accumulate(v_copia.begin(), v_copia.end(), 1, my_function) << endl;

    sort(v_copia.rbegin(), v_copia.rend());
    for_each(v_copia.begin(), v_copia.end(), &stampa);
    cout << endl;

    list<int> l = { 0, 2, 5, 6, 1, 5};
    l.sort(compare_descending);
    for(auto& value : l){
        cout << value << " ";
    }
    cout << endl;
    
    l.sort(compare_ascending);
    for(auto& value : l){
        cout << value << " ";
    }
    cout << endl;

    shuffle(v.begin(), v.end(), default_random_engine());
    for_each(v.begin(), v.end(), &stampa);
    cout << endl;

    list<int> lista = {0,1,0,1,0,1,0,1};
    vector<int> temp(lista.begin(), lista.end());
    random_shuffle(temp.begin(), temp.end());
    copy(temp.begin(), temp.end(), lista.begin());
    for(auto& value : lista){
        cout << value << " ";
    }
    cout << endl;

    list<bool> lista_pari(v.size());
    transform(v.begin(), v.end(), lista_pari.begin(), is_even);
    for_each(v.begin(), v.end(), &stampa);
    cout << endl;
    for_each(lista_pari.begin(), lista_pari.end(), &stampa);
    cout << endl;
    cout << count_if(v.begin(), v.end(), is_even) << endl;
    auto it = find_if(v.begin(), v.end(), is_even);
    cout << "First even number : " << *it << endl;

    // rimuove il primo elemento pari
    v.erase(remove_if(v.begin(), v.end(), is_even));
    for_each(v.begin(), v.end(), &stampa);
    cout << endl;

    // rimuovo tutti gli elementi pari
    auto iter = remove_if(v.begin(), v.end(), is_even);
    v.erase(iter, v.end());
    for_each(v.begin(), v.end(), &stampa);
    cout << endl;
}