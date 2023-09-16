#include<iostream>
using namespace std;
class A{
public:
 ~A(){
  cout<<"distruttore di A";
  };
};

main(){
A a;
//invocazione esplicata del distruttore
a.~A();

}
