//
// Created by Andrej Pistek on 18/10/2018.
//

#include "payload.h"
#include "iostream"
#include <cstddef>
#include <memory>
#include <algorithm>

namespace DATA{
    payload::payload(const double &value): m_value{value} {}

    payload::payload(const bool &flag): m_flag{flag} {}

    payload::payload(const std::string &description): m_description{description} {}

    payload::payload(const char data[], const int& size):
    m_size{size},
    m_data{std::unique_ptr<char[]>(new char[size])}
    {
        operator=(data);
    }

    payload::payload(const DATA::payload &o, const std::string& type) {
        if (type == "string") {
            m_description = o.m_description;
        } else if (type == "bool") {
            m_flag = o.m_flag;
        } else if (type == "double") {
            m_value = o.m_value;
        } else if ("data") {
            m_size = o.m_size;
            m_data = std::unique_ptr<char[]>(new char[m_size]);
            operator=(o);
        }
    }

    const std::string payload::getM_description() const {
        try {
            return std::get<std::string>(m_description);
        }
        catch(const std::bad_variant_access& a){
            std::cout<< a.what()<<" at: string\n";
        }
        return "error";
    }

    const bool payload::getM_flag() const {
        try {
            return std::get<bool>(m_flag);
        }
        catch(const std::bad_variant_access& a){
            std::cout<< a.what()<<" at: bool\n";
        }
        return false;
    }

    const double payload::getM_value() const {
        try {
            return std::get<double>(m_value);
        }
        catch(const std::bad_variant_access& a){
            std::cout<< a.what()<<" at: double\n";
        }
        return 0.0;
    }

    const std::unique_ptr<char[]> &payload::getM_data() const {
        return m_data;
    }

    int payload::getM_size() const {
        return m_size;
    }

    payload &payload::operator=(const  DATA::payload &o) {
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

    payload::~payload(void) = default;
}


