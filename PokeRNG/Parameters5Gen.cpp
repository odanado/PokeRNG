/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#include "Parameters5Gen.hpp"

namespace PokeRNG {
template<typename Constant>
Parameters5Gen<Constant>::Parameters5Gen() : nazo1(Constant::nazo1), nazo2(Constant::nazo2), nazo3(Constant::nazo3), nazo4(Constant::nazo4), nazo5(Constant::nazo5), vcount(Constant::vcount), gxstat(Constant::gxstat), frame(Constant::frame), timer0_min(Constant::timer0_min), timer0_max(Constant::timer0_max), timer0(timer0_min), key(0x2fff), mac_addr1(0), mac_addr2(0), mac_addr3(0), mac_addr4(0), mac_addr5(0), mac_addr6(0), year(0), month(0), day(0), hour(0), minute(0), second(0) { }

template<typename Constant>
void Parameters5Gen<Constant>::set_mac_addr(u32 m1, u32 m2, u32 m3, u32 m4, u32 m5, u32 m6) {
        mac_addr1 = m1;
        mac_addr2 = m2;
        mac_addr3 = m3;
        mac_addr4 = m4;
        mac_addr5 = m5;
        mac_addr6 = m6;
}
template<typename Constant>
void Parameters5Gen<Constant>::set_year(u32 year_) {
    year = year_;
}
template<typename Constant>
void Parameters5Gen<Constant>::set_month(u32 month_) {
    month = month_;
}
template<typename Constant>
void Parameters5Gen<Constant>::set_day(u32 day_) {
    day = day_;
}
template<typename Constant>
void Parameters5Gen<Constant>::set_hour(u32 hour_) {
    hour = hour_;
}
template<typename Constant>
void Parameters5Gen<Constant>::set_minute(u32 minute_) {
    minute = minute_;
}
template<typename Constant>
void Parameters5Gen<Constant>::set_second(u32 second_) {
    second = second_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_date_time(const DateTime& date_time) {
    year   = date_time.get_year();
    month  = date_time.get_month();
    day    = date_time.get_day();
    hour   = date_time.get_hour();
    minute = date_time.get_minute();
    second = date_time.get_second();

}

template<typename Constant>
void Parameters5Gen<Constant>::set_key(u32 key_) {
    key = key_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_timer0(u32 timer0_) {
    timer0 = timer0_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_vcount(u32 vcount_) {
    vcount = vcount_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_gxstat(u32 gxstat_) {
    gxstat = gxstat_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_frame(u32 frame_) {
    frame = frame_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_nazo1(u32 nazo1_) {
    nazo1 = nazo1_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_nazo2(u32 nazo2_) {
    nazo2 = nazo2_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_nazo3(u32 nazo3_) {
    nazo3 = nazo3_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_nazo4(u32 nazo4_) {
    nazo4 = nazo4_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_nazo5(u32 nazo5_) {
    nazo5 = nazo5_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_timer0_min(u32 timer0_min_) {
    timer0_min = timer0_min_;
}

template<typename Constant>
void Parameters5Gen<Constant>::set_timer0_max(u32 timer0_max_) {
    timer0_max = timer0_max_;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_mac_addr1() const {
    return mac_addr1;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_mac_addr2() const {
    return mac_addr2;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_mac_addr3() const {
    return mac_addr3;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_mac_addr4() const {
    return mac_addr4;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_mac_addr5() const {
    return mac_addr5;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_mac_addr6() const {
    return mac_addr6;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_year() const {
    return year;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_month() const {
    return month;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_day() const {
    return day;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_hour() const {
    return hour;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_minute() const {
    return minute;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_second() const {
    return second;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_week() const {
    return  ((2000+year-(month<3)) + (2000+year-(month<3))/4 -
            (2000+year-(month<3))/100 + (2000+year-(month<3))/400 +
            (13*(month+(month<3)*12)+8)/5 + day) % 7;
}

template<typename Constant>
DateTime Parameters5Gen<Constant>::get_date_time() const {
    DateTime date_time;
    date_time.set_year(year);
    date_time.set_month(month);
    date_time.set_day(day);
    date_time.set_hour(hour);
    date_time.set_minute(minute);
    date_time.set_second(second);

    return date_time;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_nazo1() const {
    return nazo1;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_nazo2() const {
    return nazo2;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_nazo3() const {
    return nazo3;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_nazo4() const {
    return nazo4;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_nazo5() const {
    return nazo5;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_vcount() const {
    return vcount;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_timer0() const {
    return timer0;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_gxstat() const {
    return gxstat;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_frame() const {
    return frame;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_key() const {
    return key;
}

template<typename Constant>
u32 Parameters5Gen<Constant>::get_timer0_min() const {
    return timer0_min;
}
template<typename Constant>
u32 Parameters5Gen<Constant>::get_timer0_max() const {
    return timer0_max;
}

template class Parameters5Gen<ROMType::None>;
template class Parameters5Gen<ROMType::B1Ja>;
template class Parameters5Gen<ROMType::W1Ja>;
template class Parameters5Gen<ROMType::B2Ja>;
template class Parameters5Gen<ROMType::W2Ja>;

} // end PokeRNG
