#include <cstdlib>
#include <iostream>
#include "studente.h"
#include "docente.h"
using namespace std;

int main(int argc, char *argv[]){
 {
  // Persona p1("Mario","Rossi",21); /* non è possibile perchè contiene un metodo virtuale puro*/
  // p1.stampa(); 
   Studente s1("Luca","Verdi",123456);
   s1.stampa();
   Docente d1("XX","YY",3);
   d1.stampa();
   
   Persona* s2;  /*lo posso fare perchè non stò istanziando nessuna variabile*/
   int c;
   printf("c="); scanf("%d",&c);
   if (c==0){
     s2 = new Studente("Anna","Bianchi",234555,22); 
   }else{
     s2 = new Docente("Anna","Bianchi",2,33);    
   }
   s2->stampa(); /*stampa in Persona è virtual => richiamo stampa dell'istanza specifica Studente o Docente*/
   delete s2;         
 }
 system("PAUSE"); return EXIT_SUCCESS;
}

