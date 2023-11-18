#include "b.h"

B::B(string _s){
	s = _s;
	cout << "Costruttore a un parametro di B" << endl;
}

string B::get_s(){
	return s;
}
