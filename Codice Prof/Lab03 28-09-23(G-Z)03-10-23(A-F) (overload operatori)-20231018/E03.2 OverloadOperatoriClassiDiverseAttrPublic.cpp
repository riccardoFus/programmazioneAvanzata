#include <cstdlib>
#include <iostream>
using namespace std;
 
 
class A{ 
public: 
  int val;
  A(){ val=1; }
  bool A::operator == (const A& a) const { 
     return (a.val==val);
   } //se creato come metodo all'interno della classe A  
}; 
class B{
public: 
  int val;
  B(){ val=1; }
  bool B::operator == (const B& b) const { 
     return (b.val==val);
   } //se creato come metodo all'interno della classe A    
};

bool operator == (const A &a, const B &b){ 
     return (a.val==b.val);
}//   (metto friend se ho campi privati)

bool operator == (const B &b, const A &a){ 
     return (a.val==b.val);
}//   (metto friend se ho campi privati)


int main(int argc, char *argv[]){
   {
    A a; 
    B b; 
    if (a==b) { cout <<"a==b"<< endl;}
    if (b==a) { cout <<"b==a"<< endl;} 
    if (a==a) { cout <<"a==a"<< endl;}
    if (b==b) { cout <<"b==b"<< endl;}
   }
   system("PAUSE");  return EXIT_SUCCESS;
}
