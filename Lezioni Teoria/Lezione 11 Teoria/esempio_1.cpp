#include <iostream>
using namespace std;

template<unsigned int n>
struct fact{
    enum{ value = n * fact<n-1>::value};
};

template <>
struct fact<0>{
    enum { value = 1};
};

int main(){
    cout << fact<7>::value << endl;
}