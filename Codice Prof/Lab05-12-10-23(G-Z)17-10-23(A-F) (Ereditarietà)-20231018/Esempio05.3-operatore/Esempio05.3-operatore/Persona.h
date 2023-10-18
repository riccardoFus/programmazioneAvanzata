//Autore: Roberti Pierluigi
//Data: 06-05-2010

#ifndef __PERSONA_H__
#define __PERSONA_H__

#include <string>
#include <iostream>
using namespace std;

class Persona{

private:	//CAMPI private
  //char* nome;  //stringe in C
  string nome;   // stringhe in CPP string:si occupa di allocare e deallocare in modo autonomo la memoria
  string cognome;
  int eta;
public:     //MEDODI pubblici
 //costruttore specifico
 Persona(const string  &_nome, const string  &_cognome, int _eta=0); 
 void Stampa() const;
 string get_nome() const;
 string get_cognome() const;
 int get_eta() const;
 friend ostream& operator << (ostream& os, Persona& p);
};
ostream& operator << (ostream& os, Persona& p);
#endif //__PERSONA_H__

