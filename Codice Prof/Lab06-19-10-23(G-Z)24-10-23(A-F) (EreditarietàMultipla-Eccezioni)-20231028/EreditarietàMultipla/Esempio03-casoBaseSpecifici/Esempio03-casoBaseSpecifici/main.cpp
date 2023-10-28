#include <iostream>
using namespace std;

class Studente{
protected:
	int datoStudente;
public:	
	Studente(int d){
		datoStudente=d;
		cout << "Creato Studente " << datoStudente<<endl;
	}
	~Studente(){
		cout << "Distrutto Studente " << datoStudente<<endl;
	}
};
class Lavoratore{
protected:
	int datoLavoratore;
public:
	Lavoratore(int d){
		datoLavoratore = d;
		cout << "Creato Lavoratore " << datoLavoratore<<endl;
	}
	~Lavoratore(){
		cout << "Distrutto Lavoratore " << datoLavoratore<<endl;
	}
};
class StudenteLavoratore: public Studente, public Lavoratore{
private:
public:
	StudenteLavoratore(int ds, int dl):Studente(ds),Lavoratore(dl){
		cout << "Creato StudenteLavoratore " <<endl;
	}
	~StudenteLavoratore(){
		cout << "Distrutto StudenteLavoratore " <<endl;
	}
};


int main(int argc, char** argv) {
	StudenteLavoratore sl(3,7);
	
	return 0;
}
