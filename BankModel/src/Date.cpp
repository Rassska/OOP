#include <iostream>
#include "Date.h"


Date::Date() = default;
Date::Date(int mday, int mth){
    time.tm_mday = mday;
    time.tm_year = 120;
    time.tm_mon = mth;
    time.tm_sec = 0;
    time.tm_yday = 0;
    time.tm_hour = 0;
    time.tm_isdst = 0;
    time.tm_wday = 0;
    time.tm_min = 0;
}

Date::Date(tm time){
    this->time = time;
}

time_t Date::getTime(){
    return mktime(&time);
}

bool Date::operator<(Date &another){
    return getTime() < another.getTime();
}

bool Date::operator==(Date &another){
    return getTime() == another.getTime();
}

Date Date::getNow(){
    time_t now = std::time(nullptr);
    return Date(*gmtime(&now));
}

int Date::getDay(){
    return time.tm_mday;
}