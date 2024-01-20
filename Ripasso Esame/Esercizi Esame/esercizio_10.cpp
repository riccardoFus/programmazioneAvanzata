/*
    Supponi di avere un vettore di interi casuali positivi (inventalo);
    crea una funzione booleanizzazione che ricevi in input il vettore e ne sostituisca ogni
    elemento con 0 oppure 1, a seconda che sia rispettivamente pari o dispari, utilizzare
    lambda expression
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void booleanizzazione(vector<int>& v){
    transform(v.begin(), v.end(), v.begin(), [](int value){ return value % 2 == 0 ? 0 : 1; });
}

int random(){
    return rand() % 1000 + 1;
}

int main(int argc, char ** argv){
    srand(time(NULL));
    vector<int> v;
    for(int i = 0; i < 20; i++){
        v.push_back(random());
    }
    for(const auto& value : v){
        cout << value << " ";
    }
    cout << endl;
    booleanizzazione(v);
    for(const auto& value : v){
        cout << value << " ";
    }
    cout << endl;
    return 0;
}