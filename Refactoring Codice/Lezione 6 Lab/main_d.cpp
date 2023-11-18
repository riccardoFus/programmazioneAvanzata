#include <iostream>
#include <stdexcept>
using namespace std;

int divisione_intera(int a, int b){
    if(a < 0 || b < 0){
        throw invalid_argument("Valore di a e/o di b negativo/i");
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
    try{
        // cout << divisione_intera(-1, 10) << endl;
        // cout << divisione_intera(10, -1) << endl;
        // cout << divisione_intera(-1, -1) << endl;
        // cout << divisione_intera(10, 0) << endl;
        cout << divisione_intera(1000, 40) << endl;
    }catch(const invalid_argument& e){
        cout << e.what() << endl;
    }catch(const overflow_error& e){
        cout << e.what() << endl;
    }/*catch(const out_of_range& e){
        cout << e.what() << endl;
    }*/catch(exception& e){
        cout << "Eccezione non gestita" << endl;
    }
}