#include <iostream> 
#include <cassert>
#include <ctime> 
#include "array.hpp"

int main(void){
    array* pa = 0; 
    array::status_t status; 
    ssize_t N;

    N = 8;  
    pa = new array(8);

    for(ssize_t i = 0; i < pa->size(); ++i){
        status = pa->set(i, (i+1) * 10); 
        assert(status == array::status::SUCCESS);  
    } 

    pa->show("After Setting:");

    std::cout << "Client fetching and showing each element:" << std::endl; 
    int element; 
    for(ssize_t i = 0; i < pa->size(); ++i){
        status = pa->get(i, &element); 
        std::cout << "a[" << i << "]:" << element << std::endl; 
        assert(status == array::status::SUCCESS);
    } 

    std::cout << "Size of array:" << pa->size() << std::endl; 

    assert(pa->get(N, &element) == array::status::INDEX_OUT_OF_RANGE); 
    assert(pa->set(N+1, (N+1)*10) == array::status::INDEX_OUT_OF_RANGE); 

    delete pa; 
    pa = 0; 

    pa = new array(100); 
    srand(time(0)); 
    for(ssize_t i = 0; i < pa->size(); ++i)
        pa->set(i, rand()); 

    pa->show("Before sort:"); 
    pa->sort(); 
    pa->show("After sort:"); 
    
    delete pa; 
    pa = 0; 

    std::cout << "END" << std::endl; 

    return EXIT_SUCCESS; 
}