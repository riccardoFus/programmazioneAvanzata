#include <iostream>
#include <list>
using namespace std;

int main(int argc, char ** argv){
    list<int> l;
    l.push_back(4);
    for(auto a = l.begin(); a != l.end(); a++){
        cout << *a << " ";
    }
    cout << endl;
    l.emplace(l.cbegin(), 6);
    for(auto a : l){
        cout << a << " ";
    }
    cout << endl;

    const int& x = 6;

    int&& i = 7;
    i = 8;
    i = l.size();
    cout << i << endl;

    int j = 13;

    i = move(j++);

    i++;

    cout << i << endl;

    cout << j << endl;
}