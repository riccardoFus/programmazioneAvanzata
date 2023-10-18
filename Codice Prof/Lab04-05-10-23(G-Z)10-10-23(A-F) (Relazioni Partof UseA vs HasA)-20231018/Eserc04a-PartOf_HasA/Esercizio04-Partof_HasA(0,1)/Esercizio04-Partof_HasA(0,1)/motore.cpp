#include <cstdlib>
#include <iostream>
#include "motore.h"
using namespace std;

Motore::Motore(Tipocomb _tipocomb,int _cil):
               tipo(_tipocomb),cil(_cil){
    //cil=_cil;                   
   cout << "creato Motore cil:" << cil << endl;                     
}
Motore::Motore(Tcombustibile _tipo,int _cil):tipo(_tipo){
  cil=_cil;                      
  printf("creato motore cilindrata=%d\n",cil);                      
}
int Motore::get_cil()const{ return cil; }
Tipocomb Motore::get_tipo()const{ return tipo; }
Motore::~Motore(){
 printf("distrutto motore cilindrata=%d\n",cil);                 
}

void Motore::stampa() const{
  printf("motore %dcc ",cil);
  tipo.stampa();
  printf("\n");   
}  
