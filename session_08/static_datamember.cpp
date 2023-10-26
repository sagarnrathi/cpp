
#include<iostream>

class Date{

   private :
         int day,month,year;
         static std :: size_t object_count ;
         static bool is_date_valid(int dd,int mm,int yy){

         }
   
   public :
       Date(){
         this ->object_count = this ->object_count + 1 ;
       }
      
       Date(int _day,int _month,int _year) : day(_day),month(_month),year(_year){
             Date :: object_count = Date :: object_count + 1 ;
       }

       int get_day()
       {
         return day;
       }

       int get_month()
       {
         return month ;
       }

       int get_year(){
         return year ;
       }

       void set_day(int new_day)
       {
         day = new_day ;
       }

       void set_month(int new_month)
       {
         month = new_month ;
       }

       void set_year(int new_year)
       {
         year = new_year ;
       }
      
      void show()
      {
         std :: cout << day << " - " << month << " - " << year <<std::endl;
      }

      static std :: size_t get_nr_object(void){
         return object_count ;
      }


};

std :: size_t Date :: object_count = 0 ;

int main(void)
{
   std :: cout << "total number of object created so far : "
               << Date :: get_nr_object()<<std::endl ;
   Date D1;
   std :: cout << "total number of object created so far : "
               << Date :: get_nr_object()<<std::endl ;
   Date D2, D3(1,2,1990),D4(1,2,2024);
   Date *pNewDate = new Date ;

   std :: cout << "total number of object created so far " << Date :: get_nr_object()<<std::endl;

   delete pNewDate ;
}