#ifndef PERSONA_H
#define PERSONA_H

using namespace std;
class Persona{
	private:
	protected:
		int eta;
		string nome, cognome;
		// l'attributo NON è visibile all'esterno ma alle sottoclassi SI
	public:
		Persona(string nome, string cognome, int eta = 0);
		virtual ~Persona(); // si mette virtual -> se c'è un'allocazione dinamica, chiama il distruttore ereditato e poi chiama questa
		virtual void stampa() const;
		virtual ostream& stampaOperator(ostream& os) const; // const è fondamentale!!!
		virtual void test() = 0; // classe puramente virtuale
		friend ostream& operator << (ostream& os, const Persona& p);
};

ostream& operator << (ostream& os, const Persona& p);

#endif
