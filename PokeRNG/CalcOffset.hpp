/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef POKERNG_CALC_OFFSET_HPP
#define POKERNG_CALC_OFFSET_HPP

#include "Config.hpp"
#include "LCG.hpp"

namespace PokeRNG {

class CalcOffset {
private:
    LCG5Gen lcg;
    u64 offset;
    u64 seed;
    static const u32 PROBABILITY_TABLE[6][5];

    bool is_bw1;
    bool has_continued;
    bool exist_data;
    bool exist_memory_link;

    u64 next(u64);
    u64 exec_pt(u64);
    u64 exec_extra(u64);

public:

    CalcOffset(bool is_bw1 = true, bool has_continued = true, bool exist_data = true, bool exist_memory_link = true);

    u64 get_seed() const;
    u64 get_offset() const;

    u64 bw1(u64, bool, bool);
    u64 bw2(u64, bool, bool, bool);
    u64 operator() (u64);

};

} // end PokeRNG

#endif

