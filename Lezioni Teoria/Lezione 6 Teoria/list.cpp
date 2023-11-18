#include <cstdlib>
#include <iostream>

using namespace std;

#include <list>

int main(int argc, char ** argv){
    list<int> l;
    l.push_back(2);
    l.push_front(3);

    list<int>::iterator it;  // c++98
    for(it = l.begin(); it != l.end(); ++it){
        cout << *it << " ";
    }

    cout << endl;

    for(auto a = l.begin(); a != l.end(); ++a){  // c++11 e succ.
        cout << *a << " ";
    }

    cout << endl;

    for(auto v : l){
        cout << v << " ";
    }

    cout << endl;

    for(auto& e : l){
        // modifico i valori nella lista!!
        e++;
    }

    cout << endl;

    for(auto v : l){
        cout << v << " ";
    }

    cout << endl;

    cout << l.front() << endl;
    cout << l.back() << endl;

    l.pop_back();
    l.pop_front();

    cout << l.front() << endl;
    cout << l.back() << endl;

    l.insert(l.begin(), 7);

    cout << endl;

    for(auto v : l){
        cout << v << " ";
    }

    l.insert(l.begin(), l.begin(), l.end());
    cout << endl;

    for(auto v : l){
        cout << v << " ";
    }
    cout << endl;

    auto a = l.cbegin(); // const iterator
    l.push_front(8);
    l.push_front(9);
    cout << endl;
    for(auto v : l){
        cout << v << " ";
    }
    cout << endl << *a;

    list<int> l2;
    l2.splice(l2.cbegin(), l, a, l.cend());
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }
    cout << endl << "l2:";
    for(auto v : l2){
        cout << " " << v;
    }

    cout << endl;

    /*
    l2.swap(l);
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }
    cout << endl << "l2:";
    for(auto v : l2){
        cout << " " << v;
    }
    */

    cout << l.size() << endl;
    cout << l.empty() << endl;

    l.reverse();
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }

    l.sort();
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }

    l.unique();
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }

    l.merge(l2);
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }
    cout << endl << "l2:";
    for(auto v : l2){
        cout << " " << v;
    }

    cout << endl;

    list<int>::reverse_iterator rit;
    for(rit = l.rbegin(); rit != l.rend(); ++rit){
        cout << *rit << " ";
    }
    cout << endl;

    for(auto a = l.rbegin(); a != l.rend(); ++a){
        cout << *a << " ";
    }
    cout << endl;

    l.resize(2);
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }

    l.remove(3);
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }

    l.erase(l.begin());
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }

    a = l.emplace(l.cbegin(), 11);
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }

    l2.assign(a, l.cend());
    cout << endl << "l2:";
    for(auto v : l2){
        cout << " " << v;
    }

    l.clear();
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }

    l = l2;
    cout << endl << "l:";
    for(auto v : l){
        cout << " " << v;
    }

    cout << endl << l.max_size();
    return 0;
}