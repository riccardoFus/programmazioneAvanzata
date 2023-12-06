#include <iostream>
#include <algorithm>
using namespace std;

class My_class{
    private:
        int dim; int * data;
    public: 
        My_class(){
            dim = 10;
            data = new int[dim];
            cout << "Costruttore di default" << endl;
        }
        explicit My_class(int d){
            dim = d;
            data = new int[d];
            cout << "Costruttore specifico" << endl;
        }
        ~My_class(){
            if(data != NULL){
                delete [] data;
            }
            cout << "Distruttore" << endl;
        }
        My_class& operator = (const My_class& ogg){
            if(this == &ogg){
                return *this; // per evitare mc1 = mc1;
            }
            dim = ogg.dim;
            // delete [] data;
            data = new int [dim];
            copy(ogg.data, ogg.data + dim, data);
            cout << "Operator = " << endl;
            return *this;
        }
        My_class(const My_class& ogg){
            if(this == &ogg){
                return;
            }
            dim = ogg.dim;
            delete [] data;
            data = new int [dim];
            copy(ogg.data, ogg.data + dim, data);
            cout << "Costruttore copia" << endl;
        }
        My_class (My_class&& mc){
            dim = mc.dim;
            data = mc.data;
            mc.dim = 0;
            mc.data = NULL;
            cout << "Move Constructor" << endl;
        }
};

int main(int argc, char ** argv){
    /*
        My_class mc1(100);
        My_class mc2;
        My_class mc3 = mc1;
        mc1 = mc2;
        My_class mc4(mc2);
    */
    My_class mc5(move(My_class(20)));
    My_class mc6(50);
    My_class mc7(move(mc6));
    return 0;
}