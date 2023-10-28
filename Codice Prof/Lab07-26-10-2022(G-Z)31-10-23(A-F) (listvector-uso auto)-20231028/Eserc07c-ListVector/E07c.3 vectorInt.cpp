//Autore: Roberti Pierluigi

/*--------------------------------------------------
Uso dei contenitori con STL - VECTOR: programmazione a TEMPLATE
 ho delle liste generiche, per esempio vettori generici già a disposizione!
Un vettore gestisce i suoi elementi in un array dinamico. 
Esso consente l'accesso casuale, il che significa che è possibile accedere 
 a ciascun elemento direttamente con l'indice corrispondente. 
Aggiunta e rimozione di elementi alla fine dell'array è molto veloce. 
Tuttavia, l'inserimento di un elemento nel mezzo o all'inizio del vettore 
 richiede tempo perché tutti i seguenti elementi devono essere spostati 
 per fare spazio mantenendone l'ordine.
--------------------------------------------------*/
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void foo(int i) { cout << i << "_" ; }

int main() {
    //definisco un vettore di interi
    vector<int> mia_lista;
    
    for(int i=0; i<5; ++i){
    	//inserisco in coda è valido solo questo!!! non push_front
    	mia_lista.push_back(i);
    }
    //NOTA sul ciclo for:
    // a = i++  -> a=i; a=a+1;
    // a = ++i  -> i=i+1; a=i;
    //++iter operazione più efficiente rispetto a iter++ ho una operazione codice macchina in meno
    cout <<"ITERATORE"<<endl;
    vector<int>::iterator iter;
    for (iter=mia_lista.begin(); iter != mia_lista.end(); ++iter){
    	cout << *iter << " ";
    }
    cout << endl;
    cout <<"Reverse ITERATORE"<<endl;
    vector<int>::reverse_iterator riter;
    for (riter=mia_lista.rbegin(); riter != mia_lista.rend(); ++riter){
    	cout << *riter << " ";
    }
    cout << endl;    
    for_each(mia_lista.begin(), mia_lista.end(), &foo);
    cout << endl;
    //itero sui primi 3
    for_each(mia_lista.begin(), mia_lista.begin()+3, &foo);
    cout << endl;
    
    system("PAUSE");    return EXIT_SUCCESS;
}







