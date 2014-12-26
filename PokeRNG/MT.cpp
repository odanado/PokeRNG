/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#include "MT.hpp"

template class std::mersenne_twister_engine<uint_fast32_t, 32, 624, 397, 31,
                                            0x9908b0df, 11, 0xffffffff,
                                            7,  0x9d2c5680,
                                            15, 0xefc60000,
                                            18, 1812433253>;

