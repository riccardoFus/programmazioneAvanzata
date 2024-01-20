/*
    Questo file contiene:
    1) libreria <algorithm>
    2) lambda expressions
*/
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
    return x*y;
}

bool compare_ascending(const int& first, const int& second){
    return first < second;
}

bool compare_descending(const int& first, const int& second){
    return first > second;
}

int random(){
    return rand()%101;
}

bool is_even(int n){
    return (n % 2 == 0);
}

int main(){
    vector<int> s;
    s.push_back(11);
    s.push_back(22);
    s.push_back(33);
    s.push_back(44);
    s.push_back(55);
    s.push_back(66);

    for_each(s.begin(), s.end(), &stampa);
    cout << endl;

    for_each(s.begin(), s.begin() + 3, &stampa);
    cout << endl;

    vector<int> v(15);
    iota(v.begin(), v.end(), 4);
    for_each(v.begin(), v.end(), &stampa);
    cout << endl;

    vector<int> v_copia(7);
    copy(v.begin(), v.begin()+7, v_copia.begin());
    for_each(v_copia.begin(), v_copia.end(), [](const int& x){cout << x << " ";});
    cout << endl;

    cout << "Sum : " << accumulate(v_copia.begin(), v_copia.end(), 0) << endl;
    cout << "Prod : " << accumulate(v_copia.begin(), v_copia.end(), 1, [](int x, int y){return x * y;}) << endl;

    sort(v_copia.rbegin(), v_copia.rend());
    for_each(v_copia.begin(), v_copia.end(), &stampa);
    cout << endl;

    list<int> l = {0, 2, 5, 6, 1, 6};
    l.sort(compare_ascending);
    for(const auto& v : l){
        cout << v << " ";
    }
    cout << endl;
    l.sort(compare_descending);
    for(const auto& v : l){
        cout << v << " ";
    }
    cout << endl;

    shuffle(v.begin(), v.end(), default_random_engine());
    for_each(v.begin(), v.end(), &stampa);
    cout << endl;

    list<int> lista = {0, 1, 0, 1, 0, 1, 0, 1};
    vector<int> temp(lista.begin(), lista.end());
    random_shuffle(temp.begin(), temp.end());
    copy(temp.begin(), temp.end(), lista.begin());
    for(auto& v : lista){
        cout << v << " ";
    }
    cout << endl;

    list<bool> lista_pari(v.size());
    transform(v.begin(), v.end(), lista_pari.begin(), is_even);
    for_each(v.begin(), v.end(), &stampa);
    cout << endl;
    for_each(lista_pari.begin(), lista_pari.end(), &stampa);
    cout << endl;
    list<int> lista_maggiore_dieci(v.size());
    transform(v.begin(), v.end(), lista_maggiore_dieci.begin(), 
    [](const int& x){
        return x > 10 ? x : 0;
    });
    for_each(lista_maggiore_dieci.begin(), lista_maggiore_dieci.end(), &stampa);
    cout << endl;

    v.erase(remove_if(v.begin(), v.end(), is_even), v.end());
    for_each(v.begin(), v.end(), &stampa);
    cout << endl;
    return 0;
}