/*
    Crea un vector<int> dato di 10 elementi e popolalo di valori compresi tra
    0 e 10 usando la funzione generate della libreria algorithm. A questo 
    punto:
        * Crea due funzioni set_pari e set_dispari che prendano in input il
        vettore nel modo opportuno; la prima deve settare a 1 i valori pari e
        la seconda deve settare a 0 i valori dispari
        * Crea due thread e usali per lanciare le due funzioni appena create;
        * Prendi le misure opportune per prevenire il data race
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx;
static vector<bool> visited(10);

int random(){
    return rand()%11;
}

void stampa_vettore(vector<int>& v){
    for(auto& value : v) cout << value << " ";
    cout << endl;
}

void set_pari(vector<int>& v){
    mtx.lock();
    for(int i = 0; i < v.size(); i++){
        if(v[i] % 2 == 0 && visited[i] == false){
            v[i] = 1;
            visited[i] = true;
        }
    }
    mtx.unlock();
}

void set_dispari(vector<int>& v){
    mtx.lock();
    for(int i = 0; i < v.size(); i++){
        if(v[i] % 2 != 0 && visited[i] == false){
            v[i] = 0;
            visited[i] = true;
        }
    }
    mtx.unlock();
}

int main(int argc, char ** argv){
    srand(time(NULL));

    vector<int> v(10);
    generate(v.begin(), v.end(), random);

    stampa_vettore(v);

    std::thread th1(set_pari, ref(v));
    std::thread th2(set_dispari, ref(v));

    th1.join();
    th2.join();

    stampa_vettore(v);
}