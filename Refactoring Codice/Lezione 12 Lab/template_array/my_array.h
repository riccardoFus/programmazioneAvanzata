// per la class template bisogna implementare tutto nel .h
#ifndef MY_ARRAY_H
#define MY_ARRAY_H
#include <iostream>
using namespace std;

// vanno dichiarati prima
template <class T> class My_array;

template <typename T>
ostream& operator << (ostream& os, const My_array<T>& a);

template <class T>
class My_array{
    private:
        int dim;
        T* array;
    public:
        My_array();
        My_array(int d);
        ~My_array();
        T& operator [] (int index) const;
        // va messo il <>
        friend ostream& operator << <>(ostream& os, const My_array<T>& a);
};

template <class T>
My_array<T>::My_array(){
    dim = 10;
    array = new T[dim];
    for(int i = 0; i < dim; i++){
        array[i] = 0;
    }
}

template <class T>
My_array<T>::My_array(int d){
    dim = d;
    array = new T[dim];
    for(int i = 0; i < dim; i++){
        array[i] = 0;
    }
}

template <class T>
My_array<T>::~My_array(){
    if(array != NULL){
        delete array;
    }
}

template <class T>
T& My_array<T>::operator[] (int index) const {
    if(index >= dim){
        return array[dim - 1];
    }
    if(index < 0){
        return array[0];
    }
    return array[index];
}

template <typename T>
ostream& operator << (ostream& os, const My_array<T>& a){
    for(int i = 0; i < a.dim; i++){
        os << a.array[i] << " ";
    }
    return os;
}


#endif
