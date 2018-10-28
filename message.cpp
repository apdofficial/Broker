//
// Created by Andrej Pistek on 18/10/2018.
//

#include "message.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "iostream"

namespace MAN {

    message::message(const std::string &topic, const std::string &description):
    m_payload {description},
    m_topic{topic},
    m_type {"string"}
    {
        auto now = std::chrono::system_clock::now();
        m_timestamp = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
    }

    message::message(const std::string &topic, const bool &flag):
    m_payload {flag},
    m_topic{topic},
    m_type {"bool"}
    {
        auto now = std::chrono::system_clock::now();
        m_timestamp = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
    }

    message::message(const std::string &topic, const double &value):
    m_payload {value},
    m_topic{topic},
    m_type {"double"}
    {
        auto now = std::chrono::system_clock::now();
        m_timestamp = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
    }
    message::message(const std::string &topic,const char data[],const int& size):
    m_payload {data, size},
    m_topic{topic},
    m_type {"data"}
    {
        auto now = std::chrono::system_clock::now();
        m_timestamp = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();

    }


    std::ostream& operator<<(std::ostream &os,const MAN::message &message1) {
        return os<<message1.m_timestamp<<" | "<<message1.m_topic<<" | "<<message1.convert_payload_to_json()<<"\n";
    }

    std::string message::convert_payload_to_json()const{
        std::ostringstream output;
            if(m_type == "string") {
                output<<"{type: \"" << m_type << "\", data: "<< m_payload.getM_description()<<"}";
            }
            else if  (m_type == "bool"){
                std::string flag;
                if(m_payload.getM_flag()){
                    flag.append("true");
                } else{
                    flag.append("false");
                }
                output<<"{type: \"" << m_type << "\", data: " <<flag<<"}";
            }
            else if (m_type == "double"){
                output<<"{type: \"" << m_type << "\", data: " << m_payload.getM_value()<<"}";
            }
            else if (m_type == "data"){
                output<<"{type: \"" << m_type << "\", data: ";
                for (int i = 0; i < m_payload.getM_size(); ++i) {
                    output<<"0x"<<(char32_t)m_payload.getM_data()[i]<<" ";
                }
                output<<"}";
            }
        return output.str();
    }

    message::message(const MAN::message& o) :
    m_timestamp {o.m_timestamp},
    m_topic {o.m_topic},
    m_type {o.m_type},
    m_payload {o.m_payload,o.m_type}
    {
       // m_payload  = o.m_payload;
    }

    bool operator<(const MAN::message &lhs, const MAN::message &rhs) {
        return lhs.m_timestamp < rhs.m_timestamp;
    }

    const std::string &message::getM_topic() const {
        return m_topic;
    }

    long long int message::getM_timestamp() const {
        return m_timestamp;
    }
}