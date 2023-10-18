#ifndef __DOCENTE_H__
#define __DOCENTE_H__
#include "persona.h"
#include <iostream>
using namespace std;

class Docente:public Persona{
  private:
    int corsi;        
  public:      
    Docente(string _no,string _co,int _cor,int _eta=30);
	~Docente(); 
    void stampa()const; 
    ostream& stampaOperator(ostream& os)const; 
    friend ostream& operator << (ostream& os, const Docente& d);
};

ostream& operator << (ostream& os, const Docente& d); 
#endif
