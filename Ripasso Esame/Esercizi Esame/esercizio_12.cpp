/*
    Considera una unordered_map<int, int>; scrivi una lambda expression che crei un vettore, una lista e un
    set di interi che contengano esattamente i valori della mappa suddetta nella posizione espressa dalla
    chiave; si gestiscano opportunamente le eccezioni nei casi in cui si dovessero rendersi nec.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>
#include <exception>
#include <stdexcept>
using namespace std;

int main(int argc, char ** argv){
    unordered_map<int, int> um;
    for(int i = 0; i < 10; i++){
        um.insert(pair<int, int>(i,i));
        um.insert(pair<int, int>(i,i));
    }

    cout << "Stampa di controllo" << endl;
    for(const auto& e : um){
        cout << "( " << e.first << ", " << e.second << " )";
    }
    cout << endl;

    auto result = [um](){
        vector<int> v(um.size());
        list<int> l;
        set<int> s;
        for(const auto& e : um){
            int val = e.second;
            int key = e.first;
            try{
                vector<int>::iterator it = v.begin() + key;
                v.insert(it, val);
            }
            catch (...){
                cout << "Vector too short" << endl;
            }
            l.push_front(val);
            try{
                s.insert(val);
            }
            catch (...){
                cout << "You tried to insert a double element in the " << val << endl;
            }
        }
        return ;
    };
    result();
}