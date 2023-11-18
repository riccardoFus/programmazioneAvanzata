#include <iostream>
#include <string>
#include "tipocomb.h"
using namespace std;

Tipo_Combustibile::Tipo_Combustibile(tipo_combustibile _combustibile): combustibile(_combustibile){
    cout << "Creato combustibile " << *this << endl;
}

Tipo_Combustibile::~Tipo_Combustibile(){
    cout << "Distrutto combustibile " << *this << endl;
}

ostream& operator << (ostream& os, const Tipo_Combustibile& tipo_combustibile){
    switch(tipo_combustibile.combustibile){
        case DIESEL:
            os << "DIESEL";
            break;
        case BENZINA:
            os << "BENZINA";
            break;
        case GPL:
            os << "GPL";
            break;
    }
    return os;
}