#include<cstdio>
#include<cstdlib>

namespace X
{
    int n;

    void sort(int *a,int n)
    {
        int i,j;
        int key;
        for(j = 1;j<n;j++)
        {
            key = a[j];
            i = a[j - 1];
            while(i>-1 && a[i] < a[j])
                {
                    a[i + 1 ] = a[i];
                    i = i - 1;
                }
            a[i + 1] = key;
        }
    }

    void show(int *a,int n,const char *msg)
    {
        if(msg){
            puts(msg);
        }
        int i;
        for(i = 0;i< n;i++)
        {
            printf("a[%d] : %d \n",i,a[i]);
        }
    }

    class Date{
        private :
            int day,month,year;
        public :
            Date(int _day,int _month,int _year): day(_day),
                                                 month(_month),
                                                 year(_year){

                                                 }
        void show()
        {
            printf("%d %d %d \n",day,month,year);
        }
    };

    namespace y{
        class Test{
            public :
                Test(){
                    puts("IN test");

                }
                void f()
                {
                    puts("in test f()");
                }
        };
    }
}

void test_namespace_1(void);

int main(void)
{
   test_namespace_1();
   return EXIT_SUCCESS ;
}

void test_namespace_1(void)
{
    X::n = 40;
    printf("X :: n =%d ",X::n);

    X:: Date independanceDay(15,8,1947);
    independanceDay.show();

    int a[] = {50,30,40,20,10};
    X::show(a,5,"before sort");
    X::sort(a,5);
    X::show(a,5,"after sort");

    X::y::Test t;
    t.f();
}