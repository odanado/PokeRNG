/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef POKERNG_LCG_HPP
#define POKERNG_LCG_HPP

#include <type_traits>
#include "Config.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4307)
#endif

namespace PokeRNG {

template<typename UIntType, UIntType mul, UIntType add, UIntType mask>
class LCG {
private:
    template<class T, T A, T MASK, class U>
    struct calc_pow_tmp{
        static const T value = (U::value & 1 ? A : 1) *
            calc_pow_tmp<T, (A*A) & MASK, MASK, std::integral_constant<T, (U::value>>1)>>::value;
    };

    template<u64 A, u64 MASK>
    struct calc_pow_tmp<u64, A, MASK, std::integral_constant<u64,0>> {
        static const u64 value = 1;
    };
    template<u32 A, u32 MASK>
    struct calc_pow_tmp<u32, A, MASK, std::integral_constant<u32,0>> {
        static const u32 value = 1;
    };

    template<class T,T A, T MASK>
    struct calc_inverse_tmp {
        static const T value = calc_pow_tmp<T,A, MASK, std::integral_constant<T, (MASK >> 1)>>::value;
    };


    UIntType div;
    UIntType sub;

    UIntType skip_lcg(UIntType, UIntType, UIntType, UIntType) const;
public:
    LCG();
    UIntType next(UIntType) const;
    UIntType prev(UIntType) const;

    UIntType next_n(UIntType, UIntType) const;
    UIntType prev_n(UIntType, UIntType) const;

    UIntType index(UIntType) const;

};

typedef LCG<u64, 0x5D588B656C078965, 0x269EC3, 0xFFFFFFFFFFFFFFFF> LCG5Gen;
typedef LCG<u32, 0x41C64E6D, 0x6073, 0xFFFFFFFF> LCG4Gen;
typedef LCG<u32, 0x41C64E6D, 0x6073, 0xFFFFFFFF> LCG3Gen;

typedef LCG<u64, 0x5D583D6D6C078979, 0x26A693, 0xFFFFFFFFFFFFFFFF> LCG5GenDaily;


} // end PokeRNG
#endif
