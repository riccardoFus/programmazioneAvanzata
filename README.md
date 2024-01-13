# Domande teoriche Programmazione Avanzata
1. Spiega cosa si intende con ereditarietà multipla e come viene realizzata in c++; spiega inoltre cosa è il diamond problem e come viene risolto, con esempio
L'ereditarietà multipla si ha quando una classe eredita da due o più classi, in c++ è realizzata nel seguente modo:
`class C: <type> A1, ..., <type> An` con `<type>` $\in$ {public, private, protected}.

Il problema del diamante si ha quando due o più superclassi hanno una classe base comune da cui ereditano, in questo caso la classe che eredita da queste superclassi
avrebbe un'istanza per ogni superclasse delle superclassi e questo può portare a incongruenza tra i dati e non coerenza tra il programma.
Per gestire questo problema basta rendere `virtual` le seguenti definizioni:
`class B: virtual <type> A ... class C: virtual <type> A` e in questo modo quando richiamiamo nei ctor di D i costruttori di B e C viene chiamato il costruttore a zero
parametri della classe A (*deve essere implementato*). Per chiamare il costruttore a n parametri di A, possiamo richiamarlo nel ctor di D, in generale questa cosa non è
consentita però nel caso dell'utilizzo della keyword `virtual`, questo è consentito.
2.
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