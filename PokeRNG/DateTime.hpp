/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef POKERNG_DATE_TIME_HPP
#define POKERNG_DATE_TIME_HPP

#include "Config.hpp"

namespace PokeRNG {

class DateTimeIterator;

class DateTime {

friend DateTimeIterator;

private:
    u32 year;
    u32 month;
    u32 day;
    u32 hour;
    u32 minute;
    u32 second;

public:
    void set_year(u32);
    void set_month(u32);
    void set_day(u32);
    void set_hour(u32);
    void set_minute(u32);
    void set_second(u32);

    u32 get_year() const;
    u32 get_month() const;
    u32 get_day() const;
    u32 get_hour() const;
    u32 get_minute() const;
    u32 get_second() const;

};
} // end PokeRNG

#endif
