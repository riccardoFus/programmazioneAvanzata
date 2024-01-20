/*
    Questo file contiene:
    1) Ereditarietà
    2) Late binding
*/
#include <iostream>
#include <string>
using namespace std;

class Persona{
    protected:
        string nome, cognome;
    public:
        Persona(string nome, string cognome){
            this->nome = nome;
            this->cognome = cognome;
        }
        virtual ~Persona(){
            cout << "Persona::~Persona" << endl;
        }
        virtual void stampa() const{
            cout << nome << " " << cognome << endl;
        }
        virtual ostream& stampa_operator(ostream& os) const{
            os << nome << " " << cognome;
            return os;
        }
        friend ostream& operator << (ostream& os, const Persona& p);
};

ostream& operator << (ostream& os, const Persona& p){
    return p.stampa_operator(os);
}

class Studente: public Persona{
    private:
        int matricola;
    public:
        Studente(int matricola, string nome, string cognome): Persona(nome, cognome){
            this->matricola = matricola;
        }
        ~Studente(){
            cout << "Studente::~Studente" << endl;
        }
        void stampa() const{
            cout << nome << " " << cognome << " " << matricola << endl;
        }
        ostream& stampa_operator(ostream& os) const{
            os << nome << " " << cognome << " " << matricola;
            return os;
        }
        friend ostream& operator << (ostream& os, const Studente& s);
};

ostream& operator << (ostream& os, const Studente& s){
    return s.stampa_operator(os);
}

int main(){
    Persona persona_statico("Riccardo", "Fusiello");
    cout << persona_statico << endl;
    persona_statico.stampa();
    Studente studente_statico(123456, "Michele", "Misseri");
    cout << studente_statico << endl;
    studente_statico.stampa();

    // Forziamo il late binding
    Persona* puntatore_persona;
    puntatore_persona = new Persona("Mimmo", "Berardi");
    cout << *puntatore_persona << endl;
    delete puntatore_persona;

    puntatore_persona = new Studente(123456, "Nome", "Cognome");
    puntatore_persona->stampa();
    cout << *puntatore_persona << endl;
    puntatore_persona->Persona::stampa();
    delete puntatore_persona;
}