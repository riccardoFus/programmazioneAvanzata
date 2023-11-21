#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
using namespace std;

class Giardino{
    private:
        string nome, localita;
        int estensione;
    public:
        Giardino(string nome, int estensione, string localita){
            this->nome = nome;
            this->estensione = estensione;
            this->localita = localita;
        }
        int get_estensione() const {
            return estensione;
        }
        friend ostream& operator << (ostream& os, const Giardino& g);
};

ostream& operator << (ostream& os, const Giardino& g){
    os << "Nome Giardino : " << g.nome << endl;
    os << "Estensione [mq] : " << g.estensione << endl;
    os << "Localita : " << g.localita;
    return os;
}

bool under_120(const Giardino& g){
    return g.get_estensione() < 120;
}

int main(){
    map<int, list<Giardino>> dato;
    map<int, list<Giardino>>::iterator mit;
    list<Giardino>::iterator vit;

    dato[1].push_back(Giardino("G1", 100, "L1"));
    dato[2].push_back(Giardino("G2", 200, "L2"));
    dato[3].push_back(Giardino("G3", 300, "L3"));

    for(mit = dato.begin(); mit != dato.end(); mit++){
        mit->second.remove_if(under_120);
    }
    cout << "Rimozione da lista" << endl;

    for(mit = dato.begin(); mit != dato.end(); mit++){
        for(vit = mit->second.begin(); vit != mit->second.end(); vit++){
            cout << *vit << endl;
        }
    }

    map<int, vector<Giardino>> dato2;
    map<int, vector<Giardino>>::iterator mit2;
    vector<Giardino>::iterator vit2;

    dato2[1].push_back(Giardino("G1", 100, "L1"));
    dato2[2].push_back(Giardino("G2", 200, "L2"));
    dato2[3].push_back(Giardino("G3", 300, "L3"));
    
    for(mit2 = dato2.begin(); mit2 != dato2.end(); mit2++){
        mit2->second.erase(
            remove_if(mit2->second.begin(), mit2->second.end(), under_120),
            mit2->second.end()
        );
    }
    cout << "Rimozione da vector" << endl;

    for(mit2 = dato2.begin(); mit2 != dato2.end(); mit2++){
        for(vit2 = mit2->second.begin(); vit2 != mit2->second.end(); vit2++){
            cout << *vit2 << endl;
        }
    }
    return 0;
}