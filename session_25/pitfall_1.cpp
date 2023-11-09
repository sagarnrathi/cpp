#include<iostream>

class HasPtr
{
    private :
        int num;
        int *pn; 
    
    public :
        HasPtr(
            int _num ,
            int _n
        ) : num(_num),pn(new  int(_n)){

        }

        int get_num() const {
            return num ; 
        }

        int *get_ptr() const {
            return (pn);
        }

        int get_ptr_val() const {
                  return *pn ;
        }

        void set_ptr_val(int new_val){
            *pn = new_val;
        }
        ~HasPtr(){
            delete pn ;
            pn = 0 ;
        }
} ;

int main(void){

HasPtr * p_hp1 = new HasPtr(100,200);
HasPtr *p_hp2 = new HasPtr(*p_hp1);

if(p_hp1-> get_num() == p_hp2 -> get_num())
   std::cout <<"value in num of ph1 and ph2 are same "<< std:: endl;

if(p_hp2 -> get_ptr() == p_hp2 -> get_ptr())
    std:: cout <<" addres of both is same " << std:: endl ;
    std::cout   << "BEFORE:p_hp2->get_ptr_val():" 
                << p_hp2->get_ptr_val() 
                << std::endl; 
    p_hp1->set_ptr_val(500); 
    std::cout   << "AFETR:p_hp2->get_ptr_val():" 
                << p_hp2->get_ptr_val() 
                << std::endl; 

}