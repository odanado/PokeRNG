/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#include "DateTimeIterator.hpp"

namespace PokeRNG {

const u32 DateTimeIterator::month_ends[13] = 
                { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

DateTimeIterator::DateTimeIterator(const DateTime& date_time_, const DateTime& begin, const DateTime& end) : date_time(date_time_), begin_date_time(begin), end_date_time(end) {
    if(month_ends[begin_date_time.month] < begin_date_time.day) {
        begin_date_time.day = month_ends[begin_date_time.month];
    }

    if(month_ends[end_date_time.month] < end_date_time.day) {
        end_date_time.day = month_ends[end_date_time.month];
    }

    if(month_ends[date_time.month] < date_time.day) {
        date_time.day = month_ends[date_time.month];
    }
}

bool DateTimeIterator::operator!=(const DateTimeIterator& it) const {
    if(date_time.year != it.date_time.year) return true;
    if(date_time.month != it.date_time.month) return true;
    if(date_time.day != it.date_time.day) return true;
    if(date_time.hour != it.date_time.hour) return true;
    if(date_time.minute != it.date_time.minute) return true;
    if(date_time.second != it.date_time.second) return true;

    return false;

}

const DateTime& DateTimeIterator::operator*() const {
    return date_time;
}

const DateTimeIterator& DateTimeIterator::operator++() {
    if(date_time.second < end_date_time.second) {
        ++date_time.second;
        return *this;
    }
    date_time.second = begin_date_time.second;

    if(date_time.minute < end_date_time.minute) {
        ++date_time.minute;
        return *this;
    }
    date_time.minute = begin_date_time.minute;

    if(date_time.hour < end_date_time.hour) {
        ++date_time.hour;
        return *this;
    }
    date_time.hour = begin_date_time.hour;

    if(date_time.day < end_date_time.day) {
        ++date_time.day;
        return *this;
    }
    date_time.day = begin_date_time.day;

    if(date_time.month < end_date_time.month) {
        ++date_time.month;
        return *this;
    }
    date_time.month = begin_date_time.month;

    if(date_time.year < end_date_time.year) {
        ++date_time.year;
        return *this;
    }

    return *this;
}

} // end PokeRNG
