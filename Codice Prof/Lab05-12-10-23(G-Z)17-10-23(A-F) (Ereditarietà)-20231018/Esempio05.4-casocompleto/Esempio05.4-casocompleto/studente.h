#ifndef __STUDENTE_H__
#define __STUDENTE_H__
#include <string>
using namespace std;
#include "persona.h"

class Studente:public Persona{
  private:
    int matricola;
    int esami;          
  public:      
    Studente(string _no,string _co,int _mat,int _eta=20);
	~Studente(); 
    void stampa()const;
    ostream& stampaOperator(ostream& os)const; 
    friend ostream& operator << (ostream& os, const Studente& s);   
};

ostream& operator << (ostream& os, const Studente& s); 
#endif
