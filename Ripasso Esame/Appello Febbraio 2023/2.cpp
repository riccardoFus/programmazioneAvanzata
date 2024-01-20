#include <iostream>
#include <set>
#include <map>
using namespace std;

int random(){
    return rand() % 5 + 1;
}

ostream& operator << (ostream& os, multiset<int>& d){
    os << "dati :: ";
    for(const auto& i : d){
        os << i << "; ";
    }
    return os;
}

ostream& operator << (ostream& os, map<int, int>& m){
    os << "occorenze :: ";
    for(const auto& v : m){
        os << v.first << "=>" << v.second << " ; ";
    }
    return os;
}

map<int, int> set2map(multiset<int>& d){
    map<int, int> mappa;
    for(int i = 1; i <= 5; i++){
        mappa[i] = 0;
    }
    for(const auto& v : d){
        mappa[v]++;
    }
    return mappa;
}

int main(){
    srand(time(NULL));
    multiset<int> dati;
    for(int i = 0; i < 20; i++){
        dati.insert(random());
    }
    cout << dati << endl;
    map<int, int> occ;
    occ = set2map(dati);
    cout << occ << endl;
}