/*
    Questo file contiene:
    1) Ereditarietà multipla
    2) Eccezioni
*/

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Studente{
    private:
        int dato_studente;
    public:
        Studente(int dato): dato_studente(dato){}
        ~Studente(){};
        void stampa() const{
            cout << "Dato studente : " << dato_studente << endl;
        }
};
class Lavoratore{
    private:
        int dato_lavoratore;
    public:
        Lavoratore(int dato): dato_lavoratore(dato){}
        ~Lavoratore(){};
        void stampa() const{
            cout << "Dato lavoratore : " << dato_lavoratore << endl;
        }
};
class Studente_Lavoratore: public Studente, public Lavoratore{
    private:
    public:
        Studente_Lavoratore(int dato_s, int dato_l): Studente(dato_s), Lavoratore(dato_l){}
        ~Studente_Lavoratore(){}
};

class A{
    protected:
        string n;
    public:
        A(string n){
            cout << "A::A(n)" << endl;
            this->n = n;
        }
        A(){
            cout << "A::A()" << endl;
            this->n = "";
        }
};

class B: virtual public A{
    private:
    public:
        B(string n): A(n){
            cout << "B::B(n)" << endl;
        }
};

class C: virtual public A{
    private:
    public:
        C(string n): A(n){
            cout << "C::C(n)" << endl;
        }
};

class D: public B, public C{
    private:
    public:
        D(string n): B(n), C(n)/*, A(n)*/{
            cout << "D::D(n)" << endl;
        }
};

int main(){
    Studente stud(120);
    Lavoratore lav(150);
    Studente_Lavoratore stud_lav(400, 300);
    stud_lav.Studente::stampa();
    stud_lav.Lavoratore::stampa();

    D d("Michele");

    float a, b;
    try{
        cout << "A = ";
        cin >> a;
        cout << "B = ";
        cin >> b;
        if(a < 0){
            throw "Valore di A negativo";
        }
        if(b == 0){
            throw "Valore di B uguale a 0";
        }
        cout << "A / B = " << a / b << endl;
    }catch(const char* msg){
        cerr << msg << endl;
    }

    try{
        cout << "A = ";
        cin >> a;
        cout << "B = ";
        cin >> b;
        if(a < 0 || b < 0){
        throw invalid_argument("Valore di a e/o di b negativo/i");
        }
        if(b == 0){
            throw overflow_error("Denominatore uguale a 0");
        }
        if(a > 999){
            throw out_of_range("Valore troppo grande");
        }
        cout << "A / B = " << a / b << endl;
    }catch(const invalid_argument& e){
        cout << e.what() << endl;
    }catch(const overflow_error& e){
        cout << e.what() << endl;
    }catch(const exception& e){
        cout << "Eccezione non gestita" << endl;
    }
    return 0;
}