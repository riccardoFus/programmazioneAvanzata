#include <iostream>
#include <string>
#include <list>
#include <stdexcept>
#include <vector>
using namespace std;

class VotoEsame{
    protected:
        string nome, cognome;
        float voto;
    public:
        VotoEsame(string nome, string cognome, float voto){
            if(voto < 0.0){
                throw invalid_argument("Voto minore di 0");
            }
            if(voto > 30.0){
                throw out_of_range("Voto maggiore di 30");
            }
            this->nome = nome;
            this->cognome = cognome;
            this->voto = voto;
        }
        virtual ~VotoEsame(){}
        virtual ostream& stampa(ostream& os) const{
            os << nome << " " << cognome << " " << voto;
            return os;
        }
        string get_nome() const{ return nome; }
        string get_cognome() const{ return cognome; }
        float get_voto() const{ return voto; }
        friend ostream& operator << (ostream& os, const VotoEsame& v);
};

ostream& operator << (ostream& os, const VotoEsame& v){
    return v.stampa(os);
}

class VotoOrale: public VotoEsame{
    private:
        int numDomande;
    public:
        VotoOrale(int numDomande, string nome, string cognome, float voto): VotoEsame(nome, cognome, voto){
            if(numDomande == 0){
                throw overflow_error("Numero di domande pari a 0");
            }
            this->numDomande = numDomande;
        }
        ~VotoOrale(){}
        ostream& stampa(ostream& os) const{
            os << nome << " " << cognome << " " << voto << " " << numDomande;
            return os;
        }
        friend ostream& operator << (ostream& os, const VotoOrale& v);
};

ostream& operator << (ostream& os, const VotoOrale& v){
    return v.stampa(os);
}

class VotoScritto: public VotoEsame{
    private:
        string aula;
    public:
        VotoScritto(string aula, string nome, string cognome, float voto): VotoEsame(nome, cognome, voto){
            this->aula = aula;
        }
        ~VotoScritto(){}
        ostream& stampa(ostream& os) const{
            os << nome << " " << cognome << " " << voto << " " << aula;
            return os;
        }
        friend ostream& operator << (ostream& os, const VotoScritto& v);
};

ostream& operator << (ostream& os, const VotoScritto& v){
    return v.stampa(os);
}

int main(){
    list<VotoEsame> lve;
    vector<VotoScritto> lvs;
    vector<VotoOrale> lvo;
    lvs.push_back(VotoScritto("T2", "Mario", "Bianchi", 22.0));
    lvs.push_back(VotoScritto("T1", "Lucia", "Verdi", 30.0));
    lvs.push_back(VotoScritto("T2", "Marco", "Rossi", 15.0));
    lvs.push_back(VotoScritto("T1", "Luca", "Gallo", 24.0));
    lvo.push_back(VotoOrale(3, "Mario", "Bianchi", 25.0));
    lvo.push_back(VotoOrale(4, "Lucia", "Verdi", 27.0));
    lvo.push_back(VotoOrale(2, "Luca", "Gallo", 15.0));
    for(const auto& vs : lvs){
        cout << vs << endl;
    }
    for(const auto& vo : lvo){
        cout << vo << endl;
    }
    for(const auto& vo : lvo){
        for(const auto& vs : lvs){
            if(vo.get_nome() == vs.get_nome() &&
               vo.get_cognome() == vs.get_cognome() &&
               vo.get_voto() + vs.get_voto() >= 18){
                try{
                    lve.push_back(VotoEsame(vo.get_nome(), vo.get_cognome(), vo.get_voto() + vs.get_voto()));
                }catch(const invalid_argument& e){
                    cout << e.what() << endl;
                    lve.push_back(VotoEsame(vo.get_nome(), vo.get_cognome(), 0));
                }catch(const out_of_range& e){
                    cout << e.what() << endl;
                    lve.push_back(VotoEsame(vo.get_nome(), vo.get_cognome(), 30));
                }
               }
        }
    }
    for(const auto& ve : lve){
        cout << ve << endl;
    }
}