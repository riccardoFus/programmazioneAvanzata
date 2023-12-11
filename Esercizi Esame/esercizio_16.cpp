/*
    Crea due classi A e B diverse tra loro, entrambe hanno un attributo privato n.
    Implementa l'operatore < per confrontare due istanze delle tali classe e fallo 
    senza dichiarare metodi d'appoggio come get_n(); Inoltre sappi che l'operatore deve
    funzionare sia per A < B che per B < A.
*/
#include <iostream>
using namespace std;
class B;
class A{
    private:
        int n;
    public:
        A(int n){ this->n = n; }
        friend bool operator < (const A& a, const B& b);
        friend bool operator < (const B& b, const A& a);
};

class B{
    private: 
        int n;
    public:
        B(int n){ this->n = n; }
        friend bool operator < (const A& a, const B& b);
        friend bool operator < (const B& b, const A& a);
};
bool operator < (const A& a, const B& b){
    return a.n < b.n;
}
bool operator < (const B& b, const A& a){
    return b.n < a.n;
}

int main(int argc, char ** argv){
    A a1(10);
    B b1(20);
    if(a1 < b1){
        cout << "a1 e' minore di b1" << endl;
    }else{
        cout << "a1 e' maggiore/uguale di b1" << endl;
    }
    if(b1 < a1){
        cout << "b1 e' minore di a1" << endl;
    }else{
        cout << "b1 e' maggiore/uguale di a1" << endl;
    }
}