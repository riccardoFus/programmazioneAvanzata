#include <cstdlib>
#include <iostream>
#include "tipocomb.h"
#include "auto.h"
using namespace std;

int main(int argc, char *argv[]){
  {
    Tipocomb combBENZINA(BENZINA);
    Tipocomb combDIESEL(DIESEL);
    Tipocomb combGPL(GPL);
    Tipocomb *comb;
    comb = new Tipocomb(GPL);

    Auto auto1(&combBENZINA, 1100, "Fiat","Panda");
    auto1.addMotoretipo(&combGPL);
    Auto auto2(comb,3500,"Ferrari","Enzo");
    auto2.setMotscorta(&combDIESEL,2000); 
    auto1.stampa();   
    auto2.stampa();
    
    Auto auto3(comb, 1100, "Fiat","Panda");
    cout << auto3;
   }
    system("PAUSE");
    return EXIT_SUCCESS;
}
