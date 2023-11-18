#include <iostream>
using namespace std;

class Prova{
    private:
        int dato;
    public:
        explicit Prova(int _dato){
            cout << "Costruttore a un parametro EXPLICIT" << endl;
            dato = _dato;
        }
        Prova(const Prova& p){
            cout << "Costruttore di copia" << endl;
            dato = p.dato;
        }
        ~Prova(){
            cout << "Distruttore" << endl;
        }
        int get_dato() const{
            return dato;
        }
        friend ostream& operator << (ostream& os, const Prova& p);
};

void test(Prova p){
    cout << p.get_dato() << endl;
}

ostream& operator << (ostream& os, const Prova& p){
    os << p.dato;
    return os;
}

int main(int argc, char ** argv){
    // test(2);

    test(Prova(2));

    Prova mia_prova(4);
    test(mia_prova);

    cout << mia_prova << endl;

    return 0;
}