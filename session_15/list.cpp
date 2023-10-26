#include<iostream>
#include"list.hpp"

node::node(int new_data) :  data(new_data), 
                            prev(0), 
                            next(0)
{

}

list :: list() : head_node(new node){
    head_node -> next = head_node;
    head_node ->prev  = head_node ;
}

list :: ~list(){
    node *run = 0 ;
    node *run_next = 0;

    for(run = head_node ->next ; run !=head_node;run = run_next)
    {
        run_next = run -> next;
        delete run;
    }
    delete head_node;
    head_node = 0;
}

list :: status_t list :: insert_start(data_t new_data){
    generic_insert(this -> head_node,new node(new_data),this->head_node->next);
    return SUCCESS;
}

list :: status_t list :: insert_end(data_t new_data){
    generic_insert(this->head_node->prev,new node(new_data),this->head_node);
    return SUCCESS;
}

list :: status_t list :: insert_after(data_t e_data,data_t new_data){
    node * e_node = 0 ;
    e_node = this->search_node(e_data);
    if(e_node == 0)
        return LIST_DATA_NOT_FOUND;
    generic_insert(e_node,new node(new_data),e_node-> next);
    return SUCCESS;
}

list :: status_t list :: insert_before(data_t e_data,data_t new_data){
    node *e_node=0;
    e_node = this -> search_node(e_data);
    if(e_node == 0)
        return LIST_DATA_NOT_FOUND ;
    generic_insert(e_node->prev,new node(new_data),e_node->next);
    return SUCCESS;
}

list :: status_t list :: get_start(data_t *p_data) const{
    if(this->empty())
          return LIST_EMPTY;
    *p_data = this-> head_node->next-> data;
    return SUCCESS;
}

list :: status_t list :: get_end(data_t * p_data) const {
    if(this -> empty())
        return LIST_EMPTY;
    *p_data = this -> head_node->prev->data;
    return SUCCESS;
}

list :: status_t list :: pop_start(data_t *p_data){
    if(this -> empty())
         return LIST_EMPTY;
    *p_data = this -> head_node -> next -> data;
    generic_delete(this->head_node -> next);
    return SUCCESS;
}

list :: status_t list :: pop_end(data_t *p_data)
{
    if(this -> empty())
       return LIST_EMPTY;
    *p_data = this -> head_node -> prev -> data;
    generic_delete(this ->head_node -> prev);
    return SUCCESS;
}

list :: status_t list :: remove_start(){
    if(this -> empty())
       return LIST_EMPTY;
    generic_delete(this->head_node -> next);
    return SUCCESS;
}

list :: status_t list :: remove_end(){
    if(this ->empty())
       return LIST_EMPTY;
    generic_delete(this -> head_node->prev);
    return SUCCESS;
}

list :: status_t list :: remove_data(data_t data)
{
    node * r_node = 0 ;
    r_node = this->search_node(data);
    if(r_node == 0)
        return LIST_DATA_NOT_FOUND ;
    generic_delete(r_node);
    return SUCCESS;
}
bool list::empty() const{
   
   return( this -> head_node -> next == this -> head_node &&
           this -> head_node -> prev == this -> head_node
           );
}

bool list :: find(data_t f_data){
    node * f_node = 0;
    f_node = this->search_node(f_data);
      return(f_node != 0);
}

void list ::show(const char *msg) const{
    if(msg)
        std::cout <<msg<<std::endl;
    std::cout <<"[START] <->";
    for(
        node *run = this-> head_node->next;
        run != head_node ;run = run->next
    )
    std :: cout <<"[" << run -> data << "] <->";

   std::cout <<"[END]" << std::endl;
    
}

list :: len_t  list ::size() const {
    list :: len_t len = 0;
    for(node *run = this ->head_node ->next;
        run != head_node;
        run = run ->next )
        len +=1;
    return len;
}

void list:: generic_insert(node *beg,node *mid,node *end){
    mid->next = end;
    mid -> prev = beg ;
    beg->next =  mid;
    end->prev = mid;
}

void list :: generic_delete(node *beg ){
    beg -> prev -> next = beg -> next;
    beg -> next -> prev = beg -> prev;
    delete beg;
    beg = 0;
}

 node * list :: search_node(data_t data){

     
    for(node * run  = this->head_node->next;run !=this->head_node;run = run ->next)
        if(run -> data == data)
            return run;
    return 0;
 }