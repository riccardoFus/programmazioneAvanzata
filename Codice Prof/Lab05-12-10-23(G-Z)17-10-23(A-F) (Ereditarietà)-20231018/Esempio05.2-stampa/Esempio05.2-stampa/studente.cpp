#include <cstdlib>
#include <iostream>
#include "studente.h"
using namespace std;

Studente::Studente(const string &_nome, const string &_cognome,
         int _matricola,int _eta):Persona(_nome, _cognome, _eta)
{
 cout<< "costruttore Studente::Studente" << endl;
 matricola=_matricola;
 esami=0;        
} 
Studente:: ~Studente()
{cout<< "distruttore Studente::Studente" << endl;}

 
void Studente::Stampa() const
{
  cout << "Studente::Stampa ";
  //cout << nome << "" cognome << " " << matricola;   
  //Persona::Stampa();
  cout << Persona::get_nome() << " ";
  cout << matricola << endl;
} 

void Studente::CambiaNome(const string &_nome)  
{
  Persona::set_nome(_nome);
}
   
