#include <atomic>
#include <iostream>
#include <thread>
using namespace std;

// static int condivisa = 0;
static std::atomic<int> condivisa(0);

void inc_thread(){
    for(int i = 0; i < 100000; i++) condivisa++;
}

void dec_thread(){
    for(int i = 0; i < 100000; i++) condivisa--;
}

int main(){
    std::thread inc(inc_thread);
    std::thread dec(dec_thread);

    inc.join();
    dec.join();

    cout << "Condivisa : " << condivisa << endl;
    return 0;
}