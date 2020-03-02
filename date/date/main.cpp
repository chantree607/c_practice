//
//  main.cpp
//  date
//
//  Created by Chan Yong Lee on 28.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <iostream>
class Date{
    
private:
    int year_;
    int month_;
    int day_;
    
public:
    
    //default constructor
    Date(){
        year_ = 2020;
        month_ = 2;
        day_ = 28;
    }
    //constructor
    Date(int year, int month, int day){
        year_ = year;
        month_ = month;
        day_ = day;
    }
    void setDate(int year, int month, int day){
        year_ = year;
        month_ = month;
        day_ = day;
    }
    
    int getTotalDaysOfMonth(int year, int month)
    {
        static int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(month != 2){
            return month_days[month-1];
        }
        else if(year%100 != 0 && year%4 == 0 ){
            return 29;
        }
        else{
            return 28;
        }
    }
    
    void addDay(int inc){
        day_ += inc;
        
        while (true) {
            
            int days = getTotalDaysOfMonth(year_, month_);
            
            if(day_ <= days){
                break;
            }
            else{
                day_ -= days;
                addMonth(1);
            }
        }
    }
    
    void addMonth(int inc){
        addYear((month_ + inc - 1)/12);
        month_ = month_ + inc % 12;
        month_ = (month_ == 12 ? 12 : month_ % 12);
    }
    
    void addYear(int inc){
        year_ += inc;
    }
    
    void showDate(){
        std::cout << year_ <<"."<<month_<<"."<<day_<<std::endl;
    }
};

int main(int argc, const char * argv[]) {
    Date date(2011,3,1);
    date.showDate();
    
    date.addDay(30);
    date.showDate();
    
    date.addDay(2000);
    date.showDate();
    
    Date day2;
    day2.showDate();
    return 0;
}
