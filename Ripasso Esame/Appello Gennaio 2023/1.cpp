#include <iostream>
using namespace std;

template <bool condition, class Then, class Else>
struct IF{
    typedef Then RET;
};

template <class Then, class Else>
struct IF<false, Then, Else>{
    typedef Else RET;
};

template <class T1, class T2>
typename IF<sizeof(T1) < sizeof(T2), T2, T1>::RET minimo(T1 a, T2 b){
    return a <= b ? a : b;
}

int main(){
    cout << minimo(3, 2) << endl;
    cout << minimo(3.9, 4.0) << endl;
    cout << minimo(3.0, 2) << endl;
    cout << minimo(3, 2.0) << endl;
    cout << minimo(string("Riccardo"), string("Alessandro")) << endl;
}