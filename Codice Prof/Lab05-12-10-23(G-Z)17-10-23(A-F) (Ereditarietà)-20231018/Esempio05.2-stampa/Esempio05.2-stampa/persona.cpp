#include <cstdlib>
#include <iostream>
#include "persona.h"
using namespace std;

Persona::Persona(const string &_nome,const string &_cognome, int _eta)
{
 cout<< "costruttore Persona::Persona" << endl;
 nome=_nome;
 cognome=_cognome;
 eta=_eta;                      
}
Persona:: ~Persona()
{
  cout<< "distruttore Persona::Persona" << endl;         
}

void Persona::Stampa() const
{
 cout << "Persona::Stampa " << nome << " " << cognome;
 cout << " " << eta << endl;    
}

string Persona::get_nome() const
{
  return nome;     
}

void Persona::set_nome(const string &_nome)
{
  nome = _nome;   
}
