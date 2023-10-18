#include "Motore.h"

#include <iostream>
using namespace std;

Motore::Motore(Combustibile comb, int _cilindata):
	tipo(comb), cilindata(_cilindata), numero_giri(0) {
	ricarica();
}

bool Motore::is_acceso()const{
	return get_giri() > 0;
}

void Motore::accendi(){
	if (!is_acceso() && get_carica() > 0) {
			livello_batteria -= 20;
			numero_giri = 1000;
	}
}

void Motore::spegni(){
	if (is_acceso()) numero_giri = 0;
}

void Motore::accelera(){
	if (is_acceso()) numero_giri += 400;
}

void Motore::rilascia(){
	if (is_acceso()) numero_giri = 1000;
}


void Motore::ricarica(){
	livello_batteria = 100;
}

int Motore::get_cilindrata()const{ 	return cilindata; }
int Motore::get_carica() const{ return livello_batteria; }
int Motore::get_giri()const { return numero_giri; }
string Motore::get_comb()const{ return tipo.get_comustibile(); }

void Motore::stampa()const{
		cout << "Motore ";
		tipo.stampa();
		cout << " " << get_cilindrata() << " cc";
		if (!is_acceso()) cout << " Spento";
		else cout << " Acceso " << get_giri() << " rpm";
		cout << " Batteria:" << get_carica();
}

ostream& operator << (ostream& os, const Motore& m){
	return os << "Motore " << m.get_comb() << " " << m.get_cilindrata() << " cc";
	
}
