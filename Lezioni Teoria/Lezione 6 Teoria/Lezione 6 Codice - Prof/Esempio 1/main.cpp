#include <cstdlib>
#include <iostream>

using namespace std;

#include "film.h"
#include "spettatore.h"
#include "cineteca.h"
int main(int argc, char *argv[])
{   test_film();
    test_spettatore();
    test_cineteca();
    system("PAUSE");
    return EXIT_SUCCESS;
}
