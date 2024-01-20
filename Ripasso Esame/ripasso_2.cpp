/*
    Questo file contiene l'esercizio dell'automobile, del combustibile e del motore,
    mostrato in entrambi i modi:
    1) con composizione
    2) con aggregazione
*/
#include <iostream>
#include <string>
using namespace std;

typedef enum{
    DIESEL, BENZINA, GPL 
} tipo_combustibile;

class Tipo_Combustibile{
    private:
        tipo_combustibile combustibile;
    public:
        Tipo_Combustibile(tipo_combustibile combustibile){
            this->combustibile = combustibile;
        }
        ~Tipo_Combustibile(){}
        friend ostream& operator << (ostream& os, const Tipo_Combustibile& tipo_combustibile);
};

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
        default:
            os << "?";
    }
    return os;
}

class Motore{
    private:
        int cilindrata;
        Tipo_Combustibile* tipo_1;
        Tipo_Combustibile* tipo_2;
    public:
        Motore(int cilindrata, Tipo_Combustibile* tipo){
            this->cilindrata = cilindrata;
            tipo_1 = tipo;
            tipo_2 = NULL;
        }
        ~Motore(){}
        void add_tipo_2(Tipo_Combustibile* tipo){
            tipo_2 = tipo;
        }
        friend ostream& operator << (ostream& os, const Motore& motore);
};

ostream& operator << (ostream& os, const Motore& motore){
    os << motore.cilindrata << " con combustibile " << *(motore.tipo_1);
    if(motore.tipo_2 != NULL){
        os << " e " << *(motore.tipo_2);
    }
    return os;
}

class Automobile{
    private:
        string marca, modello;
        Motore motore_composizione;
        Motore* motore_opzionale;
    public:
        Automobile(string marca, string modello, int cilindrata, Tipo_Combustibile* tipo): motore_composizione(cilindrata, tipo){
            this->marca = marca;
            this->modello = modello;
            this->motore_opzionale = NULL;
        }
        ~Automobile(){
            if(motore_opzionale != NULL){
                delete motore_opzionale;
            }
        }
        void add_motore_scorta(int cilindrata, Tipo_Combustibile* tipo_combustibile){
            motore_opzionale = new Motore(cilindrata, tipo_combustibile);
        }
        friend ostream& operator << (ostream& os, const Automobile& automobile);
};

ostream& operator << (ostream& os, const Automobile& automobile){
    os << automobile.marca << ", modello " << automobile.modello << endl;
    os << automobile.motore_composizione;
    if(automobile.motore_opzionale != NULL){
        os << " e " << *(automobile.motore_opzionale);
    }
    return os;
}

int main(){
    Tipo_Combustibile diesel(DIESEL), benzina(BENZINA), gpl(GPL);

    Automobile a1("Fiat", "Bravo", 1500, &gpl);
    cout << a1 << endl;
    a1.add_motore_scorta(1000, &benzina);
    cout << a1 << endl;
    
    return 0;
}