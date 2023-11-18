#include <iostream>
#include <map>
#include <string>
#include <list>
using namespace std;

class Dati{
    private:
        static int id_dato;
        int id;
        list<int> valori;
    public:
        Dati(){
            id = id_dato++;
            cout << "Costruttore" << endl;
        }
        Dati(int id){
            this->id = id;
            cout << "Costruttore con parametro" << endl;
        }  
        ~Dati(){
            cout << "Distruttore" << endl;
        }
        void addAggiungereValore(int valore){
            valori.push_back(valore);
        }
        int get_id() const{
            return id;
        }
        bool operator < (const Dati& dato) const{
            return this->id < dato.id;
        }
        friend ostream& operator << (ostream& os, const Dati& dati);
};

int Dati::id_dato = 0;

ostream& operator << (ostream& os, const Dati& dati){
    os << dati.id << " = ";
    for(auto& valore : dati.valori){
        os << valore << " ";
    }
    return os;
}

int random(int min, int max){
    return rand() % (max - min + 1) + min;
}

int main(int argc, char ** argv){
    srand(time(NULL));
    /*
        map<list<int>, int> mappa_interi;
        set<list<int>> set_lista_interi;
    */
    map<int, Dati> mappa_dati;
    // Dati d1(1), d2(2), d3(1); NO, basta mettere l'indice i come chiave, oppure attributo statico comune a tutte che si incrementa
    // Dati d1, d2, d3;
    // cout << d1.get_id() << endl;

    // N.B : va di 2 in 2 perché creo una copia
    /*
        for(int i = 0; i < 5; i++){
            Dati d;
            d.addAggiungereValore(i + 0);
            d.addAggiungereValore(i + 1);
            d.addAggiungereValore(i + 2);
            // mappa_dati[d.get_id()] = d; costruttore copia, a 2 a 2
            mappa_dati.insert(pair<int, Dati>(d.get_id(), d)); // corretto
        }
    */

    for(int i = 0; i < 5; i++){
        mappa_dati[i] = Dati(i);
    }

    for(auto& chiavi : mappa_dati){
        chiavi.second.addAggiungereValore(random(-100, 100));
        chiavi.second.addAggiungereValore(random(-100, 100));
    }

    for(auto& it : mappa_dati){
        cout << "Chiave : " << it.first << ", Valore : " << it.second << endl;
    }
    
    map<Dati, int> mappa_interi;
    mappa_interi[Dati(5)] = 99;
    mappa_interi[Dati(6)] = 104;
    mappa_interi[Dati(2)] = 11;
    for(auto& it : mappa_interi){
        cout << it.first << " " << it.second << endl;
    }

    list<Dati> lista_dati;
    map<int, Dati*> mappa_1;
    map<string, Dati*> mappa_2;

    return 0;
}