
#include "CalcOffset.hpp"

namespace PokeRNG {

const u32 CalcOffset::PROBABILITY_TABLE[6][5] = {
        {  50,100,100,100,100 },
        {  50, 50,100,100,100 },
        {  30, 50,100,100,100 },
        {  25, 30, 50,100,100 },
        {  20, 25, 33, 50,100 },
        { 100,100,100,100,100 } } ;


CalcOffset::CalcOffset(bool is_bw1, bool has_continued, bool exist_data, bool exist_memory_link) : lcg(LCG5Gen()), offset(0), seed(0), is_bw1(is_bw1), has_continued(has_continued), exist_data(exist_data), exist_memory_link(exist_memory_link) { }



inline u64 CalcOffset::next(u64 s) {
    ++offset;
    return lcg.next(s);
}

u64 CalcOffset::exec_pt(u64 s) {
    u64 r;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if(PROBABILITY_TABLE[i][j] == 100) {
                break;
            }
            s = next(s);
            r = ((s >> 32) * 101) >> 32;

            if (r <= PROBABILITY_TABLE[i][j]) {
                break;
            }
        }
    }

    return s;
}

u64 CalcOffset::exec_extra(u64 s) {
    u64 r1,r2,r3;

    while(true) {
        s = next(s);
        r1 = ((s >> 32) * 15) >> 32;
        s = next(s);
        r2 = ((s >> 32) * 15) >> 32;
        s = next(s);
        r3 = ((s >> 32) * 15) >> 32;
        if(!(r1==r2 || r2==r3 || r3==r1)) {
            break;
        }
    }
    return s;
}

u64 CalcOffset::get_seed() const { 
    return seed; 
}
u64 CalcOffset::get_offset() const { 
    return offset;
}
u64 CalcOffset::bw1(u64 seed_, bool has_continued_, bool exist_data_) {
    seed = seed_;
    offset = 0;
    if(has_continued_) {
        seed = exec_pt(seed);
        seed = exec_pt(seed);
        seed = exec_pt(seed);
        seed = exec_pt(seed);
        seed = exec_pt(seed);
    }
    else {
        if(!exist_data_) {
            seed = exec_pt(seed);
        }
        seed = exec_pt(seed);
        seed = exec_pt(seed);

        seed = next(seed);
        seed = next(seed);
        seed = next(seed);
    }

    return offset;
}

u64 CalcOffset::bw2(u64 seed_, bool has_continued_, bool exist_data_, bool exist_memory_link_) {

    seed = seed_;
    offset = 0;
    if(has_continued_) {
        seed = exec_pt(seed);
        if(!exist_memory_link_) {
            seed = next(seed);
        }
        seed = next(seed);
        seed = next(seed);

        seed = exec_pt(seed);
        seed = exec_pt(seed);
        seed = exec_pt(seed);
        seed = exec_pt(seed);

        seed = exec_extra(seed);
    }
    else {
        seed = exec_pt(seed);

        seed = next(seed);
        seed = next(seed);
        if(exist_data_ && !exist_memory_link_) {
            seed = next(seed);
        }

        seed = exec_pt(seed);

        seed = next(seed);
        seed = next(seed);

        if(!exist_data_) {
            seed = next(seed);
            seed = next(seed);
            seed = exec_pt(seed);
            seed = next(seed);
            seed = next(seed);
        }

        seed = next(seed);
        seed = next(seed);
        seed = next(seed);
    }


    return offset;
}

u64 CalcOffset::operator() (u64 seed) {
    if(is_bw1) {
        offset = bw1(seed, has_continued, exist_data);
    }
    else {
        offset = bw2(seed, has_continued, exist_data, exist_memory_link);
    }

    return offset;
}

} // end PokeRNG

