#include <iostream> 
#include "array.hpp"

array::array(ssize_t _N) : N(_N), a(new int[_N]){

}

array::status_t array::get(ssize_t index, int* element) const {
    if(index < 0 || index >= N)
        return (INDEX_OUT_OF_RANGE); 
    *element = a[index]; 
    return (SUCCESS); 
}

array::status_t array::set(ssize_t index, int new_val){
    if(index < 0 || index >= N)
        return (INDEX_OUT_OF_RANGE); 
    a[index] = new_val; 
    return (SUCCESS); 
}

void array::show(const char* msg) const{
    if(msg)
        std::cout << msg << std::endl; 
    for(ssize_t i = 0; i < N; ++i)
        std::cout << "a[" << i << "]:" << a[i] << std::endl; 
}

ssize_t array::partition(ssize_t p, ssize_t r){
    ssize_t i, j; 
    int pivot, tmp; 

    i = p - 1;
    pivot = a[r];  
    for(j = p; j < r; ++j){
        if(a[j] <= pivot){
            i = i + 1; 
            tmp = a[i]; 
            a[i] = a[j]; 
            a[j] = tmp; 
        }
    }

    tmp = a[r]; 
    a[r] = a[i+1]; 
    a[i+1] = tmp; 

    return i+1; 
}

void array::quick_sort(ssize_t p, ssize_t r){
    if(p < r){
        ssize_t q = this->partition(p, r); 
        this->quick_sort(p, q-1); 
        this->quick_sort(q+1, r); 
    }
}

void array::sort(){
    this->quick_sort(0, this->N-1); 
}

ssize_t array::size() const {
    return (N); 
}

array::~array(){
    delete[] a; 
}