//Autore: Roberti Pierluigi

//contiene l'implementazione dell'interfaccia
#include "Persona.h"
//includo l'interfaccia di cui voglio fare l'implementazione

//Persona:: costruttore che appartiene alla struttura persona
//simile a std::cout
//se non viene dichiarato 
//using namespace std;

#include <iostream>
using namespace std;

Persona::Persona()
 {
	nome = "Mario";
	cognome = "Rossi";
	eta=0;
	b=NULL;
	cout << "Persona Inizializzata per default"<<endl;
 }

 //il dato DEFAULT _eta=0 non viene specificato
Persona::Persona(char* _nome, char* _cognome, int _eta)
 {
 	nome = _nome;
	cognome = _cognome;
	eta=_eta;
    b = new int[5]; 
    b[0]=1; b[1]=2; b[2]=3;b[3]=4;b[4]=5;
	cout << "Persona Inizializzata in modo specifico"<<endl;
 }
//costruttore per copia
Persona::Persona(const Persona& p){
 nome=p.nome;
 eta=p.eta;
 //b=p.b; // lo fa di default ma copio il puntatore
 //mentre devo duplicare i dati in memeoria!!!
 if (p.b==NULL){
    b=NULL;
 }else{ 
    b=new int[5];
    for(int i=0;i<5;i++){
        b[i]=p.b[i];
    }
  } 
  cout << "costruttore di copia"<<endl;
}
 Persona::~Persona() {
   if (b!=NULL) delete b;
   cout << "Persona distrutta:"<<nome<<endl;;
 }

 void Persona::Stampa() const
 {   
	 cout << " " << nome << " " << cognome << " " << eta<<endl;
 }

 int Persona::confronta(const Persona &P2) const
 {
	if (eta>P2.eta) return -1;
	if (eta==P2.eta) return 0;
	if (eta<P2.eta) return 1;
 }

void Stampa(const Persona p){
     p.Stampa();
} 
