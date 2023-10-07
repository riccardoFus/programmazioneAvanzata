//Autore: Roberti Pierluigi

//file header è interfaccia della classe
//punto di aggancio di altro sw
//non contiene implementazione - contiene solo parte dichiarativa

//le interfacce si includono una sola volta
//quindi si evita di includerlo più volte con questa istruzione
//e non viene più ricompilata questa parte
#ifndef __PERSONA_H__
#define __PERSONA_H__

//PER CONVENZIONE NOMI METODI E PROPRIETA' SONO minuscoli
//NOMI DELLE CLASSI SONO maiuscole
//NOMI COMPOSTI SONO SEPARATI DA _
//INDENTAZIONE 2 SPAZI ALLA VOLTA

struct Persona{
    //CAMPI
    char* nome;
    char* cognome;
    int eta;
    int* b;
    
    //MEDODI
    //costruttore di default
    Persona();
    //Persona():Persona("Mario","Rossi",0);
    /*
    Il corpo del costruttore è l'ultima cosa ad essere eseguita 
	(per quanto riguarda l'ordine di inizializzazione). 
	L'ordine lo si può trovare su:
	https://en.cppreference.com/w/cpp/language/constructor#Initialization_order
    */
    //costruttore specifico
    //con un parametro di DEFAULT _eta=0 se questo non viene specificato
    Persona(char* _nome, char* _cognome, int _eta=0);
    //distruttore
    ~Persona();
    //costruttore di copia
    Persona(const Persona& p);
    void Stampa() const;
    int confronta(const Persona &P2) const;
};
void Stampa(const Persona p); // manca il costuttore di copia

#endif //__PERSONA_H__
//lasciare riga vuota alla fina del file
