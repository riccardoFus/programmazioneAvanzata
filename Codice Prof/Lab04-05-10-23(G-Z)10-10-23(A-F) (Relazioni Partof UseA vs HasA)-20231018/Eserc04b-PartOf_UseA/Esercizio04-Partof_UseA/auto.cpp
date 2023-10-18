#include <cstdlib>
#include <iostream>
#include "auto.h"
using namespace std;

Auto::Auto(Tipocomb* _tipo, int _cil,string _ma, string _mo):
               motore(_tipo,_cil){
   marca=_ma;
   modello=_mo; 
   motscorta=NULL;
   cout<<">creataAuto"<<marca<<"-"<<modello<<endl;           
}
Auto::~Auto(){
  if (motscorta!=NULL){
    delete motscorta;                   
  }             
 cout<<">distruttaAuto"<<marca<<"-"<<modello<<endl;              
}
void Auto::setMotscorta(Tipocomb* _tipo, int _cil){
 motscorta = new Motore(_tipo,_cil);     
}
void Auto::addMotoretipo(Tipocomb* _tipo){
  motore.setTipo2(_tipo);   
}
void Auto::stampa()const{
  cout << marca << " " << modello << " ";
  motore.stampa(); 
  //oppure alternativo:
  cout << "OPERATOR::" << marca << " " << modello << " " << motore;
  if (motscorta!=NULL){
    motscorta->stampa();                   
  }  
}

ostream& operator<<(ostream& os, const Auto& a){
 os << " marca: " << a.marca;
 os << " modello: " << a.modello;
 os << " motore: " << a.motore << endl;
 if (a.motscorta!=NULL) {
    os<<" motorescorta: "<<*(a.motscorta)<<endl;
 }
 return os;
}
