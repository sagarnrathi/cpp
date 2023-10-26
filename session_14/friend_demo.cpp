#include <iostream>
#include <cstdlib>

void some_func(void);
void test_class_c1(void);
void test_class_c2(void);

class Test{
    private :
        int a;
        char b;
        float c;
    public :
        friend void some_func(void);
        friend class c2;
        Test():a(100),b('s'),c(3.12){

        }
};

class c1{
    public :
    void c1_func1(){
        Test t;
    }

    void c1_func2(){
        Test t;
    }

};

class c2{
    public :
    void c2_func1(){
        Test t;
        std::cout <<"this is class 2 method 1"<<std::endl;
        std::cout <<"t.a "<<t.a<<std::endl;
        std::cout<<"t.b "<<t.b<<std::endl;
        std::cout<<"t.c "<<t.c<<std::endl;
    }
    void c2_func2(){
        Test t;
        std::cout <<"this is class 2 method 2"<<std::endl;
        std::cout <<"t.a "<<t.a<<std::endl;
        std::cout<<"t.b "<<t.b<<std::endl;
        std::cout<<"t.c "<<t.c<<std::endl;
    }
};

int main(void){
Test t;
some_func();
test_class_c1();
test_class_c2();
return(0);
}

void some_func(void){
    Test *p_test = new Test;
    std::cout<<"inside some func():" << std::endl;
    std::cout << "some func a "<<p_test->a<<std::endl;
    std::cout << "some func b "<<p_test-> b<< std::endl;
    std::cout << "some func c "<< p_test->c << std::endl;
    delete p_test;
    p_test = 0;
    std::cout <<"----------------end some func------"<<std::endl;

}
void test_class_c1(void){
    std::cout <<"inside test class c1 " << std::endl;
    c1 obj1;

}

void test_class_c2(void){

     std ::cout <<"inside test class 2 "<<std::endl;
     c2 obj2;
     obj2.c2_func1();
     obj2.c2_func2();
     std::cout<<"-----------------end class 2 -----------"<< std::endl;
}