/*
    Crea una lambda expression stampaBizzarra che riceve in input una stringa e un
    intero n e stampa la stringa n volte; crea due thread a cui passi questa funzione con le stringhe "tanti"
    e "ionico"; assicurati che non ci siano inconsistenze nelle stampe
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <string>
using namespace std;

mutex my_mutex; 

int main(int argc, char ** argv){
    auto stampaBizzarra = [](string parola, int n){
        my_mutex.lock();
        for(int i = 0; i < n; i++){
            // my_mutex.lock();
            cout << parola << " ";
            // my_mutex.unlock();
        }
        cout << endl;
        my_mutex.unlock();
    };
    thread t1(stampaBizzarra, "tanti", 10);
    thread t2(stampaBizzarra, "ionico", 10);
    t1.join(); t2.join();
    return 0;
}