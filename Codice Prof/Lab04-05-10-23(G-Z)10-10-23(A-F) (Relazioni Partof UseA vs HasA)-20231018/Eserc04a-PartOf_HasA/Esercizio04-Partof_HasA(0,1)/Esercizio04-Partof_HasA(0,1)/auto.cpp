#include <cstdlib>
#include <iostream>
#include "auto.h"
using namespace std;

Auto::Auto(Tcombustibile _tipo,int _cil,char* _marca,
       char* _modello):motore(_tipo,_cil){
    marca=_marca;
    modello=_modello;
    motoreScorta = NULL; 
    printf("creata %s %s",marca, modello);
    motore.stampa();            
}
Auto::Auto(const Auto& a):motore(a.motore.get_tipo(),a.motore.get_cil()) {
  marca=a.marca;
  modello=a.modello;
  if (a.motoreScorta==NULL){ motoreScorta=NULL; }
  if (a.motoreScorta!=NULL){
       motoreScorta = new Motore(a.motoreScorta->get_tipo(),a.motoreScorta->get_cil());                       
    }               
}
Auto::~Auto(){      
    printf("distrutta %s %s",marca, modello);
    motore.stampa();   
    if (motoreScorta!=NULL){
       delete motoreScorta;                       
    }                   
}
void Auto::stampa() const{
    printf("auto: %s %s",marca, modello);
    motore.stampa(); 
    if(motoreScorta!=NULL){
      motoreScorta->stampa();                       
    }    
} 

void Auto::setMotoreScorta(Tcombustibile _tipo,int _cil){
  motoreScorta = new Motore(_tipo,_cil);   
}
