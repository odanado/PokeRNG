/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef POKERNG_DATE_TIME_RANGE_HPP
#define POKERNG_DATE_TIME_RANGE_HPP

#include "DateTime.hpp"
#include "DateTimeIterator.hpp"

#include "Config.hpp"

namespace PokeRNG {

class DateTimeRange {
public:
    typedef DateTimeIterator iterator;
private:
    DateTime begin_date_time;
    DateTime end_date_time;

public:

    void set_year(u32, u32);
    void set_month(u32, u32);
    void set_day(u32, u32);
    void set_hour(u32, u32);
    void set_minute(u32, u32);
    void set_second(u32, u32);

    iterator begin() const;
    iterator end() const;


};

} // end PokeRNG

#endif
