#include "fraction.h"

Fraction::Fraction(){
    zero = false;
}

Fraction Fraction::set_zero(){
    zero = true;
    num.clear();
    den.clear();
    return *this;
}

void Fraction::mul(unsigned int _i){
    multiset<unsigned int>::iterator it = den.find(_i);
    if(it != den.end()){
        den.erase(it);
    }else{
        num.insert(_i);
    }
}

void Fraction::div(unsigned int _i){
    multiset<unsigned int>::iterator it = num.find(_i);
    if(it != num.end()){
        num.erase(it);
    }else{
        den.insert(_i);
    }
}

Fraction& Fraction::operator*= (const Fraction& _f){
    if(_f.is_zero){
        set_zero();
        return *this;
    }
    multiset<unsigned int>::iterator it;
    for(it = _f.num.begin(); it != _f.num.end(); it++){
        mul(*it);
    }
    for(it = _f.den.begin(); it != _f.den.end(); it++){
        div(*it);
    }
    return *this;
}

bool Fraction::is_zero() const{
    return zero;
}