#include <iostream>
#include "cliente.h"
#include "ordine.h"
using namespace std;

int main(int argc, char ** argv){
    Cliente c(33);
    Ordine o1(1);
    Ordine o2(2);
    c.add_ordine_vettore(&o1);
    c.add_ordine_vettore(&o2);
    c.add_ordine_lista(3);
    cout << c << endl;
    return 0;
}