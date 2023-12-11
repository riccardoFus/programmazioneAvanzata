/*
    Crea una classe Alpaca. Un Alpaca ha un nome, eta e razza. Tuttavia gli alpaca sono animali riservati
    e quindi certe informazioni le vogliono tenere private.
    Crea Allevamento che ha una lista di Alpaca*. Creati un costruttore per gli Alpaca a cui passi tutto il nec.
    Crea una classe Allevatore, pure vuota.
    Nel main crea una mappa<Allevatore, Allevamento>, in questa devi inserire due allevatori e due allevamenti (uno a testa)
    Crea una lista di alpaca, devono essere 7.
    Con una lambda cattura la lista di alpaca e assegna quelli in posizione pari ad un allevatore e quelli in posizione dispari
    all'altro; per fare questo devi accedere al record della mappa e da lì devi aggiungere l'alpaca alla lista dell'allevamento
    dell'allevatore
*/

#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <string>
using namespace std;

class Alpaca{
    private:
        string nome, razza;
        int eta;
    public:
        Alpaca(string n, int e, string r): nome(n), eta(e), razza(r){ cout << "Creato Alpaca" << endl; }
        ~Alpaca(){ cout << "Alpaca ucciso :(" << endl; }
        bool operator == (const Alpaca& a){
            return (nome == a.nome && eta == a.eta && razza == a.razza);
        }
        friend ostream& operator << (ostream& os, const Alpaca& a);
};

ostream& operator << (ostream& os, const Alpaca& a){
    os << a.nome << " di eta' " << a.eta << ", di razza " << a.razza;
    return os;
}

class Allevamento{
    private:
        list<Alpaca*> lista_alpaca;
    public:
        Allevamento(){ cout << "Creato Allevamento" << endl; }
        ~Allevamento(){ cout << "Distrutto Allevamento" << endl; }
        void add_alpaca(Alpaca* a){ lista_alpaca.push_back(a); }
        friend ostream& operator << (ostream& os, const Allevamento& a);
};

ostream& operator << (ostream& os, const Allevamento& a){
    os << "Allevamento:" << endl;
    for(auto& alpaca : a.lista_alpaca){
        os << "\t" << *alpaca << endl;
    }
    return os;
}

class Allevatore{
    private:
        int id;
    public:
        Allevatore(int id){
            this->id = id;
        }
        bool operator < (const Allevatore& a) const{
            return id < a.id;
        }
};

int main(int argc, char ** argv){
    Allevatore allevatore_1(0), allevatore_2(1);
    map<Allevatore, Allevamento> mappa;
    mappa[allevatore_1] = Allevamento();
    mappa[allevatore_2] = Allevamento();
    list<Alpaca> lista_alpaca;
    lista_alpaca.push_back(Alpaca("Michele", 0, "Razza0"));
    lista_alpaca.push_back(Alpaca("Luca", 1, "Razza1"));
    lista_alpaca.push_back(Alpaca("Walter", 2, "Razza2"));
    lista_alpaca.push_back(Alpaca("Gertrude", 3, "Razza3"));
    lista_alpaca.push_back(Alpaca("Carmen", 4, "Razza4"));
    lista_alpaca.push_back(Alpaca("Leo", 5, "Razza5"));
    lista_alpaca.push_back(Alpaca("Riccardo", 6, "Razza6"));
    for_each(lista_alpaca.begin(), lista_alpaca.end(), [&lista_alpaca, &mappa, &allevatore_1, &allevatore_2](Alpaca& a){
        int index = distance(find(lista_alpaca.begin(), lista_alpaca.end(), a), lista_alpaca.begin());
        if(index % 2 == 0){
            mappa[allevatore_1].add_alpaca(&a);
        }else{
            mappa[allevatore_2].add_alpaca(&a);
        }
    });
    for(auto v : mappa){
        cout << v.second << endl;
    }
    return 0;
}