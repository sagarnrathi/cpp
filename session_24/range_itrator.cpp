#include<iostream>
#include<cstdlib>

class range{
    private :
         int  n_start;
         int n_end ;
    public :
        class iterator ;
    range(int end) : n_start(0),n_end(end){};
    range(int start,int end) : n_start(start),n_end(end){};

    iterator begin(){
        return iterator(n_start);
    }
    iterator end(){
        return iterator(n_end);
    }

    class iterator{
        private :
            int n;
        public :
           iterator(int _n = 0 ) : n(_n) {

           }
        iterator operator++(){
            ++n;
            return *this;
        }
        
        iterator operator++(int){
            iterator tmp(n);
            n++;
            return tmp;
        }
        
        iterator operator--(){
            --n;
            return *this ;
        }

        iterator operator--(int){
            iterator temp(n);
            --n ;
            return temp ;
        }

        int operator*(){
            return n;
        }

        bool operator== (const iterator &other){
            return(this -> n == other.n);
        }

        
        bool operator!= (const iterator &other){
            return(this -> n != other.n);
        }

    };
};


int  main(void){
    range r1(5);
    range r2(3,8);

    std::cout << "iterating over r1  " << std::endl ;
    for(range :: iterator iter = r1.begin();iter != r1.end();iter++)
        std::cout << "*iter = " << *iter <<std::endl; 
    std::cout <<"iterating over r2 " << std :: endl;
    for(range :: iterator iter = r2.begin();iter != r2.end();iter++)
       std::cout <<"*iter = " << *iter << std :: endl ;
    
    return EXIT_SUCCESS; 
}

