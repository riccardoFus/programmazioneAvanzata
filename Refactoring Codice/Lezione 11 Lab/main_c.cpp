#include <iostream>
#include <thread>
using namespace std;

void stampa(int valore){
    cout << valore << endl;
}

void test(){
    // 0000 e 1111 sono separabili
    cout << "0000" << "1111" << endl;
}

class Test{
    private:
        int d;
    public:
        Test(){
            d = 1;
        }
        void stampa(int val) const {
            cout << val << endl;
        }
        void operator() (int val) { cout << val << endl; }
};

int main(int argc, char ** argv){
    thread thread_1(stampa, 4);
    thread thread_2(test);
    cout << "RUN" << endl;
    thread_1.join();
    thread_2.join();
    cout << "END" << endl;

    Test test_oggetto;
    thread thread_3(&Test::stampa, &test_oggetto, 10);
    thread_3.join();

    // bisogna definire l'operatore ()
    thread thread_4(test_oggetto, 10);
    thread_4.join();

    auto lambda_expr = [](int d){ cout << d << endl; };
    thread thread_5(lambda_expr, 10);
    thread_5.join();

    // cenno ref(v) quando si usano thread e references
    return 0;
}