#include "automobile.h"
#include <iostream>
#include <string>
using namespace std;

Automobile::Automobile(string _marca, string _modello, int cilindrata, Tipocomb* tipo): motore(cilindrata, tipo){
	marca = _marca;
	modello = _modello;
	motoreScorta = NULL;
	cout << "Creata automobile di marca " << *this << endl << endl;
}

Automobile::~Automobile(){
	cout << "Distrutta automobile di marca " << *this <<  endl << endl;
	// attenzione, mai disallocare prima dell'output
	if(motoreScorta != NULL) delete motoreScorta;
}

void Automobile::addMotoreScorta(int cilindrata, Tipocomb* tipo){
	motoreScorta = new Motore(cilindrata, tipo);
	cout << "Aggiunto motore di scorta nell'automobile di marca " << *this << endl;
}

ostream& operator << (ostream& os, const Automobile& automobile){
	os << automobile.marca << ", modello " << automobile.modello << ". " << automobile.motore;
	if(automobile.motoreScorta != NULL) os << " " << *(automobile.motoreScorta);
	return os;
}
