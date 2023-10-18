#include <cstdlib>
#include <iostream>
#include "tipocomb.h"
using namespace std;

Tipocomb::Tipocomb(Tcombustibile _comb){
  comb=_comb;  
  cout << "creato combustibile ";
  stampa();
  cout << endl;                             
}
Tipocomb::~Tipocomb(){
  cout << "distrutto combustibile ";
  stampa();
  cout << endl;                       
}
void Tipocomb::stampa()const{
 switch (comb){
    case DIESEL: printf("Diesel"); break;
    case BENZINA: printf("Benzina"); break;
    case GPL: printf("GPL"); break;
    default:  printf("ND");      
 }     
}
