#include <iostream>
using namespace std;

class Person { 
   // Data members of person  
public: 
    Person(int x)  { cout << "Person::Person(int ) called" << endl;   } 
    Person()     { cout << "Person::Person() called" << endl;   } 
}; 
  
class Faculty: virtual public Person { 
   // data members of Faculty 
public: 
    Faculty(int x):Person(x)   { 
       cout<<"Faculty::Faculty(int ) called"<< endl; 
    } 
}; 
  
class Student: virtual public Person { 
   // data members of Student 
public: 
    Student(int x):Person(x) { 
        cout<<"Student::Student(int ) called"<< endl; 
    } 
}; 
  
class TA: public Faculty, public Student  { 
public: 
    /*TA(int x):Student(x), Faculty(x)   { 
        cout<<"TA::TA(int ) called"<< endl; 
    } */
	/*
	 In generale, non è consentito chiamare direttamente il costruttore del nonno, deve essere chiamato tramite la classe genitore. 
	 È consentito solo quando viene utilizzata la parola chiave "virtuale".
	*/  
    TA(int x):Student(x), Faculty(x), Person(x)    { 
        cout<<"TA::TA(int ) called"<< endl; 
    } 	  
}; 
   
  
int main(int argc, char** argv) {
	TA ta1(30); 
	/*
	  Il costruttore di "Person" viene chiamato due volte. 
	  Il distruttore di "Persona" verrà anche chiamato due volte quando l'oggetto "ta1" viene distrutto. 
	  Quindi l'oggetto "ta1" ha due copie di tutti i membri di "Persona", questo causa ambiguità. 
	  La soluzione a questo problema è la parola chiave "virtuale". 
	  Rendiamo le classi "Facoltà" e "Studente" come classi di base virtuali per evitare due copie di "Persona" nella classe "AT". 
	  Modifiche:
	  class Faculty : virtual public Person
	  class Student : virtual public Person
	  + add Person() 
      Ora il costruttore di "Persona" viene chiamato una volta. 
	  Una cosa importante da notare nell'output sopra è che viene chiamato il costruttore predefinito di "Persona". 
	  Quando usiamo la parola chiave 'virtual', il costruttore predefinito della classe grandparent viene chiamato 
	  per impostazione predefinita anche se le classi genitore chiamano esplicitamente il costruttore parametrizzato.	  
	*/
	
	return 0;
}
