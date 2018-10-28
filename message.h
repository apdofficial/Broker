//
// Created by Andrej Pistek on 18/10/2018.
//

#ifndef ASSIGNMENT_5_MESSAGE_BROKER_DATE_T_H
#define ASSIGNMENT_5_MESSAGE_BROKER_DATE_T_H

#include "iostream"
#include "payload.h"
#include "map"
#include "ctime"
#include <chrono>

namespace MAN {
    class message {
    private:
        DATA::payload m_payload;
        std::string m_topic;
        long long int m_timestamp;
        std::string m_type;
    public:
        const std::string &getM_topic() const;
        long long int getM_timestamp() const;
        message(const std::string &topic,const std::string &description);
        message(const std::string &topic,const bool &flag);
        message(const std::string &topic,const double &value);
        message(const std::string &topic,const char data[],const int& size);
        message(const MAN::message& o);
        std::string convert_payload_to_json()const;
        friend std::ostream& operator<<(std::ostream &os,const MAN::message &message1);
        friend bool operator< (const MAN::message& lhs, const MAN::message& rhs);
    };
}


#endif //ASSIGNMENT_5_MESSAGE_BROKER_DATE_T_H
