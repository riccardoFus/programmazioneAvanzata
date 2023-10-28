#include <cstdlib>
#include <iostream>
using namespace std;

class Studente{
private:
 int datoStudente;
public: 
  Studente(){ 
  	datoStudente=0; 
	cout <<"creato Studente="<<datoStudente<<endl;
  }  
  ~Studente(){
  	cout <<"distrutto Studente="<<datoStudente<<endl;
  }
  void stampa()const{ cout <<"datoStudente="<<datoStudente<<endl;}        
};

class Lavoratore{
private:
 int datoLavoratore;
public: 
  Lavoratore(){ 
  	datoLavoratore=999; 
	cout <<"creato Studente="<<datoLavoratore<<endl;  
  } 
  ~Lavoratore(){
  	cout <<"distrutto Lavoratore="<<datoLavoratore<<endl;
  } 	
  void stampa()const{ cout <<"datoLavoratore="<<datoLavoratore<<endl;}      
};

class StudenteLavoratore:public Studente,public Lavoratore{
private:
public: 
	StudenteLavoratore(){ cout <<"creato StudenteLavoratore"<<endl;  }
	~StudenteLavoratore(){ cout <<"distrutto StudenteLavoratore"<<endl; } 
};

int main(int argc, char *argv[]){
	{
    Studente s1;
    s1.stampa();
    Lavoratore l1;
    l1.stampa(); 
	cout << "==============" << endl;  
    StudenteLavoratore sl;
    //sl.stampa(); //ambiguo!!!!
    sl.Studente::stampa();  //non ambiguo!!!
	}
    system("PAUSE");  return EXIT_SUCCESS;
}
