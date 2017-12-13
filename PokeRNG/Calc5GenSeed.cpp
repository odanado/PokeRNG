/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#include "Calc5GenSeed.hpp"

namespace PokeRNG {

const u32 Calc5GenSeed::K0 = 0x5a827999; 
const u32 Calc5GenSeed::K1 = 0x6ed9eba1;
const u32 Calc5GenSeed::K2 = 0x8f1bbcdc;
const u32 Calc5GenSeed::K3 = 0xca62c1d6;

const u32 Calc5GenSeed::H0 = 0x67452301;
const u32 Calc5GenSeed::H1 = 0xefcdab89;
const u32 Calc5GenSeed::H2 = 0x98badcfe;
const u32 Calc5GenSeed::H3 = 0x10325476;
const u32 Calc5GenSeed::H4 = 0xc3d2e1f0;

inline u32 Calc5GenSeed::to_u32_little_endian(u32 val) const {
    return ((val&0xff)<<24) | (((val>>8)&0xff)<<16) | (((val>>16)&0xff)<<8) | ((val>>24)&0xff);
}

inline u32 Calc5GenSeed::to_bcd(u32 val) const {
    return ((val/10)<<4) | (val%10);
}

inline u32 Calc5GenSeed::sha1_circular_shift(u32 bits, u32 word) const {
    return ((word << bits) | (word >> (32-bits)));
}

template<typename Constant>
u64 Calc5GenSeed::operator() (const Parameters5Gen<Constant>& param) {
        u32 A, B, C, D, E;
        u32 temp;
        u32 t;
        W[0] = to_u32_little_endian(param.get_nazo1());
        W[1] = to_u32_little_endian(param.get_nazo2());
        W[2] = to_u32_little_endian(param.get_nazo3());
        W[3] = to_u32_little_endian(param.get_nazo4());
        W[4] = to_u32_little_endian(param.get_nazo5());
        W[5] = to_u32_little_endian(
                    (param.get_vcount()<<16) | param.get_timer0()
                );
        W[6] = (param.get_mac_addr5() << 8) | param.get_mac_addr6();
        W[7] = to_u32_little_endian(
                    param.get_gxstat() ^ param.get_frame() ^
                    ((param.get_mac_addr4()<<24) | 
                    (param.get_mac_addr3()<<16) |
                    (param.get_mac_addr2()<<8 ) | 
                    (param.get_mac_addr1()))
                );
        W[8] = (to_bcd(param.get_year())  << 24) | 
               (to_bcd(param.get_month()) << 16) |
               (to_bcd(param.get_day()) << 8) |
                param.get_week();
        W[9] = ((to_bcd(param.get_hour()) |
               ((!param.get_is3ds()&&12<=param.get_hour())<<6)) << 24) |
               (to_bcd(param.get_minute()) << 16) |
               (to_bcd(param.get_second()) << 8);
        W[10] = 0x00000000;
        W[11] = 0x00000000;
        W[12] = to_u32_little_endian(param.get_key());
        W[13] = 0x80000000;
        W[14] = 0x00000000;
        W[15] = 0x000001A0;
        for (t = 16; t < 80; t++) {
            W[t] = sha1_circular_shift(1, W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16]);
        }

        A = H0;
        B = H1;
        C = H2;
        D = H3;
        E = H4;


        for (t = 0; t < 20; t++) {
            temp =  sha1_circular_shift(5, A) +((B & C) | ((~B) & D)) + E + W[t] + K0;
            E = D;
            D = C;
            C = sha1_circular_shift(30, B);
            B = A;
            A = temp;
        }

        for (t = 20; t < 40; t++) {
            temp = sha1_circular_shift(5, A) + (B ^ C ^ D) + E + W[t] + K1;
            E = D;
            D = C;
            C = sha1_circular_shift(30, B);
            B = A;
            A = temp;
        }

        for (t = 40; t < 60; t++) {
            temp = sha1_circular_shift(5, A) +
                ((B & C) | (B & D) | (C & D)) + E + W[t] + K2;
            E = D;
            D = C;
            C = sha1_circular_shift(30, B);
            B = A;
            A = temp;
        }

        for (t = 60; t < 80; t++) {
            temp = sha1_circular_shift(5, A) + (B ^ C ^ D) + E + W[t] + K3;
            E = D;
            D = C;
            C = sha1_circular_shift(30, B);
            B = A;
            A = temp;
        }

        u64 seed = to_u32_little_endian(H1+B);
        seed <<= 32;
        seed |= to_u32_little_endian(H0+A);

        return seed;

}

template u64 Calc5GenSeed::operator()<ROMType::None>(const Parameters5Gen<ROMType::None>&);
template u64 Calc5GenSeed::operator()<ROMType::B1Ja>(const Parameters5Gen<ROMType::B1Ja>&);
template u64 Calc5GenSeed::operator()<ROMType::W1Ja>(const Parameters5Gen<ROMType::W1Ja>&);
template u64 Calc5GenSeed::operator()<ROMType::B2Ja>(const Parameters5Gen<ROMType::B2Ja>&);
template u64 Calc5GenSeed::operator()<ROMType::W2Ja>(const Parameters5Gen<ROMType::W2Ja>&);
template u64 Calc5GenSeed::operator()<ROMType::B1JaDSi>(const Parameters5Gen<ROMType::B1JaDSi>&);
template u64 Calc5GenSeed::operator()<ROMType::W1JaDSi>(const Parameters5Gen<ROMType::W1JaDSi>&);
template u64 Calc5GenSeed::operator()<ROMType::B2JaDSi>(const Parameters5Gen<ROMType::B2JaDSi>&);
template u64 Calc5GenSeed::operator()<ROMType::W2JaDSi>(const Parameters5Gen<ROMType::W2JaDSi>&);

} // end PokeRNG
