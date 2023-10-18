#ifndef __PERSONA_H__
#define __PERSONA_H__
#include <string>
using namespace std;
class Persona{
private:
       string nome;  //char* nome;
       string cognome;
       int eta;       
public:
 Persona(const string &_nome,const string &_cognome, int _eta=0);
 void Stampa()const;
 ~Persona();
 string get_nome() const;
 void set_nome(const string &_nome);
};

#endif
