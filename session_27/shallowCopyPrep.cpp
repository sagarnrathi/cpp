class HasPtr
{
    private :
        int n ;
        int *ptr ;
        static int ref_count ;
    
    public  :
        HasPtr(int _n,int _val) : n(_n), ptr(new int(_val)){
              
        }

        HasPtr &operator=(const HasPtr &rhs_object){
            
        }


} ;