#include <cstdlib>
#include <iostream>
#include "tipocomb.h"
using namespace std;

Tipocomb::Tipocomb(Tcombustibile _comb):comb(_comb){
  //cout<<">>>creatoTipocomb"<<comb<<endl;    
  cout<<">>>creatoTipocomb"<<*this<<endl;                            
}
Tipocomb::~Tipocomb(){
  //cout<<">>>distruttoTipocomb"<<comb<<endl;   
  cout<<">>>distruttoTipocomb"<<*this<<endl;         
}
void Tipocomb::stampa() const{
   switch(comb){
     case DIESEL: cout << "Diesel "; break;
     case BENZINA:cout << "Benzina "; break;
     case GPL:    cout << "Gpl "; break;
     default: cout << "BOH ";             
   }  
}

ostream& operator<<(ostream& os,const Tipocomb& tc){ 
 switch (tc.comb){
   case DIESEL: os<<"Diesel "; break;
   case BENZINA: os<<"Benzina ";break;
   case GPL: os <<"Gpl ";break;
   default: cout<< "BOH! ";
 }
 return os;
}
