/*
    Ereditarietà multipla: quando una classe eredita da due o più classi contemporaneamente.
    In C++ è possibile, può generare ambiguità.
*/
#include <iostream>
using namespace std;

class Studente{
    private:
        int datoStudente;
    public:
        Studente(int _datoStudente){ 
            datoStudente = _datoStudente; 
            cout << "Creato studente" << endl;
        }
        ~Studente(){ cout << "Distrutto studente" << endl; }
        void stampa() const {
            cout << "datoStudente = " << datoStudente << endl;
        }
};

class Lavoratore{
    private:
        int datoLavoratore;
    public:
        Lavoratore(int _datoLavoratore){ 
            datoLavoratore = _datoLavoratore; 
            cout << "Creato Lavoratore" << endl;
        }
        ~Lavoratore(){ cout << "Distrutto lavoratore" << endl; }
        void stampa() const {
            cout << "datoLavoratore = " << datoLavoratore << endl;
        }
};

class StudenteLavoratore : public Studente, public Lavoratore {
    private:
    public:
        // nel codice del prof c'è la versione con 0 param -> 0 param = non serve richiamare il costruttore
        StudenteLavoratore(int _datoStudente, int _datoLavoratore):Studente(_datoStudente), Lavoratore(_datoLavoratore){
            cout << "Creato studente lavoratore" << endl;
        }
        ~StudenteLavoratore(){
            cout << "Distrutto studente lavoratore" << endl;
        }
};

int main(int argc, char ** argv){
    Studente s(150);
    // s.stampa();
    Lavoratore l(200);
    // l.stampa();
    StudenteLavoratore sl(300, 400);
    // crea prima studente -> poi lavoratore -> poi studente lavoratore
    // non ne esce fuori il compilatore -> o lo ricreo oppure richiamo lo scope del padre
    // sl.stampa(); errore
    sl.Studente::stampa();
    sl.Lavoratore::stampa();
    return 0;
}