/*
    Crea una classe Pinguino che deve avere gli attributi numero_zampe, eta e nome in seguito sovrascivi
    i meotdi di tale classe in modo da ottenere che:
        * se sommi due pinguini ottieni un terzo pinguino con eta 0 e numero di zampe la somma
        * un pinguino con più zampe è maggiore di un pinguino con meno zampe
        * il preincremento e il post incremento funzionano come con gli interi, ritornano un pinguino e ne aumentano il numero di zampe
        * un pinguino deve poter essere usato come funzione che ritorna void e prende come input una stringa cibo; la funzione deve stampare a video "Il pinguino Joe ha
        * mangiato una focaccia"
*/

#include <iostream>
#include <string>
using namespace std;

class Pinguino{
    private:
        int numero_zampe, eta;
        string nome;
    public:
        Pinguino(int numero_zampe, int eta, string nome){
            this->numero_zampe = numero_zampe;
            this->eta = eta;
            this->nome = nome;
        }
        Pinguino(const Pinguino& pinguino){
            this->numero_zampe = pinguino.numero_zampe;
            this->eta = pinguino.eta;
            this->nome = pinguino.nome;
        }
        Pinguino operator + (const Pinguino& pinguino) const{
            return Pinguino(this->numero_zampe + pinguino.numero_zampe, 0, "Michele");
        }
        bool operator < (const Pinguino& pinguino) const{
            return this->numero_zampe < pinguino.numero_zampe;
        }
        Pinguino& operator ++ (){
            ++this->numero_zampe;
            return (*this);
        }
        Pinguino operator ++ (int){
            Pinguino tmp(*this);
            this->numero_zampe++;
            return tmp;
        }
        void operator()(const string &cibo){
            cout << "Il pinguino " << this->nome << " ha mangiato " << cibo << endl;
        }
};

int main(int argc, char** argv){
    Pinguino pinguino_1(2, 4, "Riccardo");
    Pinguino pinguino_2(2, 3, "Gertrude");

    Pinguino pinguino_3 = pinguino_1 + pinguino_2;

    cout << (bool)(pinguino_1 < pinguino_2) << endl;
    pinguino_2++;
    cout << (bool)(pinguino_1 < pinguino_2) << endl;

    pinguino_1("la merda");
}