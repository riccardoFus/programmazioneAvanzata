/*
    Crea una classe Ciabatta{} e fa in modo che sia stampabile tramite cout. Sappi che la ciabatta
    non ha per forza dei piedi al suo interno ma spesso li ha, crea quindi una lista di piedi nella
    ciabatta, ma creala nell'heap. Implementa quindi tutti i metodi che servono per le occasioni come
    queste (quando vai a mettere piede nello heap)
*/
#include <iostream>
#include <list>
using namespace std;

class Piede{
    private:
        int taglia;
    public:
        Piede(int t): taglia(t){}
        ~Piede(){ cout << "Eliminato Piede" << endl; }
        int get_taglia() const { return taglia; }
};

class Ciabatta{
    private:
        list<Piede*> piedi;
    public:
        Ciabatta(){
            cout << "Creata ciabatta" << endl;
        }
        Ciabatta(const Ciabatta& c){
            for(Piede* piede : c.piedi){
                piedi.push_back(new Piede(*piede));
            }
        }
        Ciabatta(Ciabatta&& c){
            piedi = c.piedi;
            c.piedi.clear();
        }
        ~Ciabatta(){
            for(Piede* piede : piedi){
                delete piede;
            }
            piedi.clear();
            cout << "Distrutta Ciabatta" << endl;
        }
        void add_piede(Piede* p){
            piedi.push_back(p);
        }
        friend ostream& operator << (ostream& os, const Ciabatta& c);
};
        
ostream& operator << (ostream& os, const Ciabatta& c){
    if(c.piedi.size() > 0){
        os << "La ciabatta e' indossata da " << c.piedi.size() << " piede/i" << endl;
        for(Piede* piede : c.piedi){
            os << piede->get_taglia() << " ";
        }
    }
    return os;
}

int main(int argc, char ** argv){
    Ciabatta c1;
    c1.add_piede(new Piede(39));
    c1.add_piede(new Piede(39));
    cout << c1 << endl;
    Ciabatta c2(c1);
    cout << c2 << endl;
    Ciabatta c3(move(c1));
    cout << c3 << endl;
}