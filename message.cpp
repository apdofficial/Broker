//
// Created by Andrej Pistek on 18/10/2018.
//

#include "message.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "iostream"

namespace sax {

    message::message(const std::string &topic, const std::string& description):
    m_payload {description},
    m_topic{topic},
    m_type {"string"},
    m_timestamp {get_time()}
    {}

    message::message(const std::string &topic, std::string&& description):
    m_payload{std::move(description)},
    m_topic{topic},
    m_type {"string"},
    m_timestamp {get_time()}
    {}

    message::message(const std::string &topic, const char* description):
    message(topic, std::string(description))
    {}

    message::message(const std::string &topic, bool flag):
    m_payload {flag},
    m_topic{topic},
    m_type {"bool"},
    m_timestamp {get_time()}
    {}

    message::message(const std::string &topic, double value):
    m_payload {value},
    m_topic{topic},
    m_type {"double"},
    m_timestamp {get_time()}
    {}

    message::message(const std::string &topic, const char *data, int size):
    m_payload {data, size},
    m_topic{topic},
    m_type {"data"},
    m_timestamp {get_time()}
    {}

    std::ostream& operator<<(std::ostream& os,const sax::message& message1) {
        return os<<message1.m_timestamp<<" | "<<message1.m_topic<<" | "<< message1.payload_to_json();
    }

    message::message(const sax::message& o) :
    m_timestamp {o.m_timestamp},
    m_topic {o.m_topic},
    m_type {o.m_type},
    m_payload {o.m_payload}
    {}

    bool operator<(const sax::message &lhs, const sax::message& rhs) {
        return lhs.m_topic < rhs.m_topic;
    }

    const std::string message::payload_to_json()const{
        std::ostringstream output;
        if(m_type == "string") {
            output<<"{type: \"" << m_type << "\", data: "<< m_payload.get_description()<<"}";
        }
        else if  (m_type == "bool"){
            std::string flag;
            if(m_payload.get_flag()){ flag.append("true"); }
            else{ flag.append("false"); }
            output<<"{type: \"" << m_type << "\", data: " <<flag<<"}";
        }
        else if (m_type == "double"){
            output<<"{type: \"" << m_type << "\", data: " << m_payload.get_value()<<"}";
        }
        else if (m_type == "data"){
            output<<"{type: \"" << m_type << "\", data: ";
            for (int i = 0; i < m_payload.get_size(); ++i) {
                output<<"0x"<<(char32_t)m_payload.get_data()[i]<<" ";
            }
            output<<"}";
        }
        return output.str();
    }
    const std::string &message::topic() const {
        return m_topic;
    }

    long long int message::timestamp() const {
        return (m_timestamp);
    }

    long long int sax::message::get_time()const{
        auto now = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
    }
}