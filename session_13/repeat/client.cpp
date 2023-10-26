#include<iostream>
#include<cstdlib>
#include"vector.hpp"

int main(void){
    vector v1;
    vector v2(5);
    vector v3(10,48);
    vector v4(v3);

    v1.show("v1 :");
    v2.show("v2 : ");
    v3.show("v3 : ");
    v4.show("v4 : ");

    std::cout <<"v4.size() : " <<v4.size()<<std::endl;
    std::cout <<"v4.max_size() :" <<v4.max_size()<<std::endl;

    for(int i = 0;i< 100;i = i + 10)
        v1.push_back(i);
    
    while(true)
    {
        int data;
        vector ::status_t status;
        status  = v1.pop_back(&data);
        if(status ==  vector :: VECTOR_EMPTY)
           break;

        std :: cout <<"popped data : "<<data<<std::endl;
    }
    return EXIT_SUCCESS;
}