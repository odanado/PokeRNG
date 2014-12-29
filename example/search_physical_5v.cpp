#include <iostream>
#include <cstdio>

#include "PokeRNG/Calc5GenSeed.hpp"
#include "PokeRNG/MT.hpp"
#include "PokeRNG/LCG.hpp"
#include "PokeRNG/DateTimeRange.hpp"

std::ostream& operator<<(std::ostream& os, const PokeRNG::DateTime date_time) {

    os << date_time.get_year() << " / " << date_time.get_month() << " / " <<
        date_time.get_day() << " : " << date_time.get_hour() << " / " <<
        date_time.get_minute() << " / " << date_time.get_second();

    return os;
}

int main() {
    PokeRNG::Parameters5Gen<PokeRNG::ROMType::B1Ja> b1;
    PokeRNG::DateTimeRange range;
    PokeRNG::LCG5Gen lcg;
    PokeRNG::Calc5GenSeed calc_seed;

    b1.set_mac_addr(0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0);
    b1.set_timer0(0xc7a);

    range.set_year(0, 99);
    range.set_month(1, 12);
    range.set_day(1, 31);
    range.set_hour(0, 23);
    range.set_minute(0, 59);
    range.set_second(0, 59);

    for(const auto &it : range) {
        b1.set_date_time(it);
        PokeRNG::u64 seed1 = lcg.next(calc_seed(b1));
        PokeRNG::MT mt(seed1 >> 32);

        PokeRNG::u32 H = mt() >> 27;
        PokeRNG::u32 A = mt() >> 27;
        PokeRNG::u32 B = mt() >> 27;
        mt();
        PokeRNG::u32 D = mt() >> 27;
        PokeRNG::u32 S = mt() >> 27;

        if(H == 31 && A == 31 && B == 31 && D == 31 && S == 31) {
            std::cout<<it<<std::endl;
            printf("found! %lx\n", seed1);
        }
    }

    return 0;
}
