/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#include "DateTimeRange.hpp"

namespace PokeRNG {

    void DateTimeRange::set_year(u32 begin, u32 end) {
        begin_date_time.year = begin;
        end_date_time.year = end;
    }
    void DateTimeRange::set_month(u32 begin, u32 end) {
        begin_date_time.month = begin;
        end_date_time.month = end;
    }
    void DateTimeRange::set_day(u32 begin, u32 end) {
        begin_date_time.day = begin;
        end_date_time.day = end;
    }
    void DateTimeRange::set_hour(u32 begin, u32 end) {
        begin_date_time.hour = begin;
        end_date_time.hour = end;
    }
    void DateTimeRange::set_minute(u32 begin, u32 end) {
        begin_date_time.minute = begin;
        end_date_time.minute = end;
    }
    void DateTimeRange::set_second(u32 begin, u32 end) {
        begin_date_time.second = begin;
        end_date_time.second = end;
    }

    DateTimeRange::iterator DateTimeRange::begin() const {
        return DateTimeIterator(begin_date_time, begin_date_time, end_date_time);
    }

    DateTimeRange::iterator DateTimeRange::end() const {
        return DateTimeIterator(end_date_time, begin_date_time, end_date_time);
    }


} // end PokeRNG
