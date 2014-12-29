#include <cstdio>

#include "PokeRNG/CalcOffset.hpp"

int main() {
    PokeRNG::u64 seed = 0;
    PokeRNG::CalcOffset calc_offset;

    // bw1のオフセット計算
    // 続きから始めた時
    printf("%lu\n", calc_offset.bw1(seed, true, true));
    // 最初から始めた時でセーブデータあり
    printf("%lu\n", calc_offset.bw1(seed, false, true));
    // 最初から始めた時でセーブデータなし
    printf("%lu\n", calc_offset.bw1(seed, false, false));

    // bw2のオフセット計算
    // 続きから始めた時でおもいでリンクあり
    printf("%lu\n", calc_offset.bw2(seed, true, true, true));
    // 続きから始めた時でおもいでリンクなし
    printf("%lu\n", calc_offset.bw2(seed, true, true, false));
    // 最初から始めた時でセーブデータありでおもいでリンクあり
    printf("%lu\n", calc_offset.bw2(seed, false, true, true));
    // 最初から始めた時でセーブデータありでおもいでリンクなし
    printf("%lu\n", calc_offset.bw2(seed, false, true, false));
    // 最初から始めた時でセーブデータなし
    printf("%lu\n", calc_offset.bw2(seed, false, false, true));

    return 0;
}
