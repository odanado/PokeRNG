
#include "LCG.hpp"

namespace PokeRNG {

template<typename UIntType, UIntType mul, UIntType add, UIntType mask>
LCG<UIntType, mul, add, mask>::LCG() : 
    div(calc_inverse_tmp<UIntType, mul, mask>::value), sub(~(div * add) + 1ULL) { }

template<typename UIntType, UIntType mul, UIntType add, UIntType mask>
UIntType LCG<UIntType, mul, add, mask>::next(UIntType s) const {
    return ((s * mul) + add);
}

template<typename UIntType, UIntType mul, UIntType add, UIntType mask>
UIntType LCG<UIntType, mul, add, mask>::prev(UIntType s) const {
    return ((s * div) + sub);
}

template<typename UIntType, UIntType mul, UIntType add, UIntType mask>
UIntType LCG<UIntType, mul, add, mask>::skip_lcg(UIntType s, UIntType n, UIntType a, UIntType b) const {
    while(n) {
        if(n & 1) s = ((s * a) + b);
        b = (a * b + b);
        a = (a * a);
        n >>= 1;
    }

    return s;
}

template<typename UIntType, UIntType mul, UIntType add, UIntType mask>
UIntType LCG<UIntType, mul, add, mask>::next_n(UIntType s, UIntType n) const {
    return skip_lcg(s, n, mul, add);
}

template<typename UIntType, UIntType mul, UIntType add, UIntType mask>
UIntType LCG<UIntType, mul, add, mask>::prev_n(UIntType s, UIntType n) const {
    return skip_lcg(s, n, div, sub);
}
/*
 * 参考
 * http://plusletool.hatenablog.jp/entry/2014/11/05/230000
 */
template<typename UIntType, UIntType mul, UIntType add, UIntType mask>
UIntType LCG<UIntType, mul, add, mask>::calc_index(UIntType s) const {
    u64 a = mul;
    u64 b = add;
    u64 n = 0;
    u64 x = 1;

    while(x) {
        if(s & x) {
            n |= x;
            s -= b;
            b *= a;
        }

        b *= a + 1;
        a *= a;
        x <<= 1;
    }

    return n;
}
template class LCG<u64, 0x5D588B656C078965, 0x269EC3, 0xFFFFFFFFFFFFFFFF>;
template class LCG<u32, 0x41C64E6D, 0x6073, 0xFFFFFFFF>;

template class LCG<u64, 0x5D583D6D6C078979, 0x26A693, 0xFFFFFFFFFFFFFFFF>;


} // end PokeRNG
