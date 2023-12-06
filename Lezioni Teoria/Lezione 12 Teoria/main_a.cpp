#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;

int main(int argc, char ** argv){
    bitset<32> b;
    cout << b.size() << endl;
    cout << b << endl;
    string s = "101010011010101101001";
    cout << s << endl;
    b = bitset<32>(s);
    cout << b << endl;
    b <<= 4;
    cout << b << endl;
    cout << (b & (b << 3)) << endl;
    cout << (b | (b << 3)) << endl;
    istringstream(s) >> b;
    cout << b << endl;
    cout << ~b << endl;
    cout << b.to_ullong() << endl;
    cout << b.flip() << endl;
    b.reset(1);
    cout << b << endl;
    return 0;
}