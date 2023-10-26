#include<cstdio>

class x
 {

 } ;
 
 
 class y{
    public :
   y()
   {
    puts("inside Y : Y()");
   }

 };


class z{
    
    public :

    z(int a)
    {
        printf("inside Z : Z() %d",a);

    }
};

int main()
{
    x objx;
    y objy;
    z objz(10);

    return 0;
}