#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

class Date{
    private :
         int day,month,year;
    
    public :
        Date() : day(1),month(1),year(1970){

        }
        Date(int _day,int _month,int _year) : 
                   day(_day),month(_month),year(_year)
        {

        }
        Date(const char * date_str)
        {
            size_t l = strlen(date_str);
            assert(l > 0);
            char * clone_date_str = (char *) malloc(l +1);

            *(clone_date_str + l) = '\0';
            strncpy(clone_date_str,date_str,l);

            day = atoi(strtok(clone_date_str,"/"));
            month = atoi(strtok(NULL,"/"));
            year = atoi(strtok(NULL,"/"));

            free(clone_date_str);
            clone_date_str = NULL ;

        }

        void show()
        {
            printf(" %d %d %d \n",day,month,year);
        }
};

int main(void)
{
    Date myDate ;
    Date cpa(28,2,2025);
    Date yearend("31/12/2023");
    
    myDate.show();
    cpa.show();
    yearend.show();

    return(EXIT_SUCCESS);

}