#include<iostream>

class Date{
    
    private :
       int day;
       int month;
       int year;
    
    public :
        Date(int _day,int _month,int _year) :day(_day),month(_month),year(_year){}
        Date() : day(1),month(1),year(1970){}

        void show(const char *msg) const {
            if(msg) 
                std::cout <<msg;
            std::cout <<day <<"-" <<month << "-"<< year<<std::endl;
        }

        friend std::ostream& operator<<(std ::ostream& op_stream,const Date &date_obj);
        friend std ::istream& operator>>(std :: istream& ip_stream, Date &date_obj);

} ;

std::ostream &operator<<(std:: ostream &op_stream,const Date& date_obj){
    op_stream <<date_obj.day<<"-" << date_obj.month<<"-" <<date_obj.year <<std::endl ;
    return op_stream;
}
std::istream &operator >>(std::istream &ip_stream, Date& date_obj){
    
    std::cout << "enter a day :";
    ip_stream >> date_obj.day ;

    std::cout << "enter a month : ";
    ip_stream >> date_obj.month ;

    std:: cout << "enter a year ";
    ip_stream >> date_obj.year ;

    return ip_stream ;
}

int main (void){
    Date user_date ;
    std:: cin >> user_date ;
    std::cout << "user_date : " << user_date <<std::endl;
    return 0;
}