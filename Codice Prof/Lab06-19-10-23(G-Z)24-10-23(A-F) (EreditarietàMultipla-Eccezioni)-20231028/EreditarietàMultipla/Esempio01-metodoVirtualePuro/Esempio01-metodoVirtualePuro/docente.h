#ifndef __DOCENTE_H__
#define __DOCENTE_H__
#include "persona.h"
class Docente:public Persona{
  private:
    int corsi;        
  public:      
    Docente(char* _no,char* _co,int _cor,int _eta=30); 
    void stampa()const; 
    void test(); 
};


#endif
