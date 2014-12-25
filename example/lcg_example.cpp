#include <cstdio>

#include "PokeRNG/LCG.hpp"

int main() {
    PokeRNG::LCG5Gen lcg;
    PokeRNG::u64 s = 0;

    // 1個LCGを進める
    s = lcg.next(s);

    // 1個LCGを戻す
    s = lcg.prev(s);

    // 100個LCGを進める
    s = lcg.next_n(s, 100);

    // 50個LCGを戻す
    s = lcg.prev_n(s, 50);

    // s = lcg.next_n(0, idx) となるidxを求める
    PokeRNG::u64 idx = lcg.index(s);

    return 0;
}
