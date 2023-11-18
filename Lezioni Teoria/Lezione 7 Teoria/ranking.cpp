#include "ranking.h"

bool short_name(string _s){
    if(_s.length() < 4){
        return true;
    }else{
        return false;
    }
}

void Ranking::add_item_back(string _s){
    if(s.find(_s) == s.end()){
        l.push_back(_s);
        s.insert(_s);
    }
}

void Ranking::compare(const Ranking& _r) const{
    pair<list<string>::const_iterator, list<string>::const_iterator> p;
    p = mismatch(l.begin(), l.end(), _r.l.begin());
    cout << endl << "compare mismatch: " << *p.first <<  " " << *p.second;

    list<string>::const_iterator it3 = ++(++(++(l.begin())));
    cout << endl << "compare equal: " << equal(l.begin(), it3, _r.l.begin());

    cout << endl << "compare is_permutation: " << is_permutation(l.begin(), l.end(), _r.l.begin());
}

void Ranking::properties() const{
    list<string>::const_iterator it;
    list<string>::const_iterator it3 = ++(++(++(l.begin())));
    int i = count_if(l.begin(), l.end(), short_name);
    // short_name -> controlla se la stringa è più piccola di 4
    cout << endl << "properties count_if: " << i;

    i = count_if(l.begin(), it3, short_name);
    cout << endl << "properties count_if*: " << i;

    it = find_if(l.begin(), it3, short_name);
    cout << endl << "properties find_if: " << *it;

    cout << endl << "properties all_of: " << all_of(l.begin(), l.end(), short_name);
    cout << endl << "properties any_of: " << any_of(l.begin(), l.end(), short_name);
    cout << endl << "properties none_of: " << none_of(l.begin(), l.end(), short_name);
}

void Ranking::modify(){
    list<string>::iterator it;
    list<string>::iterator it3 = ++(++(++(l.begin())));
    reverse(l.begin(), it3);
    cout << endl << "modify reverse first three: " << *this;

    rotate(l.begin(), it3, l.end());
    cout << endl << "modify rotate: " << *this;

    int d = l.size();
    remove(l.begin(), it3, "Franco");
    if(l.size() != d){
        s.erase("Franco");
    }
    /*
    d = l.size();
    remove(l.begin(), l.end(), "Franco");
    if(l.size() != d){
        s.erase("Franco");
    }
    */

    replace(l.begin(), l.end(), string("Franco"), string("Francesco"));
    cout << endl << "modify replace: " << *this;
}

ostream& operator << (ostream& os, const Ranking& _r){
    list<string>::const_iterator it;
    for(it = _r.l.begin(); it != _r.l.end(); it++){
        os << *it << " ";
    }
    return os;
}

void test_ranking(){
    // versione 2.0
    Ranking r2020;
    r2020.add_item_back("MIT");
    r2020.add_item_back("Stanford");
    r2020.add_item_back("Harvard");
    r2020.add_item_back("Oxford");
    r2020.add_item_back("Caltech");
    r2020.add_item_back("ETH");
    r2020.add_item_back("Cambridge");
    r2020.add_item_back("UCL");
    r2020.add_item_back("Imperial");
    r2020.add_item_back("Chicago");
    cout << "2020: " << r2020 << endl;
    Ranking r2018;
    r2018.add_item_back("MIT");
    r2018.add_item_back("Stanford");
    r2018.add_item_back("Harvard");
    r2018.add_item_back("Caltech");
    r2018.add_item_back("Cambridge");
    r2018.add_item_back("Oxford");
    r2018.add_item_back("UCL");
    r2018.add_item_back("Imperial");
    r2018.add_item_back("Chicago");
    r2018.add_item_back("ETH");
    cout << "2018: " << r2018 << endl;
    // r2020.compare(r2018);
    r2018.compare(r2020);
    r2020.properties();
    cout << endl << endl;
    // versione 3.0
    Ranking ordine;
    ordine.add_item_back("Giovanna");
    ordine.add_item_back("Franco");
    ordine.add_item_back("Carla");
    ordine.add_item_back("Martino");
    ordine.add_item_back("Silvia");
    cout << ordine << endl;
    ordine.modify();
}