#include <iostream>
#include <string>
using namespace std;

void my_swap (int &f, int &s){
	int tmp = f;
	f = s;
	s = tmp;
}

void my_swap (string &f, string &s){
	string tmp = f;
	f = s;
	s = tmp;
}

/* 
void my_swap (void* &f, void* &s){
	void* tmp = f;
	f = s;
	s = tmp;
}
*/

template <class T>
void my_swap(T& f, T& s){
	T tmp = f;
	f = s;
	s = tmp;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string a = "Hello";
	string b = "World";
	cout << "Before a = " << a << " and b = " << b << endl;
	my_swap(a,b);
	cout << "After a = " << a << " and b = " << b << endl;
	void* d1 = new double(7.0);
	void* d2 = new double(3.0);
	// my_swap(d1, d2); compile time error, no know conversation from double to &int
	/*
	// C-style casting
	cout << "Before d1 = " << *((double*)d1) << " and d2 = " << *((double*)d2) << endl;
	my_swap(d1, d2);
	cout << "After d1 = " << *((double*)d1) << " and d2 = " << *((double*)d2) << endl;
	
	// static_casting
	cout << "Before d1 = " << *(static_cast<double*>(d1)) << " and d2 = " << *(static_cast<double*>(d2)) << endl;
	my_swap(d1, d2);
	cout << "After d1 = " << *(static_cast<double*>(d1)) << " and d2 = " << *(static_cast<double*>(d2)) << endl;
	*/
	
	int x = 150, y = 23;
	cout << "Before x = " << x << " and y = " << y << endl;
	my_swap<int>(x,y);
	cout << "After x = " << x << " and y = " << y << endl;	
	return 0;
}
