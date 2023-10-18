#ifndef tempo_h
#define tempo_h

#include <cstdlib>
#include <iostream>

using namespace std;

class tempo{
public:
	tempo(); // costruttore senza parametri
	explicit tempo(int ore); //costruttore a un parametro
	tempo(int ore, int minuti, int secondi=0); //costruttore a tre parametri
	int Ore() const; // const = non modifica l'oggetto chiamante
	int Minuti()const;
	int Secondi()const;
	void ImpostaTempo(int ore, int minuti, int secondi);
	virtual void AggiungiOra();       
private:
	//protected:
	long int sec; //variabile che rappresenta il tempo
	void normalize(); //metodo private
	//friend ostream& operator<<(ostream& os, tempo& t); //NON e' un metodo
};

ostream& operator<<(ostream& os, tempo& t); // header 

void test_tempo();

#endif
