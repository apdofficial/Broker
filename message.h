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
        std::string m_type;
        long long int m_timestamp;
    public:
        /* copy ctor */
        message(const MAN::message& o);

        /* ctors for individual types */
        message(const std::string &topic, const std::string &description);
        message(const std::string &topic, std::string &&description);
        message(const std::string &topic, const char* description);

        message(const std::string &topic, bool flag);
        message(const std::string &topic, double value);
        message(const std::string &topic,const char data[], int size);

        /* overloaded  operators */
        friend std::ostream& operator<<(std::ostream &os,const MAN::message &message1);
        friend bool operator< (const MAN::message& lhs, const MAN::message& rhs);

        /* getters */
        const std::string payload_to_json()const;
        const std::string& topic() const;
        const long long int& timestamp() const;

        /* time getter */
        const long long int get_time()const;

    };
}


#endif //ASSIGNMENT_5_MESSAGE_BROKER_DATE_T_H
