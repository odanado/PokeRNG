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
    typedef PokeRNG::ConstantParameters5Gen<0x2215f30, 0x221602c, 0x221602c, 0x2216078, 0x2216078, 0x5f, 0x6000000, 0x6, 0xc68, 0xc69> W1Ja;
    typedef PokeRNG::ConstantParameters5Gen<0x209a8dc, 0x2039ac9, 0x21ff9b0, 0x21ffa04, 0x21ffa04, 0x82, 0x6000000, 0x6, 0x1102, 0x1108> B2Ja;
    typedef PokeRNG::ConstantParameters5Gen<0x209a8fc, 0x2039af5, 0x21ff9d0, 0x21ffa24, 0x21ffa24, 0x82, 0x6000000, 0x6, 0x10f6, 0x10fb> W2Ja;
    typedef PokeRNG::ConstantParameters5Gen<0x2761150, 0x276124c, 0x276124c, 0x2761298, 0x2761298, 0x8c, 0x6000000, 0x9, 0x1237, 0x1238> B1JaDSi;
    typedef PokeRNG::ConstantParameters5Gen<0x2761150, 0x276124c, 0x276124c, 0x2761298, 0x2761298, 0x8c, 0x6000000, 0x9, 0x1232, 0x1234> W1JaDSi;
    typedef PokeRNG::ConstantParameters5Gen<0x209a8dc, 0x2039ac9, 0x27aa730, 0x27aa784, 0x27aa784, 0xa2, 0x6000000, 0x8, 0x150d, 0x1514> B2JaDSi;
    typedef PokeRNG::ConstantParameters5Gen<0x209a8fc, 0x2039af5, 0x27aa5f0, 0x27aa644, 0x27aa644, 0xbe, 0x6000000, 0x8, 0x18af, 0x18b3> W2JaDSi;


} // end ROMType
} // end PokeRNG

#endif

