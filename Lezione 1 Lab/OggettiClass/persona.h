//Autore: Roberti Pierluigi

//file header è interfaccia della classe
//punto di aggancio di altro sw
//non contiene implementazione - contiene solo parte dichiarativa

//le interfacce si includono una sola volta
//quindi si evita di includerlo più volte con questa istruzione
//e non viene più ricompilata questa parte
#ifndef __PERSONA_H__
#define __PERSONA_H__
#include <string>
using namespace std;

//PER CONVENZIONE NOMI METODI E PROPRIETA' SONO minuscoli
//NOMI DELLE CLASSI SONO maiuscole
//NOMI COMPOSTI SONO SEPARATI DA _
//INDENTAZIONE 2 SPAZI ALLA VOLTA

//disponibile: costruttore default, distruttore, costruttore copia superf
class Persona{
  private:
   string nome;
   string cognome;
   int eta,dim,annoNascita; 
   int* dati; 
  public:
   //costruttore 0 parametri
   Persona();
   //costruttori specifici
   Persona(string _nome, string _cognome, int _eta=0);  
   Persona(int _dim);
   //costruttore di copia
   Persona(const Persona &p); 
   //distruttore  
   ~Persona();
   void stampa() const;
   int get_eta() const;
   string get_nome() const;
   string get_cognome() const;
   void set_eta(int _eta);  
   void set_AnnoNascita(int _anno);
   int get_AnnoNascita() const;  
   bool uguale(const Persona p) const;
  protected:                             
};

ostream& operator <<(ostream& os, const Persona& p);

void stampa(Persona p);
void stampa1(const Persona &p);
void stampa2(const Persona* p);
 
#endif
//lasciare riga vuota alla fina del file
