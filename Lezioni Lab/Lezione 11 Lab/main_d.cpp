#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void stampa(int n, char d){
    mtx.lock();
    for(int i = 0; i < n; i++){
        cout << d;
    }
    mtx.unlock();
}

int main(int argc, char ** argv){
    thread t_1(stampa, 10, 'x');
    thread t_2(stampa, 10, 'y');
    t_1.join(); 
    t_2.join();
    return 0;
}