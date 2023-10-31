#include <iostream>
using namespace std;

class Studente{
    private:
        int dato_studente;
    public:
        Studente(int dato_studente){
            this->dato_studente = dato_studente;
            cout << "Creato studente" << endl;
        }
        ~Studente(){
            cout << "Distrutto studente" << endl;
        }
        void stampa() const{
            cout << "Dato studente: " << dato_studente << endl;
        }
};

class Lavoratore{
    private:
        int dato_lavoratore;
    public:
        Lavoratore(int dato_lavoratore){
            this->dato_lavoratore = dato_lavoratore;
            cout << "Creato lavoratore" << endl;
        }
        ~Lavoratore(){
            cout << "Distrutto lavoratore" << endl;
        }
        void stampa() const{
            cout << "Dato lavoratore: " << dato_lavoratore << endl;
        }
};

class Studente_Lavoratore: public Studente, public Lavoratore{
    private:
    public:
        Studente_Lavoratore(int dato_studente, int dato_lavoratore): Studente(dato_studente), Lavoratore(dato_lavoratore){
            cout << "Creato studente lavoratore" << endl;
        }
        ~Studente_Lavoratore(){
            cout << "Distrutto studente lavoratore" << endl;
        }
};

int main(int argc, char ** argv){
    Studente studente(150);

    Lavoratore lavoratore(200);

    Studente_Lavoratore studente_lavoratore(300, 400);

    studente_lavoratore.Studente::stampa();
    
    studente_lavoratore.Lavoratore::stampa();
}