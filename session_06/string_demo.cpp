#include<iostream>
#include<string>
#include<cstdio>

int main(void)
{
    std :: string s1  ;
    std :: string s2("Hello");
    std :: string s3 = "world";
    std :: string s4(s3);

    std :: cout << "s1 : " <<s1  << std::endl 
                << "s2 : " << s2 << std :: endl 
                <<"s3 : "  << s3 << std :: endl
                <<"s4 : " << s4 << std::endl ;
    
    s1 = "new string s1 ";
    s2 = " new string s2 ";
    s3 = " new string s3 ";
    s4 = " new string s4 ";

    std :: cout << "s1 : " << s1 << std::endl
                << "s2 : " << s2 << std :: endl
                << "s3 : " << s3 << std:: endl
                << "s4 : " << s4 << std ::endl ;
    

    for(std :: string :: size_type i = 0; i< s4.size();i++)
         std::cout << "s4["<< i << "] : " <<s4[i] << std::endl;
    
    for(std :: string :: iterator itr = s4.begin();
        itr != s4.end();
        itr++)
        std :: cout << "*itr " << *itr << std::endl ;

    const char *str = s4.c_str();
    printf("str = %s \n",str);
    return 0;
}