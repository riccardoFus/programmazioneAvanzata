#include <iostream>
#include <memory>
using namespace std;

int main(int argc, char ** argv){
    unique_ptr<int> p, p1;
    p.reset(new int(54));
    cout << *p << endl;
    p1.reset(new int(23));
    cout << *p1 << endl;
    p1 = move(p);
    // cout << *p << endl;
    cout << *p1 << endl;
}