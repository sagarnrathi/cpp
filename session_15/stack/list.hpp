#ifndef _LIST_H
#define _LIST_H

const int SUCCESS = 1;
const int TRUE = 1;
const int FALSE = 0 ;
const int LIST_DATA_NOT_FOUND = 2;
const int LIST_EMPTY  = 3;

typedef int data_t;

class node{
    friend class list;
    
    private :
        data_t data;
        node *prev;
        node* next;
        node (int new_data = 0);
};

class list{
    private:
    node* head_node;

    static void generic_insert(node *beg,node *mid,node* end);
    static void generic_delete(node *beg);

    node *search_node(data_t s_data);

    public :
    typedef enum status {
                FALSE = 0 ,
                SUCCESS = 1,
                LIST_DATA_NOT_FOUND ,
                LIST_EMPTY    
    } status_t;

    typedef int len_t;
    list();
    ~list();

    status_t insert_start(data_t new_data);
    status_t insert_end(data_t new_data);
    status_t insert_before(data_t e_data,data_t n_data);
    status_t insert_after(data_t e_data,data_t n_data);

    status_t get_start(data_t * p_start_data)const;
    status_t get_end(data_t * p_end_data) const;
    status_t pop_start(data_t * p_start_data);
    status_t pop_end(data_t * p_end_data);

    status_t remove_start();
    status_t remove_end();
    status_t remove_data(data_t r_data);

    bool find(data_t f_data);
    bool empty()const;
    void show(const char *msg) const;
    len_t size() const;
};
#endif /*_LIST_H */