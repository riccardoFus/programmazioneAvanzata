#include <iostream>
using namespace std;

class TestAtt{
    private:
        int i;
        static int si;
        const float cf;
        static const int sci;
        static const float scf;
    public:
        TestAtt(): i(0), cf(0.0){
            si++;
        }
        TestAtt(int i, float c): cf(c){
            this->i = i;
            si++;
        }
        TestAtt(const TestAtt& t): cf(t.cf){
            this->i = t.i;
            si++;
        }
        ~TestAtt(){
            si--;
        }
        static int get_si(){ return si; }
        friend ostream& operator << (ostream& os, const TestAtt& t);
};

ostream& operator << (ostream& os, const TestAtt& t){
    os << t.i << " " << t.si << " " << t.cf << " " << t.sci << " " << t.scf;
    return os;
}

int TestAtt::si = 0;
const int TestAtt::sci = 10;
const float TestAtt::scf = 126.0;

int main(){
    cout << TestAtt::get_si() << endl;
    TestAtt t1;
    cout << t1 << endl;
    TestAtt t2(10, 20.0);
    cout << t2 << endl;
    TestAtt t3(t2);
    cout << t3 << endl;
}