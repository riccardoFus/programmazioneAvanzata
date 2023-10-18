#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
 
class A {
 private:   
   int k;
 public:
    //costruttore 0 parametri
    /*A(){ 
       k=0; 
       cout <<"costruttore 0 parametri k="<< k <<endl;
    }*/
    //costruttore 0 parametri con delega a costruttore specifico
    A():A(0){}
    //costruttore specifico
    A(int _k){
    	k=_k;
    	cout <<"costruttore specifico k="<< k <<endl;
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
  		myfile << k<< "\n";
  		myfile.close();
    } 
	
    //operatore di copia    
    A(const A& aa){
     k = aa.k;   
     cout <<"costruttore di copia k="<< k <<endl;
    } 
    //operatore assegnazione tra istanza della classe e numero intero
    A& operator = (const int _k){
      k=_k; cout << " operator = tra classe e int" << endl;
      return *this;
    }    
    //operatore assegnazione tra istanze della classe 
    A& operator = (const A& aa){
      k=aa.k; cout << " operator = tra classi" << endl;
      return *this;
    }
    A operator + (const A& aa) {
         A temp;
         printf("print+::k=%d, aa.k=%d \n",k,aa.k);
         temp.k = k + aa.k; 
         cout << " operator + tra classi" << endl;
         return temp;
     }
    
    A& operator += ( const A &obj ) {
      (*this).k += obj.k;          //oppure k += obj.k;
      cout << " operator += tra classi" << endl;
      return *this;
    } 
    //A++ postincremento 
    A operator ++(int) { 
      cout << " operator A++ per la classe" << endl;
      A a=*this; /*invoca costruttore di copia*/ k++; return a;
    } 
    //++A preincremento 
    A& operator ++() { 
       cout << " operator ++A per la classe" << endl;
       k++; return *this; 
    } 
    //A-- postdecremento
    A operator --(int) { 
      cout << " operator A-- per la classe" << endl;
      A a=*this; /*invoca costruttore di copia*/ k--; return a;
    }     
    //--A predecremento 
    A& operator --() { 
       cout << " operator ++A per la classe" << endl;
       k--; return *this; 
    } 
    //confronto tra istanze della classe
   /* bool operator==(const A& a) const{ 
         cout << " operator == tra classi" << endl;
         return (a.k == k); 
    }*/
    //disuguaglianza tra istanze della classe
    bool operator!=(const A& a) const{ 
         cout << " operator != tra classi" << endl;
         return (a.k != k); 
    }    
    void print(){
         printf("print::k=%d \n",k);
    }
                 
	friend bool operator == (const A& a1, const A& a2);
	friend ostream& operator << (ostream& os, const A& a);
};


bool operator == (const A& a1, const A& a2){
 cout << " funzione == tra classi" << endl;
 return (a1.k == a2.k); 
}

ostream& operator << (ostream& os, const A& a){
  return os <<  a.k;
}

int main(int argc, char *argv[]){
   {
   A a,b;
   a = 4;    //invoca operatore =
   b = 99;
   cout << "A=" << a << endl;
   a.print(); b.print();
   a++; a--;//A++ postincremento 
   a.print();
   ++a; //++A preincremento
   a.print();
   a=b;      //assegnazione tra classi
   if (a==b) { cout << "Main::istanze uguali"<<endl;} 
   a+=b;  a.print();
   if (a!=b) { cout << "Main::istanze diverse"<<endl;}
   a=a+b;  a.print();
   }
   A a; //numero istanze uguale ad 1
   system("PAUSE");  return EXIT_SUCCESS;
}
