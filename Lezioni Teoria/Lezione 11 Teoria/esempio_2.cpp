#include <iostream>
using namespace std;

template <bool condition, class Then, class Else>
struct IF{
    typedef Then Ret;
};

template <class Then, class Else>
struct IF<false, Then, Else>{
    typedef Else Ret;
};

int main(){
    IF < sizeof(int)<sizeof(long) , long, int>::Ret i;
    cout << sizeof(i) << endl;
}