#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
using namespace std;

void stampaVec(const vector<int>& vec){
    cout << "[ ";
    for(const auto& v : vec){
        cout << v << " ";
    }
    cout << "]" << endl;
}

vector<int> ordina(const vector<int>& v, string modo){
    vector<int> vec_ordinato(v.size());
    copy(v.begin(), v.end(), vec_ordinato.begin());
    if(modo == "CRE"){
        sort(vec_ordinato.begin(), vec_ordinato.end());
    }else if(modo == "DEC"){
        sort(vec_ordinato.begin(), vec_ordinato.end(), [](const int& x, const int& y){
            return x > y;
        });
    }
    return vec_ordinato;
}

int main(){
    vector<int> vec(10);
    iota(vec.begin(), vec.end(), 1);
    shuffle(vec.begin(), vec.end(), default_random_engine());
    stampaVec(vec);
    vec.erase(remove_if(vec.begin(), vec.end(), [](const int& x){ return x < 4; }), vec.end());
    stampaVec(vec);
    vector<int> vec_ordinato = ordina(vec, "CRE");
    stampaVec(vec_ordinato);
    return 0;
}