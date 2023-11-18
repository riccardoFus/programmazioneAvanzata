#include <iostream>
#include "cliente.h"
#include "ordine.h"
using namespace std;

int main(int argc, char** argv){
    Cliente c(23);
    Ordine o1(1);
    Ordine o2(2);
    c.addOrdine(&o1);
    c.addOrdine(&o2);
    c.addOrdine2(3);
    cout << c << endl;
    return 0;
}