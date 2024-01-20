/*
    Questo file contiene le prime tre lezioni di laboratorio accorpate in una,
    in particolare comprendono: 
    1) Classe Standard + metodi standard + stampa
    2) Explicit + static/const/static const
    3) Overloading operatori + riferimento incrociato per operator ==
*/
#include <iostream>
#include <string>
using namespace std;

class B;
class Persona{
    private:
        string nome, cognome;
        int eta;
        int *vettore_dinamico;
        const float costante;
        static int statico;
        static const int statico_costante;
    public:
        Persona(): costante(0.0){
            nome = "Riccardo";
            cognome = "Fusiello";
            eta = 21;
            vettore_dinamico = NULL;
            statico++;
        }
        Persona(string n, string c, int e = 0): costante(1.0){
            nome = n;
            cognome = c;
            eta = e;
            vettore_dinamico = new int [5];
            for(int i = 0; i < 5; i++){
                vettore_dinamico[i] = i*i;
            }
            statico++;
        }
        /*
        // evitiamo la conversione implicita del costruttore
        explicit Persona(string n){
            nome = n;
            cognome = "Anonimo";
            eta = "-1";
            vettore_dinamico = NULL;
        }
        */
        Persona(const Persona& p): costante(p.costante){
            nome = p.nome;
            cognome = p.cognome;
            eta = p.eta;
            if(p.vettore_dinamico != NULL){
                vettore_dinamico = new int[5];
                for(int i = 0; i < 5; i++){
                    vettore_dinamico[i] = p.vettore_dinamico[i];
                }
            }else{
                vettore_dinamico = NULL;
            }
            statico++;
        }
        ~Persona(){
            if(vettore_dinamico != NULL){
                delete[] vettore_dinamico;
                vettore_dinamico = NULL;
            }
            statico--;
        }
        Persona& operator = (const Persona& p){
            nome = p.nome;
            cognome = p.cognome;
            eta = p.eta;
            if(p.vettore_dinamico != NULL){
                if(vettore_dinamico == NULL){
                    vettore_dinamico = new int[5];
                }
                for(int i = 0; i < 5; i++){
                    vettore_dinamico[i] = p.vettore_dinamico[i];
                }
            }else{
                if(vettore_dinamico != NULL){
                    delete[] vettore_dinamico;
                    vettore_dinamico = NULL;
                }
            }
            statico++;
            return *this;
        }
        Persona operator + (const Persona& p) const{
            Persona temp;
            temp.eta = eta + p.eta;
            return temp;
        }
        Persona& operator += (const Persona& p){
            eta += p.eta;
            return *this;
        }
        Persona& operator ++ (){
            eta++;
            return *this;
        }
        Persona operator ++ (int){
            Persona temp(*this);
            eta++;
            return temp;
        }
        Persona& operator -- (){
            eta--;
            return *this;
        }
        Persona operator -- (int){
            Persona temp(*this);
            eta--;
            return temp;
        }
        bool operator == (const Persona& p) const{
            return (eta == p.eta);
        }
        bool operator != (const Persona& p) const{
            return !(*this == p);
        }
        bool operator == (const B& b) const{ return true; }
        static int get_numero_istanze(){ return statico; }
        /*
        void stampa() const{
            cout << nome << " " << cognome << " di eta': " << eta << endl;
            if(vettore_dinamico != NULL){
                cout << "[";
                for(int i = 0; i < 5; i++){
                    cout << vettore_dinamico[i] << " ";
                }
                cout << "]" << endl;
            }
        }
        */
        friend ostream& operator << (ostream& os, const Persona& p);
        friend bool operator == (const B& b, const Persona& p);
    protected:
};

class B{
    public:
        friend bool operator == (const B& b, const Persona& p);
        friend Persona;
};

bool operator == (const B& b, const Persona& p){ return true; }

int Persona::statico = 0;
const int Persona::statico_costante = 10;

// void stampa_con_copia(const Persona p){}
// void stampa_con_puntatore(const Persona* p){}
// void stampa_con_riferimento(const Persona& p){}
ostream& operator << (ostream& os, const Persona& p){
    os << p.nome << " " << p.cognome << " di eta': " << p.eta << endl;
    if(p.vettore_dinamico != NULL){
        os << "[";
        for(int i = 0; i < 5; i++){
            os << " " << p.vettore_dinamico[i] << " ";
        }
        os << "]" << endl;
    }
    os << p.costante << " " << p.statico << " " << p.statico_costante;
    return os;
}

int main(int argc, char ** argv){
    Persona p1;
    cout << p1 << endl;
    Persona p2("Michele", "Salvemini", 18);
    cout << p2 << endl;
    Persona p3(p1);
    cout << p3 << endl;
    Persona* p4 = new Persona(p2);
    cout << *p4 << endl;
    delete p4;
    cout << p3 << endl;
    cout << Persona::get_numero_istanze() << " = " << p3.get_numero_istanze() << endl;
    Persona p5 = p3;
    cout << p5 << endl;
    Persona p6 = p1 + p3;
    cout << p6 << endl;
    Persona p7;
    p7 += p2;
    cout << p7 << endl;
    cout << ++p7 << endl;
    cout << p7++ << endl;
    cout << p7 << endl;
    return 0;
}