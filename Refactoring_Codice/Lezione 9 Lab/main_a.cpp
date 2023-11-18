#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char ** argv){
    map<string, int> mappa_interi; // se implemento map<bool, int> -> massimo due valori, la chiave è univoca!!

    mappa_interi.insert(pair<string, int>("Mario", 34));
    mappa_interi.insert(pair<string, int>(string("Riccardo"), 20)); // per evitare che non venga chiamato il costruttore di string
    mappa_interi.insert(pair<string, int>("Anna", 29));
    mappa_interi.insert(pair<string, int>("Mario", 70)); // mario rimane 34

    map<string, int>::iterator iteratore;
    for(iteratore = mappa_interi.begin(); iteratore != mappa_interi.end(); iteratore++){
        cout << iteratore->first << " = " << iteratore->second << endl;
        iteratore->second++;
    }

    mappa_interi["Anna"] = 33; // mappa_interi.insert(pair<string, int>("Anna", 33)) ma questo sovrascrive
    // insert non permette la sovrascrittura
    mappa_interi["Luca"] = 22;

    for(const auto& coppia_chiave_valore : mappa_interi){
        cout << coppia_chiave_valore.first << " = " << coppia_chiave_valore.second << endl;
    }

    pair<string, int> coppia_da_aggiungere("Anna", 19);
    // mappa_interi.insert(coppia_da_aggiungere);

    cout << mappa_interi["Luca"] << endl;
    //cout << mappa_interi["Carlo"] << endl;

    if(mappa_interi.count("Carlo") > 0){
        cout << "TROVATO" << endl;
    }else{
        cout << "NON TROVATO" << endl;
    }

    iteratore = mappa_interi.find("Luca");
    if(iteratore == mappa_interi.end()){
        cout << "NON TROVATO" << endl;
    }else{
        cout << "TROVATO" << endl;
        mappa_interi.erase(iteratore);
    }

    for(const auto& coppia_chiave_valore : mappa_interi){
        cout << coppia_chiave_valore.first << " = " << coppia_chiave_valore.second << endl;
    }


    return 0;
}