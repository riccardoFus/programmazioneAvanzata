#include <cstdlib>
#include <iostream>
#include "persona.h"
#include "studente.h"
using namespace std;

int main(int argc, char *argv[])
{
 {
 Persona P("Giovanni", "Verdi", 76);
 P.set_nome("anna");
 P.Stampa();
 Studente S("Mario", "Rossi",123456, 23);
 S.Stampa();
 S.CambiaNome("Maria");
 S.Stampa();
 }
 
 system("PAUSE");
 return EXIT_SUCCESS;
}
