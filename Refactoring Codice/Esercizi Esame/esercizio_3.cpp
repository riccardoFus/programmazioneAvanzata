/*
    Hai la classe A che è povera e possiede solamente un int i e un B* bp; rallegrale la giornata 
    donandole un costruttore a un parametro e una ridefinizione degli operatori +, -, ++ pre,
    ++ post, = (copia profonda, move)
*/
#include <iostream>
using namespace std;

class B{
    int x;
    public:
        B(int x){
            this->x = x;
        }
        ~B(){
            cout << "Distrutto B("<<this->x<<")" << endl;
        }
        int get_x(){
            return x;
        }
};

class A{
    int i;
    B* bp;
    public:
        A(int i){
            this->i = i;
            this->bp = NULL;
        }
        A(const A& a){
            this->i = a.i;
            if(a.bp != NULL){
                this->bp = new B(*(a.bp));
            }else{
                this->bp = NULL;
            }
        }
        A(A&& a){
            this->i = a.i;
            a.i = 0;
            this->bp = a.bp;
            a.bp = NULL;
        }
        ~A(){
            cout << "Distrutto A("<<this->i<<")" << endl;
            delete bp;
            bp = NULL;
        }
        A operator + (const A& a) const{
            return A(this->i + a.i);
        }
        A operator - (const A& a) const{
            return A(this->i - a.i);
        }
        A& operator ++ (){
            this->i++;
            return *this;
        }
        A operator ++ (int){
            A temp(*this);
            this->i++;
            return temp;
        }
        A& operator = (const A& a){
            this->i = a.i;
            if(this->bp == NULL){
                if(a.bp != NULL){
                    this->bp = new B(*(a.bp));
                }
            }else{
                if(a.bp != NULL){
                    (*this->bp) = *(a.bp);
                }else{
                    delete bp;
                    bp = NULL;
                }
            }
            return *this;
        }
        A& operator = (A&& a){
            this->i = a.i;
            a.i = 0;
            this->bp = a.bp;
            a.bp = NULL;
            return *this;
        }
        void aggiungi_bp(B* b){
            this->bp = b;
        }
};

int main(){
    A a1(10);
    B b1(14);
    a1.aggiungi_bp(&b1);
}