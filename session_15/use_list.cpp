#include<iostream>
#include "list.hpp"
#include<cassert>

int main(void){

list * p_list = 0 ;
data_t data = 0 ;

p_list = new list;
assert(p_list !=0);
assert(p_list ->empty()==TRUE);

std::cout << "p_list -> size() :" << p_list->size() << std ::endl;

for(data = 0; data < 5;data++)
        p_list-> insert_end((data + 1) * 100);

p_list->show("after insert in end ");

for(data = 0;data < 5;++data)
      p_list -> insert_start((data + 1) * 1000);

p_list -> show("before start insert");

p_list-> get_start(&data);

std :: cout <<"start data is " << data << std::endl;

p_list ->get_end(&data);
std::cout <<"end data is "<< data << std :: endl;

p_list -> pop_start(&data);
std :: cout << " start data is " << data << std::endl;
p_list -> pop_end(&data);
std::cout <<"end data is " << data << std :: endl;
p_list -> show("after popping start and end ");

p_list -> remove_end();
p_list -> remove_start();
p_list -> remove_data(0);

p_list -> show("after removing start end and 0");
 delete p_list;
 p_list = 0;
 std :: cout <<"destroyed successfuly"<< std::endl;
 return EXIT_SUCCESS;

}