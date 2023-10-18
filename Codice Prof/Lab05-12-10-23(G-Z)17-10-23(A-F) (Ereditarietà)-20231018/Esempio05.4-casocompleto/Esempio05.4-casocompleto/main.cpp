#include <cstdlib>
#include <iostream>
#include "studente.h"
#include "docente.h"
#include <list>
using namespace std;

int main(int argc, char *argv[]){
 {
   //variabili specifiche
   Persona p1("Mario","Rossi",21);
   cout << "Persona="<<p1<<endl;   //p1.stampa(); 
   Studente s1("Luca","Verdi",123456);
   cout << "Studente="<<s1<<endl;  //s1.stampa();
   Docente d1("XX","YY",3);
   cout << "Docente="<<s1<<endl;   //d1.stampa();
   
   cout << "============================" << endl; 
   //puntatore generico a persona: deciso run time il contenuto
   Persona* s2;
   int c;
   printf("tipo (0=studente 1=docente)="); 
   fflush (stdin); scanf("%d",&c);
   if (c==0){
     s2 = new Studente("Anna","Bianchi",234555,22); 
     //provare a mettere metodo in class Studente e non il class Persona ed ha richiamarlo: da errore ma non dovrebbe essere    
   }else{
     s2 = new Docente("Anna","Bianchi",2,33);    
   }
   s2->stampa();
   cout << "Persona*="<< *s2 << endl;
   delete s2;   
   
   cout << "============================" << endl;
   //lista generica puntatore a Persona: deciso compiled time il contenuto 
   list <Persona*> lpp;
   list <Persona*>::iterator lppIter;
   lpp.push_back( new Studente("Anna","Bianchi",234555,22) );
   lpp.push_back( new Docente("Anna","Bianchi",2,33) );
   for( lppIter=lpp.begin(); lppIter!=lpp.end(); lppIter++){
      //(*lppIter)->stampa();  //viene invocata stampa di Studente e di Docente 
      //oppure
      cout << (**lppIter)<<endl;   
   } 
   cout << "============================" << endl;
   //lista generica di Persona: deciso compiled time il contenuto 
   list <Persona> lp;
   list <Persona>::iterator lpIter;
   lp.push_back( Studente("Anna","Bianchi",234555,22) );
   lp.push_back( Docente("Anna","Bianchi",2,33) );
   for( lpIter=lp.begin(); lpIter!=lp.end(); lpIter++){
      (*lpIter).stampa(); //viene invocata stampa di Persona    
      
   } 
      
 }
 system("PAUSE"); return EXIT_SUCCESS;
}

