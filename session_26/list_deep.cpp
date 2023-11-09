#include<iostream>
#include<cstdlib>

class node{
    friend class list;
    friend std::ostream& operator<<(std::ostream &os,const list &list_object);
    
    private:
         int data ;
         node *prev;
         node *next;
         node(int new_data = 0): data(new_data),next(0),prev(0)
         {}
         
};

class list
{
   
   private :
       node * head_node ;

       static void generic_insert(node * beg,node *mid,node*end){
              
              mid -> next = end;
              mid -> prev = beg ;
              beg -> next = mid;
              end -> prev = mid ;
       }
    
      static void generic_delete(node * n_del){
        n_del -> next -> prev = n_del -> prev ;
        n_del -> prev -> next = n_del -> next;
        delete n_del ;
      }

      static node*clone(node *other_head_node){
            node *new_head_node = new node(0);
            new_head_node -> prev = new_head_node;
            new_head_node -> next = new_head_node ;
        for(node *nd = other_head_node ->next;nd != other_head_node ;nd = nd -> next)
        generic_insert(new_head_node-> prev,new node(nd -> data),new_head_node );

        return new_head_node ;
      }

      public :
         list(){
            head_node = new node(0);
            head_node -> prev = head_node ;
            head_node -> next = head_node ;
         }

         list (const list &other){
            this -> head_node = clone(other.head_node);
         }

         list & operator=(const list &other){
        if(this-> head_node == other.head_node)
                return *this;
        this -> clear();
        delete this -> head_node;
        this -> head_node =clone(other.head_node);
        return *this ;
         }

         ~list(){
            this -> clear() ;
            delete head_node ;
            head_node = 0 ;
         }

        void insert_end(int new_data){
            generic_insert(head_node -> prev,new node(new_data),head_node);

        }

        void pop_start(int *p_data){
            if(head_node -> prev != head_node && head_node -> next !=head_node)
               {
                *p_data = head_node -> next -> data ;
                generic_delete(head_node -> next);
               }
        } 
        void clear()
        {

            node *nd_next = 0 ;
            for(node * nd = head_node -> next;nd != head_node ; nd  = nd -> next){
                nd_next = nd -> next ;
                delete nd ;
            }

            head_node -> next = head_node ;
            head_node -> prev = head_node ;
        }
    friend std :: ostream&operator <<(std::ostream &os,const list &list_obj);
};


std :: ostream &operator <<(std::ostream &os,const list &list_object){
    os << "[START] <->";
    for(node *nd = list_object.head_node -> next;
      nd != list_object.head_node;
      nd = nd -> next)
      os <<"["<<nd ->data << "] <->";
      os <<"[END]" <<std::endl;
      return os ;

}

int main(void){
    list L1 ; 
    int data ;
    
    for(data = 10 ;data < 101 ; data += 10)
        L1.insert_end(data);
    
    std :: cout << "L1 "<< L1<<std::endl ;

    list L2 ;
    for(data = 10;data < 101;data +=10)
       L2.insert_end(data * 100 );
    
    L2 = L1 ;

    std :: cout <<"L2 :" <<L2 << std::endl;
    L2.insert_end(500);

    std :: cout << "L2 : " <<L2 <<std::endl;
    std::cout <<"L1" << L1 <<std::endl;

    L1.pop_start(&data);
    std :: cout << "L2 : " <<L2 <<std::endl;
    std::cout <<"L1" << L1 <<std::endl;
    
    list L3(L2);

     std :: cout << "L2 : " <<L2 <<std::endl;
    std::cout <<"L3" << L3 <<std::endl;

    L3.insert_end(9999);
    std :: cout << "L2 : " <<L2 <<std::endl;
    std::cout <<"L3" << L3 <<std::endl;

    std :: cout << "end of app " <<std::endl ;

    return 0 ;

}
