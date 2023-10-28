#include <iostream>
#include <vector>
#include <algorithm>    // std::reverse
using namespace std;

//definizione tipo dato
class TipoDato{ 
private:
	int datoI;
	float datoF; 
public:
	TipoDato(){
		datoI=1; datoF=0.0;
	}
	TipoDato(int i, float f){
		datoI=i; datoF=f;
	}
	friend ostream& operator<<(ostream& os, const TipoDato& td);
};

ostream& operator<<(ostream& os, const TipoDato& td){
	os << "[" << td.datoI << " " << td.datoF << "] ";
	return os;
}


//definizione funzione
TipoDato foo()  { 
	return TipoDato(); 
}
	
int main(int argc, char** argv) {
	vector<int>s;
	vector<int>::iterator it;
	vector<int>::reverse_iterator rit;
	s.push_back(11);
	s.push_back(22);
	s.push_back(33);
	s.push_back(55);
	cout << "stampa con iterator:" << endl;;
	for (it = s.begin(); it!=s.end(); it++) {
		cout << "["<< *it << "] ";
	}
	cout << endl << endl;
	
	//utilizzo keyword auto
	cout << "utilizzo keyword auto" << endl;
	for (auto ita = s.begin(); ita != s.end(); ita++) {
		cout << "["<< *ita << "] ";
	}
	cout << endl << endl;

	cout << "stampa con reverse iterator:" << endl;;
	for (rit = s.rbegin(); rit!=s.rend(); rit++) {
		cout << "["<< *rit << "] ";
	}
	cout << endl << endl;
	
	//utilizzo keyword auto
	cout << "utilizzo keyword auto" << endl;
	for (auto ita = s.rbegin(); ita != s.rend(); ita++) {
		cout << "["<< *ita << "] ";
	}	
	cout << endl << endl;
	/*
	 Quanto è sicuro in questo caso l'uso della parola chiave auto? 
	 E se il tipo di vettore fosse float? string?
	 Un compilatore C++ sa qual è il tipo di un'espressione (di inizializzazione)!
	 
		for (int it=s.begin();it!=s.end();it++){
			cout<<*it<<endl;
		}
		[Error] cannot convert 'std::vector<int>::iterator {aka __gnu_cxx::__normal_iterator<int*, std::vector<int> >}' to 'int' in initialization
	*/

	//In C++11 si può scrivere
	cout << "utilizzo keyword auto for c++11" << endl;
	for (auto& it : s) {
	    cout << "["<< it << "] ";
	}
	cout << endl;
	
	reverse( s.begin(),s.end() );	//libreria algorithm

	for (auto& it : s ) {
	    cout << "["<< it << "] ";
	}
	cout << endl;
	/*
		La parola chiave auto ottiene il tipo dall'espressione a destra dell' =. 
		Pertanto funzionerà con qualsiasi tipo, l'unico requisito è inizializzare la variabile auto 
		quando la dichiara in modo che il compilatore possa dedurre il tipo.
	*/
	
	auto a = 0.0f;  // a is float
	auto b = std::vector<int>();  // b is std::vector<int>()
	
	//con le funzioni: invocazione funzione
	auto c = foo();  // c is TipoDato
	cout << c;
	
	return 0;
}
