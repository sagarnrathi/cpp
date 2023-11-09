#include <iostream> 
#include <cstdlib> 
#include <cassert> 

class HasPtr 
{
    private: 
        int num; 
        int* p; 

    public: 
        // parameterized constructor 
        HasPtr(int _num, int _n) :  num(_num), 
                                    p(new int(_n))
        {
            std::cout << "In HasPtr::HasPtr(int, int): (Param CC):" << std::endl; 
        }

        // copy constructor 
        HasPtr(const HasPtr& other)
        {
            std::cout << "In HasPtr::HasPtr(const HasPtr&) (CC):" << std::endl; 
            this->num = other.num; 
            this->p = new int(*other.p); 
        }
        
        HasPtr& operator=(const HasPtr& other)
        {
            std::cout << "In HasPtr::operator=:" << std::endl; 
            this->num = other.num; 
            *this->p = *other.p; 
            return *this; 
        }

        ~HasPtr()
        {
            std::cout << "In HasPtr::~HasPtr(): dtor:" << std::endl; 
            delete p; 
            p = 0; 
        }

        int get_num() const 
        {
            return num; 
        }

        void set_num(int new_num)
        {
            num = new_num; 
        }

        int* get_ptr() const 
        {
            return (p); 
        }

        int get_ptr_val() const 
        {
            return (*p); 
        }

        void set_ptr_val(int new_val) 
        {
            *p = new_val; 
        }
}; 

int main(void)
{
    HasPtr* p_hp1 = new HasPtr(100, 200);   // param CC 
    HasPtr* p_hp2 = new HasPtr(*p_hp1);     // CC 
    HasPtr* p_hp3 = new HasPtr(1000, 2000); // param CC 
    std::cout   << "p_hp1->get_ptr():" << std::hex << p_hp1->get_ptr() << std::endl 
                << "p_hp2->get_ptr():" << std::hex << p_hp2->get_ptr() << std::endl ;

    std::cout << "BEFORE:p_hp2->get_ptr_val():" << p_hp2->get_ptr_val() << std::endl; 
    p_hp1->set_ptr_val(500); 
    std::cout << "AFTER:p_hp2->get_ptr_val():" << p_hp2->get_ptr_val() << std::endl; 
    
    *p_hp1 = *p_hp3;    // copy assignment operator 

    std::cout   << "p_hp1->get_ptr():" << std::hex << p_hp1->get_ptr() << std::endl 
                << "p_hp2->get_ptr():" << std::hex << p_hp2->get_ptr() << std::endl
                << "p_hp3->get_ptr():" << std::hex << p_hp3->get_ptr() << std::endl; 

    delete p_hp1;       // dtor 
    p_hp1 = 0; 
    
    delete p_hp2;       // dtor  
    p_hp2 = 0; 

    delete p_hp3;       // dtor  
    p_hp3 = 0; 

    return 0; 
}