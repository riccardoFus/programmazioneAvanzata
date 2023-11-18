#include <iostream>
#include <fstream>
using namespace std;

class A{
    private:
        int dato;
        const float costante;
        static int numero_istanze;
        static const int pi_greco_intero;
        static const float pi_greco_float;
    public:
        A(): costante(0.0){
            cout << "Costruttore a zero parametri" << endl;
            dato = 0;
            ++numero_istanze;
        }
        A(int _dato): dato(_dato), costante(2.2){
            cout <<"Costruttore ad un parametro" << endl;
            ++numero_istanze;
        }
        ~A(){
            cout << "Distruttore" << endl;
            --numero_istanze;
            ofstream file;
            file.open("numero_istanze_log.txt", ios::app);
            file << "Numero di istanze attuale : " << numero_istanze << endl;
            file.close();
        }
        static int get_numero_istanze(){
            return numero_istanze;
        }
        friend ostream& operator << (ostream& os, const A& a);
};

int A::numero_istanze = 0;
const int A::pi_greco_intero = 3;
const float A::pi_greco_float = 3.14;

ostream& operator << (ostream& os, const A& a){
    os << "Dato = " << a.dato << "\nCostante = " << a.costante << "\nNumero di istanze attive = " << a.get_numero_istanze();
    return os;
}

int main(int argc, char ** argv){
    int dato_istanziato_inizializzato = 3;
    int dato_inizializzato_automaticamente(4);

    cout << "Numero di istanze attive: " << A::get_numero_istanze() << endl;
    A a_1;
    cout << a_1 << endl;
    A a_2(2);
    cout << a_2 << endl;
    return 0;
}