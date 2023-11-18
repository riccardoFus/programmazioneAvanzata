#include <iostream>
using namespace std;

// eccezioni -> sempre presente in qualche esercizio
// eccezione = generato a runtime (file non esiste, divisione per 0, overflow, casting non valido)
// non gestite -> bloccano l'applicazione
// 1) sollevare un'eccezione : mando un messaggio e qualcuno gestirà l'errore (verra catchato da qualche metodo)
// 2) se ho un problema, lo risolvo in autonomia
// try -> catch
int main(int argc, char ** argv){
    float a,b;
    try{
        // eseguo il codice
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        // per dare una priorità a certe eccezioni, basta invertire l'ordine dei throw
        if(a < 0){
            throw "a negativo!";
        }
        if(b == 0){
            // lancia un'eccezione di tipo "comando string" -> non eseguo il codice successivo
            throw "Divisione per zero!";
        }
        cout << a / b;
        // c'è un try catch interno
    } catch(const char* msg) {
        // cosa fare se avviene errore
        cerr << msg << endl;
        // cout << "ERRORE GESTITO DA CATCH" << endl;
    }
    cout << "Fine" << endl;
    // ci possono avere più catch sotto, l'ordine è rilevante -> viene eseguito il primo catch tra quelli avvenuti
    return 0;
}