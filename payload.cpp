//
// Created by Andrej Pistek on 18/10/2018.
//

#include "payload.h"
#include "iostream"

namespace DATA{
    payload::payload(const double &value): m_value{value} {}
    payload::payload(const bool &flag): m_flag{flag} {}
    payload::payload(const std::string &description): m_description{description} {}

    payload::payload(const DATA::payload &o, const std::string& type) {
        if(type == "string"){
            m_description = o.m_description;
        } else if (type == "bool"){
            m_flag = o.m_flag;
        } else if (type == "double"){
            m_value = o.m_value;
        }
    }

    const std::string &payload::getM_description() const {
        try {
            return std::get<std::string>(m_description);
        }
        catch(const std::bad_variant_access& a){
            std::cout<< a.what()<<" at: string\n";
        }
    }

    const bool &payload::getM_flag() const {
        try {
            return std::get<bool>(m_flag);
        }
        catch(const std::bad_variant_access& a){
            std::cout<< a.what()<<" at: bool\n";
        }
    }

    const double &payload::getM_value() const {
        try {
            return std::get<double>(m_value);
        }
        catch(const std::bad_variant_access& a){
            std::cout<< a.what()<<" at: double\n";
        }
    }
}