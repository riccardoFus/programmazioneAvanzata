#include <iostream>
using namespace std;

template<int n, template<int> class F>
struct Accumulate{
    enum { RET = Accumulate<n-1, F>::RET + F<n>::RET};
};

template <template<int> class F>
struct Accumulate<0, F>{
    enum { RET = F<0>::RET };
};

template <int n>
struct Square {
    enum { RET = n*n };
};

template <int n>
struct Identity {
    enum { RET = n };
};

int main(){
    cout << Accumulate<3, Square>::RET << endl;
    cout << Accumulate<10, Identity>::RET << endl;
}