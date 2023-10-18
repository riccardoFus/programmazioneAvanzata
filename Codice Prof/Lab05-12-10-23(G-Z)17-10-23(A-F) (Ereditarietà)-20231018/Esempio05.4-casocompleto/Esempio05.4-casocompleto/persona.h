#ifndef __PERSONA_H__
#define __PERSONA_H__
#include <iostream>
#include <string>
using namespace std;
 
class Persona{
 //private:
  protected: //per operator <<
   string nome;
   string cognome;      
   int eta;      
 public:      
   Persona(string _nome,string _cognome,int _eta=0); 
   virtual ~Persona();
   virtual void stampa()const; 
   virtual ostream& stampaOperator(ostream& os)const; 
   friend ostream& operator << (ostream& os, const Persona& p); 
};

ostream& operator << (ostream& os, const Persona& p); 
#endif
