#include <cstdlib>
#include <iostream>
#include "auto.h"
using namespace std;

int main(int argc, char *argv[]){
 {
   //Tipocomb tc(GPL);
   //tc.stampa();           
   //Motore mferrari(BENZINA,3000);
   //mferrari.stampa(); 
   Auto ferrari(BENZINA, 3000,"ferrari","testarossa");
   ferrari.setMotoreScorta(DIESEL,2000); 
   ferrari.stampa();        
 }   
 system("PAUSE"); return EXIT_SUCCESS;
}
