#include "a.h"

A::A(){
	i = 0;
	pb = NULL;
	cout << "Costruttore a zero parametri di A" << endl;
}

A::A(int _i, string _s){
	i = _i;
	pb = new B(_s);
	cout << "Costruttore a due parametri di A" << endl;
}

A::A(const A& _a){
	i = _a.i;
	if(_a.pb != NULL){
		pb = new B(*(_a.pb));
	}else{
		pb = NULL;
	}
	cout << "Costruttore di copia di A" << endl;
}

A& A::operator =(const A& _a){
	i = _a.i;
	if(this->pb == NULL){
		if(_a.pb != NULL){
			pb = new B(*(_a.pb));
		}
	}else{
		if(_a.pb != NULL){
			(*pb) = * (_a.pb);
		}else{
			delete pb;
			pb = NULL;
		}
	}
	cout << "Operator = di A" << endl;
	return *this; 
}

A::~A(){
	if(pb != NULL) delete pb;
	cout << "Distruttore di A" << endl;
}

int A::get_i(){
	return i;
}

string A::get_s(){
	if(pb != NULL){
		return pb->get_s();
	}else{
		return "";
	}
}

void A::set_s(string _s){
	if(pb == NULL){
		pb = new B(_s);
	}else{
		(*pb) = B(_s);
	}
}
