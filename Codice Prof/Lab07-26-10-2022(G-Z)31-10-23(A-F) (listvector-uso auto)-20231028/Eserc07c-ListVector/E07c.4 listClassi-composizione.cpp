#include <cstdlib>
#include <iostream>
#include <list> 
using namespace std;
class B{
 private:
  int dato;
 public:
   B(int _dato){dato=_dato; printf("B creato\n");}
   ~B(){printf("B distrutto (%d)\n",dato);}
   B(const B& b){dato = b.dato; printf("B copiato\n");}
   void stampa()const{printf("[%d]",dato);}
};
class A{
 private:
   list<B> listb;   //losanga piena (lista di istanze)
   list<B*> listpb; //losanga vuota (riferimenti ad istanze)
 public:
   A(){printf("A creato \n");} 
   ~A(){printf("A distrutto\n");}
   void addB(int dato){
     B b(dato);
     listb.push_back(b);
   }    
   void stampa(){//non mettere const
     list<B>::iterator iter;
     for(iter=listb.begin(); iter!=listb.end(); iter++){
        iter->stampa();   
     }    
     printf("\n");
   }
   friend ostream& operator <<(ostream &os, A& a);
};
ostream& operator <<(ostream &os, A& a){
 list<B>::iterator iter;
 for(iter=a.listb.begin(); iter!=a.listb.end(); iter++){
    iter->stampa();   
 }    
 printf("\n");        
}

int main(int argc, char *argv[]){
  {
   A a;
   a.addB(5);
   a.addB(2);
   a.addB(9);
   a.stampa();
   cout << a;
  }
  system("PAUSE");
  return EXIT_SUCCESS;
}
