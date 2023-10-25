#ifndef RANKING_H
#define RANKING_H

#include <iostream>
using namespace std;

#include <list>
#include <set>
// versione 2.0
#include <algorithm>

class Ranking{
    private:
        list<string> l;
        set<string> s;
    public:
        void add_item_back(string _s);
        // versione 2.0
        void compare(const Ranking& _r) const;
        void properties() const;
        // versione 3.0
        void modify();

    friend ostream& operator << (ostream& os, const Ranking& _r);
};

ostream& operator << (ostream& os, const Ranking& _r);

void test_ranking();

#endif