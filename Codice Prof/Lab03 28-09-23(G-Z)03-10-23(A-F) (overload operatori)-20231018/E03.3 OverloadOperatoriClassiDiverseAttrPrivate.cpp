#include <cstdlib>
#include <iostream>
using namespace std;

class B;

class A{
private:
  int val;     
public:
  A(){val=1;} 
  bool operator == (const A& a)const{
    return val==a.val;   
  }  
  friend bool operator == (const A& a, const B& b); 
  friend bool operator == (const B& b, const A& a);         
};

class B{
private:
  int val;      
public:
  B(){val=1;}
  bool operator == (const B& b)const{
    return val==b.val;   
  } 
  friend bool operator == (const A& a, const B& b); 
  friend bool operator == (const B& b, const A& a);            
};

bool operator == (const A& a, const B& b){
    return a.val==b.val;   
}  
bool operator == (const B& b, const A& a){
    return a.val==b.val;   
	//return a==b;
} 

int main(int argc, char *argv[]){
 {
   A a;
   B b;
   if (a==a){cout<<"a==a"<<endl;}
   if (b==b){cout<<"b==b"<<endl;}
   if (a==b){cout<<"a==b"<<endl;}
   if (b==a){cout<<"b==a"<<endl;}
 }   
 system("PAUSE");    return EXIT_SUCCESS;
}
