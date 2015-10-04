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
    static const u32 nazo1;
    static const u32 nazo2;
    static const u32 nazo3;
    static const u32 nazo4;
    static const u32 nazo5;

    static const u32 vcount;
    static const u32 gxstat;
    static const u32 frame;
    static const u32 timer0_min;
    static const u32 timer0_max;
};


template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
const u32 ConstantParameters5Gen<nazo1_, nazo2_, nazo3_, nazo4_, nazo5_, vcount_, gxstat_, frame_, timer0_min_, timer0_max_>::nazo1 = nazo1_;
template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
const u32 ConstantParameters5Gen<nazo1_, nazo2_, nazo3_, nazo4_, nazo5_, vcount_, gxstat_, frame_, timer0_min_, timer0_max_>::nazo2 = nazo2_;
template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
const u32 ConstantParameters5Gen<nazo1_, nazo2_, nazo3_, nazo4_, nazo5_, vcount_, gxstat_, frame_, timer0_min_, timer0_max_>::nazo3 = nazo3_;
template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
const u32 ConstantParameters5Gen<nazo1_, nazo2_, nazo3_, nazo4_, nazo5_, vcount_, gxstat_, frame_, timer0_min_, timer0_max_>::nazo4 = nazo4_;
template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
const u32 ConstantParameters5Gen<nazo1_, nazo2_, nazo3_, nazo4_, nazo5_, vcount_, gxstat_, frame_, timer0_min_, timer0_max_>::nazo5 = nazo5_;

template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
const u32 ConstantParameters5Gen<nazo1_, nazo2_, nazo3_, nazo4_, nazo5_, vcount_, gxstat_, frame_, timer0_min_, timer0_max_>::vcount = vcount_;
template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
const u32 ConstantParameters5Gen<nazo1_, nazo2_, nazo3_, nazo4_, nazo5_, vcount_, gxstat_, frame_, timer0_min_, timer0_max_>::gxstat = gxstat_;
template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
const u32 ConstantParameters5Gen<nazo1_, nazo2_, nazo3_, nazo4_, nazo5_, vcount_, gxstat_, frame_, timer0_min_, timer0_max_>::frame = frame_;
template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
const u32 ConstantParameters5Gen<nazo1_, nazo2_, nazo3_, nazo4_, nazo5_, vcount_, gxstat_, frame_, timer0_min_, timer0_max_>::timer0_min = timer0_min_;
template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
const u32 ConstantParameters5Gen<nazo1_, nazo2_, nazo3_, nazo4_, nazo5_, vcount_, gxstat_, frame_, timer0_min_, timer0_max_>::timer0_max = timer0_max_;


} // end PokeRNG

#endif
