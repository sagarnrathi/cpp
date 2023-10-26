#include<iostream>

class Test
{
    public :
    Test operator+(const Test &second_object) const {
        std::cout << "------in test operator+() ---------"<<std::endl;
        std::cout << "this : "<<std::hex << this << std::endl;
        std::cout << " &second object : "<< std::hex << &second_object << std::endl;
        std::cout <<"returing from test operator +" << std::endl;
        Test t = Test();
        return t;
    }

    bool operator*()
    {
        std::cout << "------in test operator * -----------"<<std::endl;
        std::cout <<"this " <<std::hex<<this<<std::endl;
        std::cout <<"returning from test() * " <<
    }

}