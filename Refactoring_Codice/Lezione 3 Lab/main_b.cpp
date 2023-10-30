#include <iostream>
using namespace std;

class B;
class A{
    private:
        int valore;
    public:
        A(){
            valore = 1;
        }
        bool operator == (const A& a) const{
            return valore == a.valore;
        }
        bool operator != (const A& a) const{
            return !(*this == a);
        }
        bool operator == (const B& b) const;
        // friend bool operator == (const A& a_1, const A& a_2);
        friend bool operator == (const B& b, const A& a);
};

class B{
    private:
        int valore;
    public:
        B(){
            valore = 2;
        }
        friend bool operator == (const B& b, const A& a);
        friend A;
};

/*
bool operator == (const A& a_1, const A& a_2){
    return a1.val == a2.val;
}

bool operator != (const A& a_1, const A& a_2){
    return !(a1 == a2);
}
*/

bool A::operator == (const B& b) const{
    return valore == b.valore;
}

bool operator == (const B& b, const A& a){
    return b.valore == a.valore;
}

int main(int argc, char ** argv){
    A a_1, a_2;
    B b_1, b_2;

    if(a_1 == a_2){
        cout << "Istanze di A uguali" << endl;
    }else{
        cout << "Istanze di A diverse" <<endl;
    }

    if(a_1 != a_2){
        cout << "Istanze di A diverse" << endl;
    }else{
        cout << "Istanze di A uguali" << endl;
    }

    if(b_1 == a_1){
        cout << "Istanze di B e A uguali" << endl;
    }else{
        cout << "Istanze di B e A diverse" << endl;
    }

    if(a_1 == b_1){
        cout << "Istanze di B e A uguali" << endl;
    }else{
        cout << "Istanze di B e A diverse" << endl;
    }

    return 0;
}