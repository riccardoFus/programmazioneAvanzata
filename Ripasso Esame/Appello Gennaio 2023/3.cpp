#include <iostream>
#include <thread>
#include <algorithm>
#include <list>
#include <functional>
#include <numeric>
#include <mutex>
using namespace std;

mutex mtx;

int random(){
    return rand()%5+1;
}

void stampa_lista(const list<int>& l){
    mtx.lock();
    for(const auto& i : l){
        cout << i << " ";
    }
    cout << endl;
    mtx.unlock();
}

void initList(list<int>& l){
    mtx.lock();
    generate(l.begin(), l.end(), &random);
    mtx.unlock();
}

void somma(list<int>& l, const int& sum){
    mtx.lock();
    transform(l.begin(), l.end(), l.begin(), [&sum](int& x){ return x + sum; });
    mtx.unlock();
}

void prodotto(list<int>& l){
    mtx.lock();
    cout << accumulate(l.begin(), l.end(), 1, multiplies()) << endl;
    mtx.unlock();
}

int main(){
    srand(time(NULL));
    list<int> li(5);
    stampa_lista(li);
    initList(li);
    std::thread t1(somma, ref(li), 10);
    std::thread t2(prodotto, ref(li));
    t1.join(); t2.join();
    stampa_lista(li);
}