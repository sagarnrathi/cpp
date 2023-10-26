#ifndef _VECTOR_H
#define _VECTOR_H

class vector{
    public :
        typedef long long int ssize_t ;
        typedef long long int index_t ;
        typedef enum status{
            SUCCESS = 1,
            INDEX_OUT_OF_RANGE,
            INVALID_SIZE,
            VECTOR_EMPTY
        } status_t;

      vector();
      vector(ssize_t N);
      vector(ssize_t N,int val);
      vector(const vector &other);

      ~vector();

      ssize_t size() const;
      ssize_t max_size()const;

      status_t push_back(int new_val);
      status_t pop_back(int *p_data);

      status_t get(index_t index,int *p_data);
      status_t set(index_t index,int new_val);
      void show(const char *msg)const;

      
      void sort(index_t start,index_t end);
    index_t search(int search_element) const;
    index_t search(int search_element,index_t start,index_t end) const;

    private :
       int *arr;
       ssize_t N;
};

#endif /*_VECTOR_H*/