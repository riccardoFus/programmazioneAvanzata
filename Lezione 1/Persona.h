#ifndef __PERSONA_H__
#define __PERSONA_H__

#include <string>
using namespace std;

// INDENTAZIONE 2 SPAZI


// class : costruttore default, distruttore, costruttore copia

// mettere gli attributi sempre privati
class Persona{
	private:
		string nome, cognome;
		int eta;
		int *b;
	public:
		Persona();
		Persona(string _nome, string _cognome, int _eta=0);
		Persona(const Persona& p);
		~Persona();
		void stampa() const;
		void setEta(int _eta);
		int getEta() const;
		void setNome(string _nome);
		string getNome() const;
		void setCognome(string _cognome);
		string getCognome() const;
		int* getB() const;
	protected:
};

void stampa1(const Persona p);

void stampa2(const Persona* p);

void stampa3(const Persona& p);

ostream& operator <<(ostream& os, const Persona& p);

#endif
// lasciare riga vuota alla fine del file
