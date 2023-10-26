#ifndef _STACK_H
#define _STACK_H

#include "list.hpp"
const int STACK_EMPTY = LIST_EMPTY;

class stack {
    
    private :
         list * p_list ;
    
    public :
      typedef list :: status_t status_t ;
      stack();
      ~stack();
      status_t push(data_t data);
      status_t pop(data_t * pop_data);
      status_t top(data_t * top_data);
      bool empty() const ;

};



#endif /* _STACK_H*/