#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
 
class A {
//se una proprietà è preceduta dalla parola static come opera il compilatore? 
//[RISPOSTA] unica copia della var x tutti oggetti della classe, esempio static int i=0;
 private:   
   int k;
   static int numIstanze; 
   static float temp;
   static const int a = 1; // can provide a value here (integral constant)
   static const float b;   // canNOT provide a value here (not integral)
   const float miaConst;
 public:
    //costruttore 0 parametri
    A():miaConst(10.5){ 
       numIstanze++; 
       cout <<"NumeroIstanze="<<numIstanze<<" miaConst="<<miaConst<<endl;
    } 
    
    A(int _k, float cf):miaConst(cf){
		//numinst=0;
		k=_k;
		numIstanze++;
		cout <<"NumeroIstanze="<<numIstanze<<" miaConst="<<miaConst<<endl;
	}
	A(const A& a):miaConst(a.miaConst) {
		k = a.k;
		numIstanze++;
		cout <<"NumeroIstanze="<<numIstanze<<" miaConst="<<miaConst<<endl;
	}
	A& operator = (const A& a){
		k = a.k;
		cout <<"NumeroIstanze="<<numIstanze<<" miaConst="<<miaConst<<endl;
		return *this; 
	}
    
    ~A(){ 
    	ofstream myfile;
    	myfile.open ("numIstanze.txt",ios::app);
    	/*
    	clf: http://www.cplusplus.com/doc/tutorial/files
    	ios::in	Open for input operations.
		ios::out	Open for output operations.
		ios::binary	Open in binary mode.
		ios::ate	Set the initial position at the end of the file.
		If this flag is not set, the initial position is the beginning of the file.
		ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.
		ios::trunc	If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
    	*/ 
  		myfile << numIstanze<< "\n";
  		myfile.close();
      numIstanze--; 
      cout <<"NumeroIstanze="<<numIstanze<<endl;
    } 
	//Static member functions can be used to work with static member variables in the class. An object of the class is not required to call them.
	static int getNI(){ return numIstanze; } 
	

    void print(){
         printf("print::k=%d, miaCostante=%5.2f \n",k,miaConst);
    }
                 

};
//inizializzazione attributi statici
int A::numIstanze=0; 
float A::temp=5.5;
const float A::b = 0.07f;

void stampa(A& a){
	a.print();	
}

int main(int argc, char *argv[]){
   {
    cout << A::getNI()<<endl;
    A a,b;
    a.print(); b.print();
    
    A a1(4,3.14);
	A a2(6,6.28);
	A a3;
	cout << a1.getNI() << endl;
	cout << a2.getNI() << endl;
	a3 = a2;
   }
   A a; //numero istanze uguale ad 1
   system("PAUSE");  return EXIT_SUCCESS;
}
