//Autore: Roberti Pierluigi

/*--------------------------------------------------
Uso dei contenitori con STL - LIST: programmazione a TEMPLATE
ho delle liste generiche, per esempio vettori generici gi� a disposizione!
Un elenco � implementato come una lista doppiamente concatenata di elementi. 
Questo significa che ogni elemento in una lista ha un proprio segmento 
 di memoria e si riferisce al suo predecessore e il suo successore. 
Le liste non forniscono accesso casuale. Ad esempio, per accedere 
 al decimo elemento, � necessario passare i primi nove elementi, 
 seguendo la catena dei loro legami. 
Tuttavia, un passo verso l'elemento successivo o precedente � possibile in tempo costante. 
Cos�, l'accesso generale ad un elemento arbitrario richiede 
 tempo lineare (la distanza media � proporzionale al numero di elementi). 
Il vantaggio di una lista � che l'inserimento o la rimozione di un elemento 
 � veloce in qualsiasi posizione. 
Solo i collegamenti devono essere modificati! 
Ci� implica che lo spostamento di un elemento nel mezzo di una lista 
 � molto veloce confrontata con lo spostamento di un elemento in un vettore.
--------------------------------------------------*/
#include <list>
#include <iostream>
using namespace std;

void foo(int i)
{ cout << i << "_" ; }

int main()
{
    //definisco una lista di interi
    //RIFERIMENTO: capitolo 5 e 6 volume 2
    list<int> mia_lista;
    
    for(int i=0; i<5; ++i) {
    	//mia_lista.push_back(i) inserisco in coda alla lista
    	//inserisco in testa alla lista, aggiungo un intero perch� mia_lista contiene interi
    	mia_lista.push_front(i);
    }
    //esiste il tipo iteratore (Class iterator) contenuto nella classe stessa
    //specializzata per attraversare una lista di interi (per esempio)
    //iter � l'istanza della classe iterator
    //mia_lista.begin() parto dall'inizio della lista, restituisce un iteratore all'inizio della lista
    //mia_lista.end() fine della lista
    //non posso mettere < perch� non so se iteratore cresce, non lo conosco
    list<int>::iterator iter;
    for (iter=mia_lista.begin(); iter != mia_lista.end(); ++iter){
    	//list<int>::iterator ridefinisce l'operatore *
    	//iter in C++ � una astrazione su un puntatore
    	//*iter � valore puntato da iter
    	cout << *iter << " ";
    }
    cout << endl;
    //reverse iterator
    list<int>:: reverse_iterator riter;
    for (riter=mia_lista.rbegin(); riter != mia_lista.rend(); ++riter){
    	cout << *riter << " ";
    }
    cout << endl;
    //questo modo non dipende dal contenitore!!!!
    //iteratore sequenziale per esempio su una lista
    //iteratore sui vettori, random accedono al 5 valore in un passo solo
    
    //in C++ si definiscono degli algoritmi generici per attraversamenti generici 
    //o ordinamento di liste
    //generici perch� sono indipendenti dal contenuto e dal contenitore (lista o vettore)
    //RIFERIMENTO: capitolo 5
    //prende 2 iteratori & puntatore ad una funzione (che � il nome alla funzione)
    //for_each(mia_lista.begin(), mia_lista.end(), foo)
    //oppure
    for_each(mia_lista.begin(), mia_lista.end(), &foo);
    cout << endl;
    //for_each sta dentro STD!
    
    //ricerca elemento 3 con cancellazione
    iter = find(mia_lista.begin(), mia_lista.end(),3);
    if (iter != mia_lista.end()) {
         mia_lista.erase(iter);
    }
    for_each(mia_lista.begin(), mia_lista.end(), &foo);
    cout << endl;
    
    system("PAUSE");    return EXIT_SUCCESS;
}






