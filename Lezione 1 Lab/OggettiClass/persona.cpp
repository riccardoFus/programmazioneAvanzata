#include <cstdlib>
#include <iostream>
#include <ctime>
#include "persona.h"
using namespace std;
//contiene l'impementazione dell'interfaccia
//includo l'interfaccia di cui voglio fare l'implementazione
//Persona:: costruttore che appartiene alla struttura persona
//simile a std::cout
//se non viene dichiarato 
//using namespace std;
Persona::Persona(){
  eta=1; nome="NN"; cognome="NN";
  annoNascita=0; dim=0; dati = NULL;
  cout << "costruttore default:" <<nome<<" "<< cognome<<endl; 
}
Persona::Persona(int _dim){
  eta=1; nome="NN"; cognome="NN";
  annoNascita=0; dim=_dim; dati = new int[dim];
  //attenzione non inizializzato array dati => potenziale porblema!
  cout << "costruttore 1 param:"<<nome<<" "<< cognome<<endl;              
}
Persona::Persona(string _nome, string _cognome, int _eta){
  nome=_nome;
  cognome=_cognome;
  set_eta(_eta);  // eta=_eta; NO  
  dati = new int[5]; dim=5;
  int i;
  for(i=0; i<5; i++){
    dati[i]=i;        
  }
  cout << "costruttore 3 param:"<<nome<<" "<< cognome<<endl;               
}
Persona::~Persona(){
  cout << "distrutto: " <<nome<<" "<< cognome<<endl;  
  if (dati!=NULL) { delete dati;}                
}
void Persona::stampa() const{
  cout << nome << " eta=" << eta << " anno=" << annoNascita<< endl;
  if (dati!=NULL) { 
     for(int i=0; i<dim; i++){
        cout << " dati["<<i<<"]="<<dati[i];        
     } 
	 cout <<endl;              
  }       
}
//costruttore di copia
Persona::Persona(const Persona &p){
     cout << "costruttore copia" << endl;           
     nome = p.nome; cognome = p.cognome; eta = p.eta;
     dim = p.dim;
     if (p.dati==NULL){
        dati=NULL;               
     }else{
        dati = new int[dim];
        for(int i=0; i<dim; i++){
          dati[i]=p.dati[i];        
        }   
     }       
  }
bool Persona::uguale(const Persona p) const{
 if (eta!=p.eta) { return false; }
 if (dim!=p.dim) { return false; }
 if (dati==NULL && p.dati==NULL) {return true; }
 for(int i=0; i<dim; i++){
   if(dati[i]!=p.dati[i]) { return false; }        
 }
 return true;
}
int Persona::get_eta() const{
    return eta;
}
string Persona::get_nome() const{
    return nome;
}
string Persona::get_cognome() const{
    return cognome;
}
void Persona::set_eta(int _eta){
  if (_eta<0) { _eta=0; }
  if (_eta>99) { _eta=99; }
  eta=_eta;
}

void Persona::set_AnnoNascita(int _anno){
  if (_anno<1900) { _anno=1900; }
  //if (_anno>2018) { _anno=2018; }     //non va più bene dopo il 2018
  //#include <ctime>
  time_t now=time(0);
  tm *dataOrario = localtime(&now);
  cout << "anno=" << dataOrario->tm_year+1900 << endl;
  int annoCorr = dataOrario->tm_year+1900;
  if (_anno>annoCorr) { _anno=annoCorr; }
  annoNascita=_anno;  
  //età campo calcolato!!!
  eta= annoCorr - annoNascita;
}
int Persona::get_AnnoNascita() const{
  return annoNascita; 
} 

/*
 implementazione delle funzioni
*/
void stampa(Persona p){
   //cout << p.nome << endl;
   //printf("nome: %s eta:%d \n",p.nome,p.eta); 	
   p.stampa();	 
   //cout << p.get_eta()
}
void stampa1(const Persona &p){	
   p.stampa();	
}
void stampa2(const Persona* p){	
   p->stampa();	
}


ostream& operator <<(ostream& os, const Persona& p){
 return os << p.get_nome() << ":" << p.get_cognome() << ":" << p.get_eta();
}
