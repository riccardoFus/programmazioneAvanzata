#include "motore.h"
#include <iostream>
using namespace std;
/*
Motore::Motore(int _cilindrata, Tcombustibile _comb): cilindrata(_cilindrata), tipo(_comb){
	
	cout << "Creato motore di cilindrata " << *this << endl << endl;
}
*/

Motore::Motore(int _cilindrata, Tipocomb* _tipo1){
	cilindrata = _cilindrata;
	tipo1 = _tipo1;
	tipo2 = NULL;
	cout << "Creato motore di cilindrata " << *this << endl << endl;
}

Motore::~Motore(){
	cout << "Distrutto motore di cilindrata " << *this << endl << endl;
	/*
	NON SI DISTRUGGONO
	delete tipo1;
	if(tipo2 != NULL) delete tipo2;
	*/
}

ostream& operator << (ostream& os, const Motore& motore){
	os <<  motore.cilindrata << " con combustibile " << *(motore.tipo1);
}

/*
SBAGLIATISSIMO -> IL MAIN NON SA COSA E' TIPOCOMB!!!!

Motore::Motore(int _cilindrata): cilindrata(_cilindrata, Tipocomb tc){
	
	cout << "Creato motore di cilindrata : " << cilindrata << endl << endl;
}

ATTENZIONE -> gli oggetti associati devono essere inizializzati inlinea con la definizione del costruttore
se noi avessimo un costruttore a 0 parametri di tipocomb posso fare tipo = Tipocomb(_comb) perché si crea prima il
comb poi si crea il motore

*/
