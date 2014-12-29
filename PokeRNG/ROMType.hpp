/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef POKERNG_ROM_TYPE_HPP
#define POKERNG_ROM_TYPE_HPP

#include "ConstantParameters5Gen.hpp"

namespace PokeRNG {
namespace ROMType {
    typedef PokeRNG::ConstantParameters5Gen<0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0> None;
    typedef PokeRNG::ConstantParameters5Gen<0x2215f10, 0x221600c, 0x221600c, 0x2216058, 0x2216058, 0x60, 0x6000000, 0x6, 0xc79, 0xc7a> B1Ja;
    typedef PokeRNG::ConstantParameters5Gen<0x2215f30, 0x221602c, 0x221602c, 0x2216078, 0x2216078, 0x60, 0x6000000, 0x6, 0xc68, 0xc69> W1Ja;


} // end ROMType
} // end PokeRNG

#endif

