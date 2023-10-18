#include "Automobile.h"
#include <iostream>
using namespace std;


Automobile::Automobile(string _marca, string _modello, Combustibile comb, int _cilindata)
		: motore(comb, _cilindata), 
		marca(_marca), modello(_modello), 
		targa("Non registrata"), 
		velocita(0) {
   //nessuna implementazione tutto nell'header!!
}

void Automobile::immatricola(string _targa){
	targa = _targa;
}

void Automobile::accendi(){
	motore.accendi();
	is_accesa = motore.is_acceso();
}

void Automobile::spegni(){
	ferma();
	if (is_accesa) motore.spegni();

	is_accesa = false;
}
	
void Automobile::accelera(){
	motore.accelera();
	if (is_accesa) velocita += 20;
}

void Automobile::ferma(){
	motore.rilascia();
	velocita = 0;
}

int Automobile::get_velocita()const { return velocita; }

void Automobile::stampa()const{
	cout << marca << " " << modello << " targa: " << targa << endl;
	motore.stampa();

	cout << endl << "Velocita: ";		
	if (is_accesa && get_velocita() > 0) {
			cout << get_velocita() << " km/h\n";
	}
	else cout << "auto ferma\n";
}

ostream& operator << (ostream& os, const Automobile& a){
	return os << a.marca << " " << a.modello << " targa: " << a.targa << endl << a.motore;
}
