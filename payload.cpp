//
// Created by Andrej Pistek on 18/10/2018.
//

#include "payload.h"
#include "iostream"

namespace DATA{
    /* ctors for individual types */
    payload::payload(const double &value): m_value{value} {}

    payload::payload(const bool &flag): m_flag{flag} {}

    payload::payload(const std::string &description): m_description{description} {}

    payload::payload(const char data[], const int& size):
    m_size{size}, m_data{std::unique_ptr<char[]>(new char[size])}
    {operator=(data);}

    /* copy ctors for all types */
    payload::payload(const DATA::payload &o, const std::string& type) {
        if (type == "string") {
            m_description = o.m_description;
        }
        else if (type == "bool") {
            m_flag = o.m_flag;
        }
        else if (type == "double") {
            m_value = o.m_value;
        }
        else if ("data") {
            m_size = o.m_size;
            m_data = std::unique_ptr<char[]>(new char[m_size]);
            operator=(o);
        }
    }

    /* copy  assignment operators */
    payload& payload::operator=(const  DATA::payload &o) {
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = o.m_data[i];
        };
        return *this;
    }

    payload& payload::operator=(const char data[]) {
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = data[i];
        };
        return *this;
    }

    /* destructor */
    payload::~payload(void) = default;

    /* getters */
    const std::string& payload::get_description() const {
        return std::get<std::string>(m_description);
    }
    const bool& payload::get_flag() const {
        return std::get<bool>(m_flag);
    }
    const double& payload::get_value() const {
        return std::get<double>(m_value);
    }
    const std::unique_ptr<char[]>& payload::get_data() const {
        return m_data;
    }
    const int& payload::get_size() const {
        return m_size;
    }
}


