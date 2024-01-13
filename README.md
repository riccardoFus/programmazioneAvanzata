# Domande teoriche Programmazione Avanzata
1. Spiega cosa si intende con ereditarietà multipla e come viene realizzata in c++; spiega inoltre cosa è il diamond problem e come viene risolto, con esempio.
- L'ereditarietà multipla si ha quando una classe eredita da due o più classi, in c++ è realizzata nel seguente modo:
`class C: <type> A1, ..., <type> An` con `<type>` $\in$ {public, private, protected}.
Il problema del diamante si ha quando due o più superclassi hanno una classe base comune da cui ereditano, in questo caso la classe che eredita da queste superclassi
avrebbe un'istanza per ogni superclasse delle superclassi e questo può portare a incongruenza tra i dati e non coerenza tra il programma.
Per gestire questo problema basta rendere `virtual` le seguenti definizioni:
`class B: virtual <type> A ... class C: virtual <type> A` e in questo modo quando richiamiamo nei ctor di D i costruttori di B e C viene chiamato il costruttore a zero
parametri della classe A (**deve essere implementato**). Per chiamare il costruttore a n parametri di A, possiamo richiamarlo nel ctor di D, in generale questa cosa non è
consentita però nel caso dell'utilizzo della keyword `virtual`, questo è consentito.
2. Spiega le eccezioni: cosa sono, come vengono propagate e come vengono utilizzate, con esempi.
- Le eccezioni sono un meccanismo per gestire gli errori di runtime, ovvero errori non rilevabili a tempo di compilazione perché si manifestano solo durante l'esecuzione
e solo durante alcune particolari situazioni; se non gestite potrebbero portare a situazioni anomale e mal funzionamento del codice.
Quando si verificano errori di runtime, si possono "lanciare" le eccezioni ovvero si crea un oggetto che appartiene ad una classe particolare, dipendente dallo specifico tipo
di errore a runtime. Il flusso di esecuzione viene sospeso nel punto in cui si è verificato e salta in un altro punto del codice in cui dovrebbe essere gestito, ed è qui che 
utilizziamo la sintassi `try{...}catch(exception e);`. Rispettivamente il `try` è il punto del codice in cui eseguiamo il codice che potrebbe portare a certe situazioni di
eccezione e il `catch` è il blocco che riconosce l'eventuale eccezione e la gestisce. Un blocco `try` può avere associato ad esso $n$ blocchi catch, quando si propaga l'eccezione
viene cercato nei vari blocchi catch il tipo di eccezione lanciato, se si trova allora si esegue il codice al tipo associato. Le eccezioni possono essere propagate in due modi:
automaticamente se previsto dall'istruzione che andiamo ad eseguire oppure manualmente attraverso la keyword `throw <type>("messaggio");`
Abbiamo visto vari esempi di utilizzo `try-catch`, in particolare:
- `throw "messaggio" catch(...){//gestisce un'eccezione generica}`   
- `throw "messaggio" catch(const char* messaggio){//stampa messaggio errore}`
- `throw invalid_argument("messaggio") catch(const invalid_argument& e){cout << e.what() << endl;}`
- `... catch(exception& e){//funzione come catch(...)}`
**Nota Bene**: per utilizzare le ultime due classi, bisogna includere la libreria `<stdexcept>`
3. Spiega cosa sono i thread, come li possiamo usare, perché sono utili; spiega il data race problem e come è possibile risolverlo.
- I thread sono dei sotto processi che possono essere eseguiti in parallelo o in serie. Essi collaborano per il raggiungimento di uno scopo comune e, per questo motivo possono anche condividere tra di loro risorse. Ci permettono di scrivere programmi più efficienti perché sfruttiamo tutti i core della nostra CPU. Ai thread possiamo passare diverse cose: funzioni, oggetti, lambda.
Il data race problem si ha quando due o più thread possono accedere ad una variabile comune e modificarla, se questo è possibile si potrebbero generare computazioni indefinite e molto spesso se non gestito si potrebbe generare incongruenza tra i dati.
Abbiamo visto due modi per risolvere il problema del data race problem:
- Rendere atomiche le operazioni su una certa variabile con la keyword `<atomic>/static std::atomic <type>`
- Definire sezioni critiche del codice mutualmente esclusive e utilizzare i cosiddetti `<mutex>`, tuttavia questa soluzione non risolve tutti i problemi di sincronizzazione, inoltre potrebbe portare a situazioni tipo *deadlock, starvation*
4. Descrivi ampiamente il concetto di copia profonda; illustra poi un breve esempio in cui è presente una classe per cui ha senso creare il costruttore di copia profonda e crea anche tutti i metodi necessari.
- La copia profonda si ha quando vogliamo copiare un'istanza di un qualche valore ma questo valore ce lo abbiamo instanziato dinamicamente e quindi se copiassimo la variabile in se per se copieremmo l'indirizzo e non il valore, per questo quando abbiamo queste situazioni dobbiamo allocare una nuova istanza e assegnare a questa nuova istanza il valore dell'istanza da copiare perché altrimenti avremmo una copia superficiale e può portare a inconsistenze.
Supponiamo di avere una classe con un attributo che è un puntatore, se dovessimo copiare il puntatore semplicemente con la copia superficiale, noi andremmo effettivamente a copiare il puntatore e quindi avremo due attributi che puntano alla stessa porzione di memoria quindi allo stesso elemento, invece noi vogliamo due attributi indipendenti e quindi abbiamo bisogno di allocare un nuovo spazio per il nuovo attributo. Ecco un esempio di codice in cui questo è eseguito:
`class A{
    int *valore;
    A(){...}
    A(const A& a){
        if(a.valore != NULL){
            valore = new int(*(a.valore));
        }else{
            valore = NULL;
        }
    }`
    
    `A& operator = (const A& a){
        if(valore == NULL){
            if(a.valore != NULL){
                valore = new int(*(a.valore));
            }
        }else{
            delete valore;
            if(a.valore != NULL){
                (*valore) = *(a.valore);
            }else{
                valore = NULL;
            }
        }
    }
}`
5.
6.
7.
8.
9.
10.
11.
12.
13.
14.
15.
16.
17.
18.
19.
20.
21.
22.
23.
24.
25.
26.
27.