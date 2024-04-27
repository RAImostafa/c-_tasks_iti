#include<iostream>
#include <string>


class Date 
{
  int day;
  int month;
  int year;
  public:
   Date() 
   {
     day = 5;
     month= 4;
     year=2024;
   }
  int Get_day (void){
    return this->day;
  }

  int Get_month (void){
    return this->month;
  }

  int Get_year (void){
    return this->year;
  }
  
  void set_day (int Day)
  { if(Day <= 31)
  {day= Day;}
        else {std::cout<<"incorrect data"<<"\n";
          return;
      }
  }

  void set_month (int Month) { 
      if(Month<= 12 ){month= Month; }
      else {std::cout<<"incorrect data"<<"\n";
          return;
      }
    
  }

  void set_year (int Year) { 
      if (Year <= 2024){year= Year; }
            else {std::cout<<"incorrect data"<<"\n";
          return;
      }
  }

  void display (void){
   std::cout<<day <<"/"<<month<<"/"<<year;
  }
};


int main(){

Date obj1;
obj1.set_day(45);
obj1.display();

  return 0;
}