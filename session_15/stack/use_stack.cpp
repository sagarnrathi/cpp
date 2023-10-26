#include<iostream>
#include "stack.hpp"

int main(void){

    stack *pStack =  new stack;
    data_t data ;

    for(data = 0;data< 8;data++)
        pStack->push(data * 100);
    
    pStack->top(&data);
    std::cout << "top data " << data << std :: endl;

    pStack -> pop(&data);
    std::cout << "popped data " <<  data << std :: endl;

    while(!pStack->empty())
    {
        (pStack->pop(&data) == SUCCESS);
        std::cout << "POPED DATA:" << data << std::endl;  
    }
    delete pStack ;
    pStack = 0;
    return EXIT_SUCCESS;
}