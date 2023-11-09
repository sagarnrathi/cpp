#include<iostream>

class X {
    public : 
       X();
       X(int,int);
};

int main(void){
    X objx;
    X objx1(100,200);
    X objx2(objx1);

    X *px = new X(objx1);
    delete px ;
    px = 0 ;
    return 0;

}