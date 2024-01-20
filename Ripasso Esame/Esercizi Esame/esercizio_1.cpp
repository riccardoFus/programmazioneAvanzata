/*
    Crea un vettore di interi positivi e negativi, inizializzalo random con 20 numeri nel range
    [-50, 50]. Utilizza poi le funzioni della libreria <algorithm> e stampa i seguenti risultati
    (stampa true la condizione è verificata, false altrimenti)
        * se il vettore contiene almeno un positivo
        * se il vettore contiene solo positivi
        * se il vettore non contiene alcun positivo
        * se nei primi tre valori del vettore c'è almeno un positivo
*/

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;
static const int MAX = 50;
static const int MIN = -50;
static const int RANGE = MAX - MIN + 1;
static const int DIM = 20;

void popola_vettore(vector<int>& vettore){
    for(int i = 0; i < vettore.size(); i++){
        // rand() % 100 - 50
        vettore[i] = rand() % RANGE + MIN;
    }
}

void stampa_vettore(vector<int>& vettore){
    for(auto& elemento : vettore){
        cout << "[" << elemento << "] ";
    }
    cout << endl;
}

bool is_positive(int elemento){
    return elemento >= 0;
}

void copia_primi_tre_elementi(vector<int>& vettore_da_copiare, vector<int>& vettore_copiato){
    for(int i = 0; i < 3; i++){
        vettore_copiato.push_back(vettore_da_copiare[i]);
    }
}

int main(int argc, char ** argv){
    srand(time(NULL));
    
    vector<int> vettore(DIM);
    popola_vettore(vettore);
    stampa_vettore(vettore);

    if(any_of(vettore.begin(), vettore.end(), is_positive)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    if(all_of(vettore.begin(), vettore.end(), is_positive)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    if(none_of(vettore.begin(), vettore.end(), is_positive)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    /*
    vector<int> vettore_primi_tre_elementi;
    copia_primi_tre_elementi(vettore, vettore_primi_tre_elementi);
    stampa_vettore(vettore_primi_tre_elementi);
    if(any_of(vettore_primi_tre_elementi.begin(), vettore_primi_tre_elementi.end(), is_positive)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    */

   vector<int>::iterator iteratore_terza_posizione = ++(++(++vettore.begin()));
   if(any_of(vettore.begin(), iteratore_terza_posizione, is_positive)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    return 0;
}