#include<iostream>
#include<cstdlib>

struct IntPtr{
    int *p;
    int ref_count ;
} ;

class HasPtr{
    
    private : 
       int n ;
       struct IntPtr *p_int_ptr ;
    public :
        HasPtr(int _n,int _val){
            this -> n = _n ;
            this -> p_int_ptr  = new IntPtr ;
            this -> p_int_ptr -> p = new int(_val);
            this -> p_int_ptr -> ref_count = 1  ;
        }
    
        HasPtr(const HasPtr &other){
            this -> n = other.n ;
            this -> p_int_ptr = other.p_int_ptr ;
            this -> p_int_ptr ->ref_count +=1 ;
        }

        HasPtr& operator=(const HasPtr &rhs_object){
            
            if(this == &rhs_object)
                 return *this ;
            this -> n = rhs_object.n ;
            this -> p_int_ptr -> ref_count -= 1;
            if(this -> p_int_ptr -> ref_count == 0){
                delete this -> p_int_ptr -> p;
                delete this -> p_int_ptr ;
            }
            
            this -> p_int_ptr = rhs_object .p_int_ptr ;
            this -> p_int_ptr -> ref_count +=1 ;         
           return *this ;
        }

        ~HasPtr(){
            this -> p_int_ptr -> ref_count -= 1 ;
            if(this -> p_int_ptr -> ref_count == 0){
                delete this -> p_int_ptr -> p ;
                delete this -> p_int_ptr ;
            }
        
        }
} ;


