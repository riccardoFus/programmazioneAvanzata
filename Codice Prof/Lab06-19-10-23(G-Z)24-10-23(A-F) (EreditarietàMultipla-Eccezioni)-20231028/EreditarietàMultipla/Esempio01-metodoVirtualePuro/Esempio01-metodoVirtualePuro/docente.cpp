#include <cstdlib>
#include <iostream>
#include "docente.h"
using namespace std;

Docente::Docente(char* _no,char* _co,int _cor,int _eta):
          Persona(_no,_co,_eta){
   corsi=_cor;                                                         
}

void Docente::stampa()const{
   Persona::stampa();
   printf("corsi=%d\n",corsi);  
}

void Docente::test(){}
  
