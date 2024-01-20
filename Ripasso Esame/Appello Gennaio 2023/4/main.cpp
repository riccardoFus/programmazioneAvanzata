#include <iostream>
#include <map>
#include <string>
#include "negozio.h"
#include "vendita.h"
using namespace std;

int main(){
    map<int, Negozio> negozi;
    negozi[1] = Negozio(1, "ScarpONE");
    negozi[2] = Negozio(2, "pastaTop");
    negozi[1].addVendita(string("ciabatta"), 3, 154.56);
    negozi[1].addVendita(string("mocassimo"), 8, -22.60);
    negozi[2].addVendita(string("penne"), -3, 3.60);
    negozi[2].addVendita(string("maccheroni"), 0, 4.05);
    for(const auto& i : negozi){
        cout << "CHIAVE : " << i.first << ", " << i.second << endl;
    }
}