/*
    Questo file contiene l'esercizio su clienti e ordini
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Cliente;
class Ordine{
    private:
        int id_ordine;
        Cliente* cliente_ordine;
    public:
        Ordine(int id_ordine){
            this->id_ordine = id_ordine;
            cliente_ordine = NULL;
        }
        ~Ordine(){}
        void set_cliente(Cliente* cliente){
            cliente_ordine = cliente;
        }
        friend ostream& operator << (ostream& os, const Ordine& o);
};

ostream& operator << (ostream& os, const Ordine& o){
    os << o.id_ordine;
    return os;
}

class Cliente{
    private:
        int id_cliente;
        vector<Ordine*> vettore_ordini;
        list<Ordine> lista_ordini;
    public:
        Cliente(int id_cliente){
            this->id_cliente = id_cliente;
        }
        ~Cliente(){}
        void add_ordine_vettore(Ordine* ordine){
            vettore_ordini.push_back(ordine);
        }
        void add_ordine_lista(int id_ordine){
            Ordine o(id_ordine);
            o.set_cliente(this);
            lista_ordini.push_back(o);
        }
        friend ostream& operator << (ostream& os, const Cliente& c);
};

ostream& operator << (ostream& os, const Cliente& c){
    os << c.id_cliente << endl;
    for(auto it = c.vettore_ordini.begin(); it != c.vettore_ordini.end(); it++){
        os << *(*it) << " ";
    }
    os << endl;
    for(const auto& it : c.lista_ordini){
        os << it << " ";
    }
    return os;
}

int main(int argc, char ** argv){
    Cliente c(33);
    Ordine o1(1);
    Ordine o2(2);
    c.add_ordine_vettore(&o1);
    c.add_ordine_vettore(&o2);
    c.add_ordine_lista(3);
    cout << c << endl;
    return 0;
}