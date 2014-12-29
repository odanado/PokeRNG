/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef POKERNG_CALC_5GEN_SEED_HPP
#define POKERNG_CALC_5GEN_SEED_HPP

#include "Config.hpp"
#include "Parameters5Gen.hpp"

namespace PokeRNG {

class Calc5GenSeed {
private:
    static const u32 K0;
    static const u32 K1;
    static const u32 K2;
    static const u32 K3;

    static const u32 H0;
    static const u32 H1;
    static const u32 H2;
    static const u32 H3;
    static const u32 H4;

    u32 W[80];

    u32 to_u32_little_endian(u32) const;

    u32 to_bcd(u32) const;

    u32 sha1_circular_shift(u32, u32) const;

public:
    template<typename Constant>
    u64 operator() (const Parameters5Gen<Constant>& param);


};

} // end PokeRNG

#endif
