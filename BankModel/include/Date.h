#pragma once

#include <chrono>

class Date{
private:
    tm time;
public:
    Date(){}
    Date(int mday, int mon);
    Date(tm time);
    
    time_t getTime();
    bool operator<(Date& another);
    bool operator==(Date& another);
    static Date getNow();
    int getDay();
};