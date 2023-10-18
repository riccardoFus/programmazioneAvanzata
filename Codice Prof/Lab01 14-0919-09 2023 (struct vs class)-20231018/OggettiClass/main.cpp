#include <cstdlib>
#include <iostream>
#include "persona.h"
//il main sa come è fatta una persona non come è implementata!!!
using namespace std;
//per compilare:
//g++ main.cpp
//ERRORE: il linker ha un riferimento non definito ai metodi (manca infatti Persona.cpp)
//g++ main.cpp persona.cpp
//creo un file a.out
//l'ordine dei FILE non è importante
//i file H non vengono MAI compilati

//OPPURE
//g++ -c main.cpp
//produce main.o
//g++ -c persona.cpp
//produce persona.o
//chiamo infine il linker
//g++ main.o persona.o
//creo un file a.out

int main(int argc, char *argv[]){
 //p1 non esiste all'infuori del blocco delle {}
 //visibilità ristretta dell'istanza dell'istanza p1    
 {
   Persona p1; //allocata nello stack
   cout << "eta'="<<p1.get_eta() << endl; 
   //p1.eta=-5;   //non posso modificare un campo privato: ERRORE!!!
   p1.set_eta(-5);
   cout << p1.get_eta() << endl; 
   p1.stampa();
   
   Persona p2(5);
   p2.set_AnnoNascita(2045);     
   p2.stampa(); 

   Persona p3("Mario","Rossi",33); 
   stampa(p3);
   
   cout << p1.uguale(p2)<<endl; // if (p1==p2){}  
   cout << "stampo con overload operatore <<:" << p3 << endl;  
   
   Persona* pp;
   pp = new Persona("Luca","Verdi",33);  //alloco nell'heap 
   pp->stampa();
   cout << "stampo con overload operatore <<:" << (*pp) << endl; 
   delete pp;
 }  
 //p1 viene distrutto dopo il blocco che lo contiene   
 system("PAUSE");  return EXIT_SUCCESS;
}


