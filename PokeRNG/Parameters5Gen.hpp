/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef POKERNG_PARAMETERS_5GEN_HPP
#define POKERNG_PARAMETERS_5GEN_HPP

#include "Config.hpp"
#include "DateTime.hpp"
#include "ROMType.hpp"

namespace PokeRNG {

template<typename Constant>
class Parameters5Gen {
private:
    u32 nazo1;
    u32 nazo2;
    u32 nazo3;
    u32 nazo4;
    u32 nazo5;

    u32 vcount;
    u32 gxstat;
    u32 frame;
    u32 timer0_min;
    u32 timer0_max;

    u32 timer0;
    u32 key;


    u32 mac_addr1;
    u32 mac_addr2;
    u32 mac_addr3;
    u32 mac_addr4;
    u32 mac_addr5;
    u32 mac_addr6;

    u32 year;
    u32 month;
    u32 day;
    u32 hour;
    u32 minute;
    u32 second;


public:
    Parameters5Gen();

    void set_mac_addr(u32, u32, u32, u32, u32, u32);
    void set_year(u32);
    void set_month(u32);
    void set_day(u32);
    void set_hour(u32);
    void set_minute(u32);
    void set_second(u32);

    void set_date_time(const DateTime&);

    void set_key(u32);
    void set_timer0(u32);

    void set_vcount(u32);
    void set_gxstat(u32);
    void set_frame(u32);

    void set_nazo1(u32);
    void set_nazo2(u32);
    void set_nazo3(u32);
    void set_nazo4(u32);
    void set_nazo5(u32);

    void set_timer0_min(u32);
    void set_timer0_max(u32);


    u32 get_mac_addr1() const;
    u32 get_mac_addr2() const;
    u32 get_mac_addr3() const;
    u32 get_mac_addr4() const;
    u32 get_mac_addr5() const;
    u32 get_mac_addr6() const;
    
    u32 get_year() const;
    u32 get_month() const;
    u32 get_day() const;
    u32 get_hour() const;
    u32 get_minute() const;
    u32 get_second() const;
    u32 get_week() const;

    u32 get_nazo1() const;
    u32 get_nazo2() const;
    u32 get_nazo3() const;
    u32 get_nazo4() const;
    u32 get_nazo5() const;

    u32 get_vcount() const;
    u32 get_timer0() const;
    u32 get_gxstat() const;
    u32 get_frame() const;
    u32 get_key() const;

    u32 get_timer0_min() const;
    u32 get_timer0_max() const;

};

} // end PokeRNG

#endif
