#include<iostream>
#include<cassert>
#include<ctime>
#include "array.hpp"

int main(void){
    array *pa = 0;
    array :: status_t status;
    ssize_t N;

    N = 8;
    pa = new array(8);

    for(ssize_t i  = 0;i<pa->size();i++)
    {
        status = pa -> set(i,(i+1)*10);
        assert(status == array :: status::SUCCESS);
    }

    pa -> show("after setting :");

    std::cout <<"client fetching and showing each elements :"<<std::endl;
    int element;
    for(ssize_t i = 0;i < pa -> size();i++)
    {
        status = pa->get(i,&element);
        std::cout <<"a["<<i<<"] : " << element << std:: endl;
    }

    std::cout <<"size of array" << pa->size() << std::endl;
    delete pa;
    pa = 0;
    pa = new array(100);
    srand(time(0));
    for(ssize_t i = 0;i < pa->size();++i)
    {
        pa -> set(i,rand());
    }
    pa->show("before sort");
    pa->sort();
    pa->show("after sort");

    delete pa;
    pa = 0;

    std :: cout <<"END"<<std::endl;

    return EXIT_SUCCESS;

}
