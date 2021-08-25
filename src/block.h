#include <string>
#include <sstream>
#include <ctime>

#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

class Block {
    private:
        const std::string block;
        std::string event_name, description, obj_name, sc_evt_time, doy, et_utc, orbit_num, plus_minus_periap, sun_earth_probe_angle, event_data {};

    public:
        explicit Block(std::string this_block);

        // setters
        void set_block(std::string block);
        void set_description(const std::string& desc);

        // getters
        std::string get_event_name();
        std::string get_description();
        std::string get_obj_name();
        std::string get_sc_evt_time();
        std::string get_doy();
        std::string get_et_utc();
        std::string get_orbit_num();
        std::string get_plus_minus_periap();
        std::string get_sun_earth_probe_angle();
        std::string get_event_data();
        std::string get_all_info();
        std::string build_output();
};

#endif

