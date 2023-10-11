#include <iostream>
using namespace std;

template <typename F, typename S>
class Pair{
	public:
		Pair(const F& f, const S& s){
			first = f;
			second = s;
		}
		F get_first() const {
			return first;
		}
		S get_second() const {
			return second;
		}
	private:
		F first;
		S second;
};
/*
Pair<F,S>::Pair(const F& f, const F& s){
	first = f;
	second = s;
}

F Pair<F,S>::get_first() const {
	return first;
}

S Pair<F, S>::get_second() const {
	return second;
}
*/

int main(){
	Pair<string, int> p("Enrico", 15);
	cout << p.get_first() << "  " << p.get_second() << endl;
	return 0;
}
