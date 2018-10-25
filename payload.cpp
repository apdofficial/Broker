//
// Created by Andrej Pistek on 18/10/2018.
//

#include "payload.h"

namespace DATA{
    payload::payload(const double &value): m_value{value} {}
    payload::payload(const bool &flag): m_flag{flag} {}
    payload::payload(const std::string &description): m_description{description} {}
}