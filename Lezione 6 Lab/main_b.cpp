// problema del diamante, abbiamo classe A -> poi B e C che sono ereditate da A -> poi c'è D che eredita da B e C -> PROBLEMA DEL DIAMANTE

#include <iostream>
#include <string>
using namespace std;

class Persona{
    private:
        string nome;
        int eta;
    public:
        Persona(string _nome, int _eta){
            nome = _nome;
            eta = _eta;
            cout << "Creata persona : " << nome << ", " << eta << endl;
        }
        Persona(){
            cout << "Creata persona default" << endl;
        }
};

class Studente: virtual public Persona{
    private:
    public:
        Studente(string _nome, int _eta): Persona(_nome, _eta){
            cout << "Creato studente : " << _nome << ", " << _eta << endl;
        }
};

class Faculty: virtual public Persona{
    private:
    public:
        Faculty(string _nome, int _eta): Persona(_nome, _eta){
            cout << "Creata faculty : " << _nome << ", " << _eta << endl;
        }
};

class TA: public Studente, public Faculty{
    private:
    public:
        TA(string _nome, int _eta): Studente(_nome, _eta), Faculty(_nome, _eta), Persona(_nome, _eta){
            cout << "Creato TA : " << _nome << ", " << _eta << endl;
        }
};

int main(int argc, char ** argv){
    // quando creo uno studente crea un'istanza di Persona
    // quando creo una facolty crea un'istanza di Persona
    // quindi io all'interno ho due istanze di Persona separate
    // se ho metodi diversi in studente e in faculty -> si potrebbe generare inconsistenza tra 
    // le due istanze di Persona 

    // mettendo virtual alle chiamate al costruttore di Persona nei costruttori di Studente e Faculty, risolvo
    // mi devo creare un'istanza di tipo Persona -> mi serve un costruttore a zero parametri da sovrascrivere
    TA ta("Riccardo", 20);
    return 0;
}