#include <iostream>
#include <string>
using namespace std;

class Persona{
    protected:
        string nome;
        int eta;
    public:
        Persona(string nome, int eta){
            this->nome = nome;
            this->eta = eta;
            cout << "Creata persona : " << nome << ", " << eta << endl;
        }
        Persona(){
            cout << "Creata persona default" << endl;
        }
};

class Studente: virtual public Persona{
    private:
    public:
        Studente(string nome, int eta): Persona(nome, eta){
            cout << "Creato studente : " << nome << ", " << eta << endl;
        }
};

class Faculty: virtual public Persona{
    private:
    public:
        Faculty(string nome, int eta): Persona(nome, eta){
            cout << "Creata faculty : " << nome << ", " << eta << endl;
        }
};

class TA: public Studente, public Faculty{
    private:
    public:
        TA(string nome, int eta): Studente(nome, eta), Faculty(nome, eta), Persona(nome, eta){
            cout << "Creato TA : " << nome << ", " << eta << endl;
            cout << this->nome << endl;
        }
};

int main(int argc, char ** argv){
    TA ta("Riccardo", 20);
    return 0;
}