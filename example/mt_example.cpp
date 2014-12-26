#include <cstdio>

#include "PokeRNG/MT.hpp"

int main() {
    // MTの初期シードを0に設定
    PokeRNG::MT mt(0);

    // MTを1つ進める
    PokeRNG::u32 r = mt();

    // MTを1つ進める
    r = mt();

    printf("%x\n", r);


    // MTの初期シードを100に設定
    mt.seed(100);

    // MTを1つ進める
    r = mt();
   
    printf("%x\n", r);

    return 0;
}
