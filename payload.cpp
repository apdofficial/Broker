//
// Created by Andrej Pistek on 18/10/2018.
//

#include "payload.h"
#include "iostream"

namespace saxion{
    /* ctors for individual types */
    payload::payload(const double &value): m_value{value} {}

    payload::payload(const bool &flag): m_value{flag} {}

    payload::payload(const std::string &description): m_value{description} {}

    payload::payload(std::string &&description) : m_value{std::move(description)}{}

    payload::payload(const char *data,int size): m_value{ blob(data, size) } {}

    /* getters */
    const std::string& payload::get_description() const {
        return std::get<std::string>(m_value);
    }

    bool payload::get_flag() const {
        if (std::holds_alternative<bool>(m_value)){
            auto& data = std::get<bool>(m_value);
            return data;
        }
        throw std::logic_error("Problem with getting type: bool");
    }

    double payload::get_value() const {
        if (auto* data = std::get_if<double>(&m_value); data){
            return *data;
        }
        throw std::logic_error("Problem with getting type: double");

    }

    const char* payload::get_data() const {

        if (std::holds_alternative<blob>(m_value)){
            auto& data = std::get<blob>(m_value);
            return data.arr.get();
        }
        throw std::logic_error("Problem with getting type: char[]");
    }

    int payload::get_size() const {
        if (auto* data = std::get_if<blob>(&m_value); data){
            return data->size;
        }
        throw std::logic_error("Problem with getting type: int");
    }


}


