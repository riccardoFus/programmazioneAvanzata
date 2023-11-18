#include <iostream>
using namespace std;

int main(int argc, char ** argv){
    float a, b;
    try{
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        if(a < 0){
            throw "Valore di a negativo";
        }
        if(b == 0){
            throw "Valore di b uguale a 0";
        }
        cout << a / b << endl;
    }catch(const char* messaggio_throw){
        cerr << messaggio_throw << endl;
    }
    cout << "Fine programma" << endl;
    return 0;
}