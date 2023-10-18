#include <cstdlib>
#include <iostream>
#include "Automobile.h"
using namespace std;

int main() {
	Automobile autoSbanda("Fiat", "Sbanda", COMB_GAS, 1400);
	autoSbanda.stampa();

	autoSbanda.immatricola("AB-123-CD");
	autoSbanda.stampa();

	autoSbanda.accendi();
	autoSbanda.stampa();
	
	autoSbanda.accelera();
	autoSbanda.stampa();

	autoSbanda.accelera();
	autoSbanda.stampa();

	autoSbanda.ferma();
	autoSbanda.stampa();

	autoSbanda.spegni();
	autoSbanda.stampa();
	cout << "=================" << endl;
	cout << autoSbanda << endl;

	return 0;
}

