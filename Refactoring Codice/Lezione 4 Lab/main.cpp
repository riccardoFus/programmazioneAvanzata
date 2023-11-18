#include <iostream>
#include "automobile.h"
#include "tipocomb.h"
using namespace std;

int main(int argc, char ** argv){
    /*
    Tipo_Combustibile c1(DIESEL);
    cout << c1 << endl << endl;
    Motore m1(100, GPL);
    cout << m1 << endl << endl;
    */
    Tipo_Combustibile diesel(DIESEL), benzina(BENZINA), gpl(GPL);

    Automobile a_1("Fiat", "Bravo", 1500, &gpl);
    cout << a_1 << endl;

    a_1.add_motore_scorta(1000, &benzina);

    Automobile a_2("TestaRossa", "Ferrari", 4000, &gpl);
    return 0;
}