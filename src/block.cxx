#include <algorithm>
#include <string>
#include <sstream>
#include <block.h>
#include <events.h>

Block::Block(std::string this_block): block(this_block) {
    Block::set_block(block);
}

void Block::set_block(std::string block) {
    std::replace(block.begin(), block.end(), ',', ' ');
    std::stringstream stream(std::stringstream::in | std::stringstream::out);
    stream << block;
    stream >> event_name >> obj_name >> sc_evt_time >> doy >> et_utc >> orbit_num >> plus_minus_periap >> sun_earth_probe_angle;
    getline(stream, event_data);
    Block::set_description(event_name);
}

void Block::set_event_name(std::string evt_name) {
    event_name = evt_name;
}

void Block::set_description(std::string desc) {
    auto it = events.find(desc);
    description = it->second;
}

std::string Block::get_event_name() {
    return event_name;
}

std::string Block::get_description() {
    return description;
}

std::string Block::get_obj_name() {
    return obj_name;
}

std::string Block::get_sc_evt_time() {
    return sc_evt_time;
}

std::string Block::get_doy() {
    return doy;
}

std::string Block::get_et_utc() {
    return et_utc;
}

std::string Block::get_orbit_num() {
    return orbit_num;
}

std::string Block::get_plus_minus_periap() {
    return plus_minus_periap;
}

std::string Block::get_sun_earth_probe_angle() {
    return sun_earth_probe_angle;
}

std::string Block::get_event_data() {
    return "{" + event_data + "}";
}

std::string Block::get_all_info() {
    return get_event_name() + " " + get_obj_name() + " " + get_sc_evt_time() + " " + get_doy() + " " + get_et_utc() 
    + " " + get_orbit_num() + " " + get_plus_minus_periap() + " " + get_sun_earth_probe_angle();
}