#ifndef TIPOCOMB_H
#define TIPOCOMB_H
#include <iostream>
using namespace std;

typedef enum {
    DIESEL, BENZINA, GPL
} tipo_combustibile;

class Tipo_Combustibile{
    private:
        tipo_combustibile combustibile;
    public:
        Tipo_Combustibile(tipo_combustibile _combustibile);
        ~Tipo_Combustibile();
        friend ostream& operator << (ostream& os, const Tipo_Combustibile& tipo_combustibile);
};

ostream& operator << (ostream& os, const Tipo_Combustibile& tipo_combustibile);

#endif