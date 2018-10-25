//
// Created by Andrej Pistek on 18/10/2018.
//

#include "message.h"

namespace MANAGEMENT {

    message::message(const std::string &topic, const std::string description):
    m_payload {description},
    m_topic{topic},
    m_timestamp {std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())}
    {}

    message::message(const std::string &topic, const bool flag):
    m_payload {flag},
    m_topic{topic},
    m_timestamp {std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())}
    {}

    message::message(const std::string &topic, const double value):
    m_payload {value},
    m_topic{topic},
    m_timestamp {std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())}
    {}
}