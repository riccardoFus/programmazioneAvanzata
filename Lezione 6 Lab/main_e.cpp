#include <iostream>
#include <stdexcept>
using namespace std;

int divisione_intera(int a, int b){
    if(a < 0 || b < 0){
        throw invalid_argument("Valore/i negativi");
    }
    if(b == 0){
        throw overflow_error("Denominatore uguale a 0");
    }
    if(a > 999){
        throw out_of_range("Valore troppo grande");
    }
    return a / b;
}

int main(int argc, char ** argv){
    int a = 1000;
    int b = 2;
    try{
        cout << divisione_intera(a, b) << endl;
        // ... qualunque problema
    }catch(const invalid_argument& e){
        cout << e.what() << endl;
    }catch(const overflow_error& e){
        cout << e.what() << endl;
    }catch(const out_of_range& e){
        cout << e.what() << endl;
    }catch(exception& e){
        // deve essere l'ultimo questo controllo
        cout << "Eccezione non gestita" << endl;
    }
}