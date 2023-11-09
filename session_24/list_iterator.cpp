#include <iostream> 

class node 
{
    friend class list; 
    private: 
        int data; 
        node* prev; 
        node* next; 
        node(int _data = 0) :   data(_data), 
                                prev(0), 
                                next(0)
        {
        }
}; 

class list 
{
    private: 
        node* head_node; 

        static void generic_insert(
            node* start, 
            node* mid, 
            node* end
        )
        {
            mid->next = end; 
            mid->prev = start; 
            start->next = mid; 
            end->prev = mid; 
        }

        static void generic_delete(node* delete_node)
        {
            delete_node->prev->next = delete_node->next; 
            delete_node->next->prev = delete_node->prev; 
            delete delete_node; 
        }

    public: 
        class iterator; 

        list() : head_node(new node) 
        {
            head_node->prev = head_node; 
            head_node->next = head_node; 
        }

        ~list()
        {
            node* run = 0; 
            node* run_next = 0; 

            for(
                run = head_node->next; 
                run != head_node; 
                run = run_next
            )
            {
                run_next = run->next; 
                delete run; 
            }
            delete head_node; 
            head_node = 0; 
        }

        void insert_start(int new_data)
        {
            generic_insert(
                head_node, 
                new node(new_data), 
                head_node->next
            ); 
        }

        void insert_end(int new_data)
        {
            generic_insert(
                head_node->prev, 
                new node(new_data), 
                head_node
            ); 
        }

        iterator begin() 
        {
            return iterator(head_node->next); 
        }

        iterator end() 
        {
            return iterator(head_node); 
        }

        class iterator 
        {
            private: 
                node* nd; 
            public: 
                iterator(node* _nd = 0) : nd(_nd)
                {

                }

                iterator operator++()
                {
                    nd = nd->next; 
                    return *this; 
                }

                iterator operator++(int)
                {
                    iterator tmp_iter(nd); 
                    nd = nd->next; 
                    return tmp_iter; 
                }

                iterator operator--()
                {
                    nd = nd->prev; 
                    return *this; 
                }

                iterator operator--(int)
                {
                    iterator tmp_iter(nd); 
                    nd = nd->prev; 
                    return tmp_iter; 
                }

                bool operator==(const iterator& other) const
                {
                    return nd == other.nd; 
                }

                bool operator!=(const iterator& other) const
                {
                    return nd != other.nd; 
                }

                int operator*() 
                {
                    return nd->data; 
                }
        }; 
}; 

int main(void)
{
    list L; 

    for(int data = 10; data <= 80; data += 10)
        L.insert_end(data); 

    for(
        list::iterator iter = L.begin(); 
        iter != L.end(); 
        --iter
    )
        std::cout << "*iter=" << *iter << std::endl; 

    return EXIT_SUCCESS; 
}

