#include <iostream>
#include <string>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

class Albero{
    private:
        string tipo;
        int altezza;
    public:
        Albero(string t, int a): tipo(t), altezza(a){}
        Albero(const Albero& a): tipo(a.tipo), altezza(a.altezza){}
        ~Albero(){}
        int get_altezza() const{ return altezza; }
        friend ostream& operator << (ostream& os, const Albero& a);
};

ostream& operator << (ostream& os, const Albero& a){
    os << a.tipo << " " << a.altezza;
    return os;
}

bool is_lt_10(const Albero& a){
    return a.get_altezza() < 10;
}

int main(){
    map<int, list<Albero>> alberi;
    alberi[0].push_back(Albero("Quercia", 10));
    alberi[1].push_back(Albero("Pino", 5));
    alberi[2].push_back(Albero("Quercia", 14));
    for(const auto& it : alberi){
        cout << "Chiave : " << it.first << endl;
        for(const auto& it2 : it.second){
            cout << it2 << endl;
        }
    }
    cout << endl << endl;
    for(auto& it : alberi){
        it.second.erase(remove_if(it.second.begin(), it.second.end(), is_lt_10), it.second.end());
    }
    for(const auto& it : alberi){
        cout << "Chiave : " << it.first << endl;
        for(const auto& it2 : it.second){
            cout << it2 << endl;
        }
    }
}