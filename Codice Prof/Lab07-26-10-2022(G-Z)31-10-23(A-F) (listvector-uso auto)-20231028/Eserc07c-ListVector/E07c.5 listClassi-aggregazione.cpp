#include <cstdlib>
#include <iostream>
#include <list> 
using namespace std;
class A;
class B{
 private:
  int dato;
 public:
   B(int _dato){dato=_dato; printf("B creato\n");}
   ~B(){printf("B distrutto (%d)\n",dato);}
   B(const B& b){dato = b.dato; printf("B copiato\n");}
   void stampa()const{printf("[%d]",dato);}
   friend ostream& operator <<(ostream &os, B& b); 
   friend ostream& operator <<(ostream &os, A& a);         
};
ostream& operator <<(ostream &os, B& b){
   os << "[" << b.dato << "]";  
   return os;      
}

class A{
 private:
   list<B*> listpb; //losanga vuota (riferimenti ad istanze)
 public:
   A(){printf("A creato \n");} 
   ~A(){printf("A distrutto\n");}
   void addB(B* b){
     listpb.push_back(b);
   }    
   void stampa(){//non mettere const
     list<B*>::iterator iter;
     for(iter=listpb.begin(); iter!=listpb.end(); iter++){
          (*iter)->stampa();
     }    
     printf("\n");
   }
   friend ostream& operator <<(ostream &os, A& a); 
};
ostream& operator <<(ostream &os, A& a){
   list <B*>::iterator piter;
   for(piter=a.listpb.begin(); piter!=a.listpb.end(); ++piter){
      os << **piter; 
                            
   }
   return os;      
}
int main(int argc, char *argv[]){
  {
   B b1(5);
   B b2(2);
   B b3(9);
   A a;     
   a.addB(&b1);
   a.addB(&b2);
   a.addB(&b3);
   a.stampa();
   cout << a << endl;
  }
  system("PAUSE");
  return EXIT_SUCCESS;
}
