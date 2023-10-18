#include <cstdlib>
#include <iostream>
using namespace std;

class A{       
  private:
    int* p;  
    int dim;      
  public:        
    A(){
       p = NULL; dim=0; cout<<"A::creato"<<endl;
    }
    A(int _dim){
       dim=_dim;   
       p = new int[dim]; cout<<"A::allocato vet "<<dim<<endl;    
    }  
	//Se eseguiamo questo programma col distruttore della classe A senza 
    //l'attributo virtual,il distruttore della classe B non viene 
    //richiamato ed abbiamo un caso tipico di memory leak.
    virtual ~A(){
       if (p!=NULL){     
         delete p; cout<<"A::deallocato vet "<<dim<<endl;
       }
       cout<<"A::distrutto"<<endl;
    } 
    virtual void stampa() const{
      if (p==NULL) { return; }      
      cout <<"A::";
      for(int i=0; i<dim;i++){
         printf("[%d]",p[i]);        
      } printf("\n");    
    }     
};
class B:public A{
  private:
    int* q;
    int dim;      
  public:        
    B(){
       q = NULL; dim=0; cout<<"B::creato"<<endl;
    }    
    B(int _dim){
       dim=_dim;   
       q = new int[dim]; cout<<"B::allocato vet "<<dim<<endl;    
    } 
    B(int dimB, int dimA):A(dimA){
       dim=dimB;
       q= new int[dim]; cout<<"B::allocato vet "<<dim<<endl;   
    }    
    ~B(){
       if (q!=NULL){ 
         delete q;cout<<"B::deallocato vet "<<dim<<endl;
       } 
       cout<<"B::distrutto"<<endl;
     }
    void stampa() const{
      if(q!=NULL){  
        cout <<"B::";    
        for(int i=0; i<10;i++){
          printf("[%d]",q[i]);        
        } printf("\n"); 
      } 
      cout <<"A::stampa()=>";  
      A::stampa(); 
    }           
};

int main(int argc, char *argv[]){
   { 
	A a(7); cout <<"a.stampa()=>"<< endl; a.stampa();
	B b(5,3); cout <<"b.stampa()=>"<< endl; b.stampa();
	a=b; cout <<"a=b.stampa()=>"<< endl; a.stampa();
	//b=a; non permesso
	
	system("PAUSE");
	
	A* x; 
	x = new B(7,3);//x = new B;
	
	cout << "x->stampa()" << endl;
	x->stampa();
	cout << "x->A::stampa()" << endl;
	x->A::stampa(); //chiamo esplicitamente metodo di A
	delete x;
	
	system("PAUSE");
	
	B miaB(3);
	A* y;
	y = &miaB;
	y->stampa();
   }
  system("PAUSE"); return EXIT_SUCCESS;
}
