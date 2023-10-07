#include <cstdlib>
#include <iostream>

using namespace std;

int f1(int i){
	return i+1;
   //i=i*10;cout<<"i in f:"<<i<<endl;
   //return i+1;
 }//passaggio parametro per valore

int f2(int* pi){//(*pi)=57;
	return *pi+1;
}// passaggio per puntatore

int f3(int& i){//i=12;
	return i+1;
}//passaggio per riferimento

int f4(const int& i){
	//i=12; non compila per via di const
     return i+1;
}//passaggio per riferimento costante

// fare versioni delle funzioni precedente che utilizzino
//gli operatori ++ 
//postfisso
int f1b (int i) {return i++;}
int f2b (int* pi){return (*pi)++;}
int f3b (int& i) {return i++;}
//int f4b (const int& i){return i++;} // questo non funzionera'
//prefisso

int f1c (int i) {return ++i;}
int f2c (int* pi){return ++(*pi);}
int f3c (int& i) {return ++i;}

int main(int argc, char *argv[])
{  int j=3;
   cout<<j<<endl;
   cout<<"f1"<<f1(j)<<endl;
   cout<<j<<endl;// j non cambia
   cout<<"f2"<<f2(&j)<<endl;
   cout<<j<<endl;
   cout<<"f3"<<f3(j)<<endl;
   cout<<j<<endl;
   cout<<"f4"<<f4(j)<<endl;
   cout<<j<<endl;
   cout<<"chiamata con valore"<<endl;
   cout<<f1(7)<<f4(7)<<endl; //mentre f2(7) e f3(7) non compilano 
   
   cout<<"funzioni b"<<endl;
   cout<<j<<endl;
   cout<<f1b(j)<<endl;
   cout<<f2b(&j)<<endl;
   cout<<f3b(j)<<endl;
   cout<<j<<endl;
   
   cout<<"funzioni c"<<endl;
   cout<<j<<endl;
   cout<<f1c(j)<<endl;
   cout<<f2c(&j)<<endl;
   cout<<f3c(j)<<endl;
   cout<<j<<endl;
   int* p; //puntatore ad intero non inizializzato
   //cout<<"p"<<*p;
   //f2(p);
   //f2b(p);//cerco guai grossi
   int k; //non e' inizializzato
   cout<<"k"<<k<<endl;
   p=&j; //inizializzato
   p=new int(11);
   cout<<"f2 da puntatore"<<f2(p)<<endl;
   //p=&j;//NOOOOOOOOO!!!
   delete p;
    system("PAUSE");
    return EXIT_SUCCESS;
}
