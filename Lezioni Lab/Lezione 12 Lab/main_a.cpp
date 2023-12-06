#include <iostream>
#include <string>
using namespace std;

template <typename T>
T min_template(const T& a, const T& b){
    return a < b ? a : b;
}

int main(int argc, char ** argv){
    cout << min_template(10, 20) << endl;
    cout << min_template(20.0, 10.0) << endl;
    cout << min_template(string("Ciao"), string("Bella")) << endl;
    cout << min_template(4.23, 3.14) << endl;
    return 0;
}