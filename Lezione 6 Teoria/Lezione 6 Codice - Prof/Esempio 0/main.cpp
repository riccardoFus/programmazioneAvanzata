#include <cstdlib>
#include <iostream>

using namespace std;

#include<list>

int main(int argc, char *argv[])
{list<int> l;

l.push_back(2);
l.push_front(3);

list<int>::iterator it; //c++98
for(it=l.begin();it!=l.end();++it)
 cout<<*it;

for(auto a=l.begin();a!=l.end();++a) //c++11 e successivi
 cout<<*a;

for(auto v:l)
 cout<<v;

for(auto& e:l)
  e++;

for(auto v:l)
  cout<<v;

cout<<endl<<"______"<<endl; 

cout<<l.front();
cout<<l.back();

l.push_back(2);
l.push_front(5);
cout<<endl;for(auto v:l) cout<<v; 

l.pop_back();
l.pop_front();
cout<<endl;for(auto v:l) cout<<v;

l.insert(l.begin(),7);
cout<<endl;for(auto v:l) cout<<v;

l.insert(l.begin(),l.begin(),l.end());
cout<<endl;for(auto v:l) cout<<v;

cout<<endl<<"______"<<endl;

auto a=l.cbegin();//const_iterator
l.push_front(8);l.push_front(9);
cout<<endl<<"l:";for(auto v:l) cout<<v;
cout<<endl<<*a;

list<int> l2;
l2.splice(l2.cbegin(),l,a,l.cend());
cout<<endl<<"l:";for(auto v:l) cout<<v;
cout<<endl<<"l2:";for(auto v:l2) cout<<v;

l2.swap(l);
cout<<endl<<"l:";for(auto v:l) cout<<v;
cout<<endl<<"l2:";for(auto v:l2) cout<<v;

cout<<endl<<"______"<<endl;

cout<<l.size();
cout<<l.empty();

l.reverse();
cout<<endl<<"l:";for(auto v:l) cout<<v;

l.sort();
cout<<endl<<"l:";for(auto v:l) cout<<v;

l.unique();
cout<<endl<<"l:";for(auto v:l) cout<<v;

l2.sort();
l.merge(l2);
cout<<endl<<"l:";for(auto v:l) cout<<v;
cout<<endl<<"l2:";for(auto v:l2) cout<<v;

cout<<endl<<"______"<<endl;

list<int>::reverse_iterator rit;
for(rit=l.rbegin();rit!=l.rend();++rit)
cout<<*rit;

for(auto a=l.rbegin();a!=l.rend();++a)
 cout<<*a;

l.resize(4);
cout<<endl<<"l:";for(auto v:l) cout<<v;

l.remove(3);
cout<<endl<<"l:";for(auto v:l) cout<<v;


l.erase(l.begin());
cout<<endl<<"l:";for(auto v:l) cout<<v;

a=l.emplace(l.cbegin(),11);
cout<<endl<<"l:";for(auto v:l) cout<<v;
l.push_front(13);
cout<<endl<<"l:";for(auto v:l) cout<<v;

l2.assign(a,l.cend());
cout<<endl<<"l2:";for(auto v:l2) cout<<v;

cout<<endl<<"______"<<endl;

list<int> l3(l);
cout<<endl<<"l3:";for(auto v:l3) cout<<v;

 l=l2;
cout<<endl<<"l:";for(auto v:l) cout<<v;
cout<<endl<<"l2:";for(auto v:l2) cout<<v;

l.clear();
cout<<endl<<"l:";for(auto v:l) cout<<v;


cout<<endl<<l.max_size();

    return EXIT_SUCCESS;

}
