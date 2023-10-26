#include <cstdio> 

class Test_1
{
    private: 
        int a; 
        char b; 
        float c; 

    public: 
        Test_1() 
        {
            printf("in constructr \n");
            printf("In Test_1():\n"); 
            printf("this:%p\n", this); 
        }
}; 

int main(void)
{
    Test_1 t1; 
    Test_1* p_t2 = new Test_1; 
    printf("in main");
    printf("main():&t1=%p\n", &t1); 
    printf("p_t2:%p\n", p_t2); 

    delete p_t2; 
    p_t2 = 0; 

    return 0; 
}