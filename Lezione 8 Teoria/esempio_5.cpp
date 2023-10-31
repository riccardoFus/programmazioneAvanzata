#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex my_mutex;
static int condivisa = 0;

void inc_thread(){
    for(int i = 0; i < 100000; i++){
        my_mutex.lock(); condivisa++; my_mutex.unlock();
    }
}

void dec_thread(){
    for(int i = 0; i < 100000; i++){
        my_mutex.lock(); condivisa--; my_mutex.unlock();
    }
}

void print_block(int n, char c){
    my_mutex.lock();
    for(int i = 0; i < n; ++i){
        cout << c;
    }
    cout << endl;
    my_mutex.unlock();
}

void thread_function(){
    std::lock_guard<std::mutex> guard(my_mutex);
    std::thread::id this_id = std::this_thread::get_id();
    cout << "Sono il thread " << this_id << endl;
}

int main(){
    std::thread inc(inc_thread);
    std::thread dec(dec_thread);

    inc.join();
    dec.join();

    cout << "Condivisa : " << condivisa << endl;

    std::thread th1(print_block, 50, '*');
    std::thread th2(print_block, 70, '&');

    th1.join();
    th2.join();

    std::thread t1(thread_function);
    std::thread t2(thread_function);
    std::thread t3(thread_function);
    std::thread t4(thread_function);

    t1.join(); t2.join(); t3.join(); t4.join();

    return 0;
}