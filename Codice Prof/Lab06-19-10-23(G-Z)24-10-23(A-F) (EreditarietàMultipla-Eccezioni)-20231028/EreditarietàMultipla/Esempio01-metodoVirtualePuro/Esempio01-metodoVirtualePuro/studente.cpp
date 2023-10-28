#include <cstdlib>
#include <iostream>
#include "studente.h"
using namespace std;

Studente::Studente(char* _no,char* _co,int _mat,int _eta):
          Persona(_no,_co,_eta){
   matricola=_mat;                              
   esami=0;                             
}

void Studente::stampa()const{
   Persona::stampa();
   printf("matricola=%d con esami=%d\n",matricola, esami);  
}
     
void Studente::test(){}              
