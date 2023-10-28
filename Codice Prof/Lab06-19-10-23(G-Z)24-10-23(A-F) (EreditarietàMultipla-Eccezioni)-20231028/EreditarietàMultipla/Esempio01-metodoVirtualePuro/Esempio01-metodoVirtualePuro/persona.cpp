#include <cstdlib>
#include <iostream>
#include "persona.h"
using namespace std;

Persona::Persona(char* _nome,char* _cognome,int _eta){
  nome=_nome;  cognome=_cognome;  eta=_eta;                    
}

void Persona::stampa()const{
  printf("%s %s di eta'=%d\n",nome,cognome,eta);     
}
