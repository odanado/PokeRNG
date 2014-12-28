/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#include "DateTime.hpp"

namespace PokeRNG {
    void DateTime::set_year(u32 year_) { year = year_; }
    void DateTime::set_month(u32 month_) { month = month_; }
    void DateTime::set_day(u32 day_) { day = day_; }
    void DateTime::set_hour(u32 hour_) { hour = hour_; }
    void DateTime::set_minute(u32 minute_) { minute = minute_; }
    void DateTime::set_second(u32 second_) { second = second_; }


    u32 DateTime::get_year() const { return year; };
    u32 DateTime::get_month() const { return month; };
    u32 DateTime::get_day() const { return day; };
    u32 DateTime::get_hour() const { return hour; };
    u32 DateTime::get_minute() const { return minute; };
    u32 DateTime::get_second() const { return second; };

} // end PokeRNG
