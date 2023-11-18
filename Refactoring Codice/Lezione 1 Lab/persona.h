#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class Persona{
	private:
		string nome, cognome;
		int eta;
		int *vettore_dinamico;
	public:
		Persona();
		Persona(string _nome, string _cognome, int _eta = 0);
		Persona(const Persona& p);
		~Persona();

		void stampa() const;
		void set_eta(int _eta);
		int get_eta() const;
		void set_nome(string _nome);
		string get_nome() const;
		void set_cognome(string _cognome);
		string get_cognome() const;
		int* get_vettore_dinamico() const;
	protected:
};

void stampa_con_copia(const Persona p);

void stampa_con_puntatore(const Persona* p);

void stampa_con_riferimento(const Persona& p);

ostream& operator << (ostream& os, const Persona& p);

#endif