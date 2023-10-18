//Autore: Roberti Pierluigi

//attraverso l'ereditarietà evito di riscrivere del codice già realizzato
//caratteristiche dello studente più caratteristiche della persone
//studente eredita le parti della classe Persona e la specializza in alcune sue parti

#ifndef __STUDENTE_H__
#define __STUDENTE_H__

#include <iostream>
using namespace std;
#include <string>
#include "Persona.h"
//devo includere persona.h

class Studente : public Persona {
//Studente deriva dalla classe base Persona
/*Proprietà dell’ereditarietà di tipo public
Proprietà della classe base ereditate dalla sottoclasse
Ulteriori proprietà aggiuntive (nomi diversi)
Possibile ridefinire proprietà della classe base (nomi uguali) mediante overloading
*/
private:	//CAMPI private
 int matricola;
 int esami;
public:     //MEDODI pubblici
 //costruttore specifico per lo studente
 Studente(const string  &_nome, const string  &_cognome, int _matricola, int _eta=0); 
 //parametri per default devono essere gli ultimi (_eta=0)
 void Stampa() const;
 friend ostream& operator << (ostream& os, Studente& s);
};
ostream& operator << (ostream& os, Studente& s);
#endif //__STUDENTE_H__

