# Domande teoriche Programmazione Avanzata
1. Spiega cosa si intende con ereditarietà multipla e come viene realizzata in c++; spiega inoltre cosa è il diamond problem e come viene risolto, con esempio
- L'ereditarietà multipla si ha quando una classe eredita da due o più classi, in c++ è realizzata nel seguente modo:
`class C: <type> A1, ..., <type> An` con `<type>` $\in$ {public, private, protected}.
Il problema del diamante si ha quando due o più superclassi hanno una classe base comune da cui ereditano, in questo caso la classe che eredita da queste superclassi
avrebbe un'istanza per ogni superclasse delle superclassi e questo può portare a incongruenza tra i dati e non coerenza tra il programma.
Per gestire questo problema basta rendere `virtual` le seguenti definizioni:
`class B: virtual <type> A ... class C: virtual <type> A` e in questo modo quando richiamiamo nei ctor di D i costruttori di B e C viene chiamato il costruttore a zero
parametri della classe A (*deve essere implementato*). Per chiamare il costruttore a n parametri di A, possiamo richiamarlo nel ctor di D, in generale questa cosa non è
consentita però nel caso dell'utilizzo della keyword `virtual`, questo è consentito.
2. Spiega le eccezioni: cosa sono, come vengono propagate e come vengono utilizzate, con esempi
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
*Nota Bene*: per utilizzare le ultime due classi, bisogna includere la libreria `<stdexcept>`
3.
4.
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