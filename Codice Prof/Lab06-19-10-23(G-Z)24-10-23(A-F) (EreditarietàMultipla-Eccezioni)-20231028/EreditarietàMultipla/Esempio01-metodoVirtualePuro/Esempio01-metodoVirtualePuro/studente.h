#ifndef __STUDENTE_H__
#define __STUDENTE_H__
#include "persona.h"
class Studente:public Persona{
  private:
    int matricola;
    int esami;          
  public:      
    Studente(char* _no,char* _co,int _mat,int _eta=20); 
    void stampa()const; 
    void test(); 
};


#endif
