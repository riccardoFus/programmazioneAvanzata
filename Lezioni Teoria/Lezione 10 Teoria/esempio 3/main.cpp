#include "a.h"
#include <cstdlib>
#include <iostream>
#include <list>
#include "a.h"
#include "b.h"
using namespace std;

int main(int argc, char ** argv){
    B b("prova");
    cout << b.get_s() << endl;
    cout << b.get_p() << endl;
    cout << b.get_s() << endl;
    cout << b.get_p() << endl;
    cout << b.get_s() << endl;
    cout << b.get_p() << endl;
}