#include <cstdlib>
#include <iostream>
using namespace std;

class B;

class A{
private:
  int val;     
public:
  A(){val=1;} 
  bool operator == (const B& b)const;
  //lo devo implementare dopo la definizione della classe B 
  friend B; 
};


class B{
private:
  int val;      
public:
  B(){val=1;}
  bool operator == (const A& a)const{
    return val==a.val;   
  }    
  friend A;       
};

bool A::operator == (const B& b)const{
	return val==b.val; 
}
int main(int argc, char *argv[]){
 {
   A a;
   B b;
   if (a==b){cout<<"a==b"<<endl;}
   if (b==a){cout<<"b==a"<<endl;}
 }   
 system("PAUSE");    return EXIT_SUCCESS;
}
