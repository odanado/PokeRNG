/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef POKERNG_DATE_TIME_ITERATOR_HPP
#define POKERNG_DATE_TIME_ITERATOR_HPP

#include "DateTime.hpp"
#include "Config.hpp"

#include <algorithm>

namespace PokeRNG {

class DateTimeIterator {
private:
    DateTime date_time;
    DateTime begin_date_time;
    DateTime end_date_time;

    static const u32 month_ends[13];

public:
    DateTimeIterator(const DateTime&, const DateTime&, const DateTime&);

    bool operator!=(const DateTimeIterator&) const;

    const DateTime& operator*() const;

    const DateTimeIterator& operator++();

    const DateTimeIterator& operator--();

};

} // end PokeRNG

#endif
