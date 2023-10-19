#include <iostream>
#include <string>
using namespace std;

bool compare(int a, int b){
    /*
    if(a < 0 || b < 0){
        // sollevare un'eccezione senza gestire = bloccare il programma
        throw "ERR: a o b negativo";
    }
    */
    if(a < 0){
        throw "ERR a negativo";  
    }else if(b < 0){
        string message = "ERR b negativo ";
        // messaggio sullo stderr != eccezione (throw)
        cerr << message << b << endl;
    }
    return a == b;
}

void test(){
    // l'eccezione si propaga fin tanto che c'è un catch che la gestisce
    cout << compare(-1, 0) << endl;
    /*
    try{
        cout << compare(-1, 0) << endl;
        // tutto il resto è ignorato -> tutto il try è ignorato
        cout << "Fine compare" << endl;
    }catch(const char* msg){
        cout << msg << endl;
    }
    */
}

void test2(){
    cout << compare(3, -4) << endl;
}

int main(int argc, char ** argv){
    try{
        test();
        cout << "Fine compare" << endl;
    }catch(const char* msg){
        cout << msg << endl;
    }
    test2();
    cout << "Fine" << endl;
    // meglio gestire l'eccezione nella funzione chiamante
    return 0;
}