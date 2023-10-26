#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include "vector.hpp"

vector :: vector() : arr(0),N(0){}

vector :: vector(ssize_t _N){
    if(_N == 0)
    {
        arr = 0;
        N  = 0;
    }
    else{
        N = _N ;
        arr = (int * ) calloc(N ,sizeof(int));
        if(arr == 0)
        {
            puts("failed to allocate the memory ");
            exit(EXIT_FAILURE);
        }
    }
}

vector :: vector(ssize_t _N,int val){
        if(_N == 0)
        {
            arr = 0;
            N = 0 ;
        }
        else{
            N = _N;
            arr = (int *) malloc(N * sizeof(int));

            if(arr == 0)
            {
                std::cout<<"fatal : out of memory "<< std::endl;
                exit(EXIT_FAILURE);
            }
            for(index_t i = 0;i < N;++i)
               arr[i] = val;
        }
}

vector :: vector(const vector& other){
    this-> N = other.N;
    if(this ->N > 0 ){
        arr = (int *)malloc(N * sizeof(int));
        if(arr == 0){
            std::cout <<"fatal out of memory "<< std::endl;
            exit(EXIT_FAILURE);
        }
    memcpy(arr,other.arr,N * sizeof(int));
    }
    else {
        arr = 0;
    }
}

vector :: ~vector(){
    if(arr){
        free(arr);
        arr = 0 ;
    }
}

vector :: ssize_t vector::size() const {
return N;
}

vector :: ssize_t vector :: max_size()const{
    vector :: ssize_t m_size = 0;
    
    #ifdef BUILD_32
    m_size = (vector ::ssize_t)pow(2,31);
    #elif BUILD_64
    m_size = (vector :: ssize_t)pow(2,63);
    #endif;

    return (m_size - 1);
}

vector ::status_t vector::push_back(int val){
    arr = (int *)realloc(arr,(N + 1)*sizeof(int));
    if(arr == 0){
            std::cout << "fatal : error in growing array" <<std::endl;
            exit(EXIT_FAILURE);
    }

    N = N +1 ;
    arr[N - 1] = val;
    return(SUCCESS);
}

vector :: status_t vector ::pop_back(int *p_data){
    if(N == 0)
         return VECTOR_EMPTY;
    *p_data  = arr[N - 1];
    if(N == 1){
        free(arr);
        arr = 0 ;
        N = 0;
    }
    else{
        arr = (int *) realloc(arr,(N -1)*sizeof(int));
        if(arr == 0)
        {
            std::cout << " error in shring " << std::endl;
            exit(EXIT_FAILURE);
        }
        N = N - 1;
    }
    return SUCCESS;
}

void vector:: show(const char *msg) const {
    if(msg)
       std::cout <<msg<<std::endl;
    for(index_t index = 0;index < N;++index)
       std::cout <<"a [" <<index <<"]:"<<arr[index]<<std::endl;
}