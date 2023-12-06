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

template <class T1, class T2>
typename IF < sizeof(T1) < sizeof(T2), T2, T1>::Ret max(T1 a, T2 b){
    return a > b ? a : b;
}

int main(){
    cout << max(2, 3) << endl;
    cout << max(2, 2.3) << endl;
    cout << max(int(2), double(3.14)) << endl;
    cout << sizeof(double) << endl;
}