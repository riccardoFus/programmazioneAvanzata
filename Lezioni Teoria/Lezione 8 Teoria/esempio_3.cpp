#include <iostream>
#include <thread>
using namespace std;

void f1(){
    cout << "Ciao f1" << endl;
}

void f2(int x){
    cout << "Ciao f2 " << x <<  endl;
}

int main(){
    unsigned int c = std::thread::hardware_concurrency();
    cout << "Numero di core: " << c << endl;

    std::thread first(f1);
    std::thread second(f2, 0);

    cout << "main, f1 e f2 lanciati..." << endl;

    first.join();
    second.join();
    
    cout << "f1 e f2 completati" << endl;
    return 0;
}