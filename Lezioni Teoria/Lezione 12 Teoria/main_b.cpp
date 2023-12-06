#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main(int argc, char ** argv){
    vector<int> v(16);
    vector<function<float()>> v_functions(16);
    int j = 0;
    for(unsigned int i = 0; i < v.size(); i++){
        auto x = [&, j](int i){ return i * j; };
        v[i] = x(i);
        function<float()> f = [i, &j](){ return i / ( 1.0 * j ); };
        v_functions[i] = f;
        j += i;
    }

    for(auto x : v) cout << x << " ";
    cout << endl;

    for(auto x : v_functions) cout << x() << " ";
    cout << endl;
    return 0;
}