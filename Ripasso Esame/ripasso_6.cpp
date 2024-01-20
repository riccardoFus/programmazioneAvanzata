/*
    Questo file contiene l'esercizio del gruppo di Persone
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Persona{
    private:
        string nome;
    public:
        Persona(){
            nome = "Michele";
        }  
        Persona(string nome){
            this->nome = nome;
        }
        Persona(const Persona& p){
            this->nome = p.nome;
        }
        ~Persona(){}
        bool operator < (const Persona& p) const {
            return this->nome < p.nome;
        }
        friend ostream& operator << (ostream& os, const Persona& p);
};

ostream& operator << (ostream& os, const Persona& p){
    os << p.nome;
    return os;
}

class Gruppo{
    private:
        set<Persona> set_persona;
        set<Persona*> set_puntatori_persona;
    public:
        Gruppo(){}
        ~Gruppo(){}
        // sbagliati 1 e 2
        void add_persona1(Persona p){};
        void add_persona2(const Persona& p){};
        void add_persona3(string nome){
            Persona p(nome);
            set_persona.insert(p);
        }
        void add_persona4(Persona* p){
            set_puntatori_persona.insert(p);
        }
        friend ostream& operator << (ostream& os, const Gruppo& g);
        void remove_persona(string nome){
            set<Persona>::iterator it;
            it = set_persona.find(Persona(nome));
            if(it != set_persona.end()){
                set_persona.erase(it);
            }
        }
};

ostream& operator << (ostream& os, const Gruppo& g){
    for(const auto& i : g.set_persona){
        os << i << " ";
    }
    os << endl;
    for(const auto& i : g.set_puntatori_persona){
        os << *i << " ";
    }
    return os;
}

int main(int argc, char ** argv){
    Gruppo gruppo;
    gruppo.add_persona3("Anna");
    gruppo.add_persona3("Michele");
    gruppo.add_persona3("Riccardo");

    cout << gruppo << endl;

    gruppo.remove_persona("Anna");
    
    cout << gruppo << endl;

    Persona p_1("Mirko");
    Persona p_2("Caio");
    gruppo.add_persona4(&p_1);
    gruppo.add_persona4(&p_2);

    cout << gruppo << endl;

    return 0;
}