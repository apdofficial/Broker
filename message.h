//
// Created by Andrej Pistek on 18/10/2018.
//

#ifndef ASSIGNMENT_5_MESSAGE_BROKER_DATE_T_H
#define ASSIGNMENT_5_MESSAGE_BROKER_DATE_T_H

#include "iostream"
#include "payload.h"
#include "map"
#include "ctime"

namespace MANAGEMENT {
    class message {
    private:
        DATA::payload m_payload;
        std::string m_topic;
        std::time_t m_timestamp;

    public:
        message(const std::string &topic, std::string description);
        message(const std::string &topic, bool flag);
        message(const std::string &topic, double value);
    };
}


#endif //ASSIGNMENT_5_MESSAGE_BROKER_DATE_T_H
