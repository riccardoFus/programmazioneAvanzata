#ifndef __STUDENTE_H__
#define __STUDENTE_H__

#include "persona.h"

class Studente: public Persona{
private:
        int matricola;
        int esami;
public:
 Studente(const string &_nome,const string &_cognome,
          int _matricola, int _eta=0);
 ~Studente();                
 void Stampa() const;
 void CambiaNome(const string &_nome);                
};

#endif
