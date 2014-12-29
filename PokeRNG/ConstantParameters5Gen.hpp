/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef POKERNG_CONSTANT_PARAMETERS_5GEN_HPP
#define POKERNG_CONSTANT_PARAMETERS_5GEN_HPP

#include "Config.hpp"

namespace PokeRNG {

template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
class ConstantParameters5Gen {
public:
    static const u32 nazo1 = nazo1_;
    static const u32 nazo2 = nazo2_;
    static const u32 nazo3 = nazo3_;
    static const u32 nazo4 = nazo4_;
    static const u32 nazo5 = nazo5_;

    static const u32 vcount = vcount_;
    static const u32 gxstat = gxstat_;
    static const u32 frame = frame_;
    static const u32 timer0_min = timer0_min_;
    static const u32 timer0_max = timer0_max_;
};

} // end PokeRNG

#endif
