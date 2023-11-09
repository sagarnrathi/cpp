#include <iostream>

class IntPtr {
    
     friend  class Hasptr ;
     
     private : 
         int *p ;
         int ref_count ;
     
    public :

    IntPtr(int _val) : p(new int(_val)), ref_count(1){

    }
    
    ~IntPtr(){
        delete p ;
    }

} ;

class HasPtr
{
    private :
        int  n ;
        IntPtr *pIntPtr ;
    
    public :
        
        HasPtr(int _n,int _val) : n(_n),pIntPtr(new IntPtr(_val))
        {

        }

        HasPtr(const HasPtr &other) : n(other.n),pIntPtr(other.pIntPtr)
        {
             pIntPtr -> ref_count +=1 ;
        }
};