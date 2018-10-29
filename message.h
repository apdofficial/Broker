#ifndef ASSIGNMENT_5_MESSAGE_BROKER_DATE_T_H
#define ASSIGNMENT_5_MESSAGE_BROKER_DATE_T_H

#include "iostream"
#include "payload.h"

namespace sax {
    class message {
    private:
        saxion::payload m_payload;
        std::string m_topic;
        std::string m_type;
        long long int m_timestamp;
    public:
        message(const sax::message &o);


        message(const std::string &topic, const std::string &description);

        message(const std::string &topic, std::string &&description);

        message(const std::string &topic, const char *description);

        message(const std::string &topic, bool flag);

        message(const std::string &topic, double value);

        message(const std::string &topic, const char *data, int size);

        friend std::ostream &operator<<(std::ostream &os, const sax::message &message1);

        friend bool operator<(const sax::message &lhs, const sax::message &rhs);

        const std::string payload_to_json() const;

        const std::string &topic() const;

        long long int timestamp() const;

        long long int get_time() const;

    };
}


#endif //ASSIGNMENT_5_MESSAGE_BROKER_DATE_T_H
