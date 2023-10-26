#include<iostream>
#include<cassert>
#include<typeinfo>

class cpa_int{
    private :
       int N ;
    public:
       cpa_int(int _n = 0) : N(_n){}

       cpa_int operator+(const cpa_int &other) const {
        
        std :: cout << "In cpa_int :: operator+()" <<std::endl;
        int result  = this -> N + other.N ;
        cpa_int sum_obj(result);
        return sum_obj;
       
        }

        cpa_int operator-(const cpa_int &other) const{
            return cpa_int(this -> N - other.N);
        }  

        cpa_int operator *(const cpa_int &other) const {
            return cpa_int(this -> N * other.N);
        }

        cpa_int operator /(const cpa_int &other) const {
            assert(other.N!=0);
            return cpa_int(this->N / other.N);

        }

        cpa_int operator %(const cpa_int &other) const{
            assert(other.N !=0);
            return cpa_int(this->N % other.N);          
        }

        cpa_int operator <<(const cpa_int &other) const{
             return cpa_int(this -> N <<other.N);          
        }

        cpa_int operator>>(const cpa_int &other) const{
            return cpa_int(N >> other.N);
        }

        cpa_int operator &(const cpa_int &other) const {
            return cpa_int(N & other.N);
        }

        cpa_int operator |(const cpa_int &other )const {
            return cpa_int(N | other.N);
        }

        cpa_int operator ^(const cpa_int &other) const {
           return cpa_int(N ^ other.N);          
        }

        cpa_int operator ~() const{
             return cpa_int(~N) ;
        }

        bool operator>(const cpa_int &other) const{
                return(N > other.N);          
        }
        bool operator>=(const cpa_int &other) const{
            return (N >= other.N);
        }

        bool operator<(const cpa_int &other) const{
            return (N < other.N);
        }
        bool operator<=(const cpa_int &other )const{
            return (N <= other.N);
        }
        bool operator ==(const cpa_int &other) const {
            return(N == other.N);
        }
        bool operator !=(const cpa_int &other) const{
            return(N != other.N);
        }
        

        cpa_int operator++(){
            ++this->N;
            return *this;
        }

        cpa_int operator++(int){
            cpa_int tmp(this->N);
            this->N++;
            return tmp ;
        }

        cpa_int operator--(){
            --this->N;
            return *this;
        }
        cpa_int operator--(int){
            cpa_int temp(this ->N);
            this->N--;
            return temp;
        }
        void show(const char*msg) const{
            if(msg);
               std::cout << msg ;
               std::cout <<this -> N << std :: endl;
        }

};

int main(void){
    
    cpa_int n1(10),n2(20);
    cpa_int result;
    n1.show("N1:");
    n2.show("N2 :");
    result = n1 + n2 ;
    result.show("summation : ");

    std::cout <<"type(n1) : " << typeid(n1).name() << std::endl;
    std::cout << "type(n2) : " << typeid(n2).name() << std::endl;
    std::cout <<"type(result) : " << typeid(result).name()<<std::endl ;
    
    result = n1 - n2 ;

    result.show(" substraction : ");

    result  = n1 * n2 ;
    result .show(" multiplication : ");

    result = n1 / n2; 
    result.show("Quotient:"); 

    result = n1 % n2; 
    result.show("Remainder:"); 
    
    result = n1 << n2; 
    result.show("Shift Arithmetic Left:"); 

    result = n1 >> n2; 
    result.show("Shift Arithmetic Right:"); 

    result = n1 & n2; 
    result.show("Bitwise AND:"); 

    result = n1 | n2; 
    result.show("Bitwise OR:"); 

    result = n1 ^ n2; 
    result.show("Bitwise XOR:"); 

    result = ~n1; 
    result.show("Bitwise ~:"); 

    std::cout << "COMPARISON OPERATORS" << std::endl; 
    n1.show("n1:"); 
    n2.show("n2:"); 

    bool rs = (n1 > n2); 
    std::cout << "n1 > n2:" << rs << std::endl; 

    rs = (n1 >= n2); 
    std::cout << "n1 >= n2:" << rs << std::endl;

    rs = (n1 < n2); 
    std::cout << "n1 < n2:" << rs << std::endl;

    rs = (n1 <= n2); 
    std::cout << "n1 <= n2:" << rs << std::endl;

    rs = (n1 == n2); 
    std::cout << "n1 == n2:" << rs << std::endl;

    rs = (n1 != n2); 
    std::cout << "n1 != n2:" << rs << std::endl;

    cpa_int x = cpa_int(100);
    result  = ++x;
    result.show("pre incre");
    result  = x++;
    result.show("post increment");
    result = --x;
    result.show("pre decrement ") ;
    result = x-- ;
    result.show("post decrement ");
    return EXIT_SUCCESS;  
}
  