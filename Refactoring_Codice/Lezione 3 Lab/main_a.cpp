#include <iostream>
using namespace std;

class A{
    private:
        int dato;
        int altro_dato;
    public:
        A(): dato(0), altro_dato(3){
            cout << "Costruttore a zero parametri" << endl;
        }
        explicit A(int _dato): dato(_dato), altro_dato(9){
            cout << "Costruttore ad un parametro" << endl;
        }
        A(int _dato, int _altro_dato): dato(_dato), altro_dato(_altro_dato){
            cout << "Costruttore a due parametri" << endl;
        }
        A(const A& a): dato(a.dato), altro_dato(a.altro_dato){
            cout << "Costruttore di copia" << endl;
        }
        ~A(){
            cout << "Distruttore" << endl;
        }
        int get_dato() const{
            return dato;
        }
        int get_altro_dato() const{
            return altro_dato;
        }
        void set_dato(int _dato){
            dato = _dato;
        }
        A& operator = (const int k){
            cout << "Operator = (const int) eseguito" << endl;
            dato = k;
            altro_dato = k;
            return *this;
        }
        A operator + (const A& a) const{
            cout << "Operator + (const A&) const eseguito" << endl;
            A temp;
            temp.dato = dato + a.dato;
            temp.altro_dato = altro_dato + altro_dato;
            return temp;
        }
        A& operator += (const A& a){
            cout << "Operator += (const A&) eseguito" << endl;
            dato += a.dato;
            altro_dato += a.altro_dato;
            return *this;
        }
        A& operator ++ (){
            cout << "Operator ++ () eseguito" << endl;
            ++dato; ++altro_dato;
            return *this;
        }
        A operator ++ (int){
            cout << "Operator ++ (int) eseguito" << endl;
            A temp;
            temp.dato = dato++;
            temp.altro_dato = altro_dato++;
            return temp;
        }
        A& operator -- (){
            cout << "Operator -- () eseguito" << endl;
            --dato; --altro_dato;
            return *this;
        }
        A operator -- (int){
            cout << "Operator -- (int) eseguito" << endl;
            A temp;
            temp.dato = dato--;
            temp.altro_dato = altro_dato--;
            return temp;
        }
        friend ostream& operator << (ostream& os, const A& a);
};

ostream& operator << (ostream& os, const A& a){
    os << "Dato = " << a.dato << "\nAltro dato = " << a.altro_dato;
    return os;
}

void funzione_test(A a){
    cout << a << endl;
}

int main(int argc, char ** argv){
    A a_1; // 0 3
    A a_2(3); // 3 9
    A a_3(4, 5); // 4 5

    cout << a_1 << endl; // 0 3

    funzione_test(a_2); // copia -> 3 9 -> distruttore

    a_1 = 5; 
    cout << a_1 << endl; // 5 5

    a_1 = a_2; 
    cout << a_1 << endl; // 3 9

    a_1 = a_1 + a_2;
    cout << a_1 << endl; // 6 18

    a_1 += a_2;
    cout << a_1 << endl; // 9 27

    cout << ++a_1 << endl; // 10 28
    cout << a_1 << endl; // 10 28

    cout << a_1++ << endl; // 10 28
    cout << a_1 << endl; // 11 28
}