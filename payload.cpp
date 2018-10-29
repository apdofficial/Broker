//
// Created by Andrej Pistek on 18/10/2018.
//

#include "payload.h"
#include "iostream"

namespace DATA{
    /* ctors for individual types */
    payload::payload(const double &value): m_value{value} {}

    payload::payload(const bool &flag): m_value{flag} {}

    payload::payload(const std::string &description): m_value{description} {}
    payload::payload(std::string &&description) : m_value{std::move(description)}{}

    payload::payload(const char data[], const int& size):
        m_value{ blob(data, size) }
    {

    }

    /* copy ctors for all types */
//    payload::payload(const DATA::payload &o, const std::string& type) {
//        if (type == "string") {
//            m_description = o.m_description;
//        }
//        else if (type == "bool") {
//            m_flag = o.m_flag;
//        }
//        else if (type == "double") {
//            m_value = o.m_value;
//        }
//        else if ("data") {
//            m_size = o.m_size;
//            m_data = std::unique_ptr<char[]>(new char[m_size]);
//            operator=(o);
//        }
//    }

    /* copy  assignment operators */
//    payload& payload::operator=(const  DATA::payload &o){
//        if (this != &o) {
//            if (m_size != o.m_size) {
//                m_data = std::make_unique<char[]>(o.m_size);
//                m_size = o.m_size;
//            }
//
//            m_value = o.m_value;
//
//            for (int i = 0; i < m_size; ++i) {
//                m_data[i] = o.m_data[i];
//            };
//        }
//        return *this;
//    }

//    payload& payload::operator=(const char data[]) {
//        for (int i = 0; i < m_size; ++i) {
//            m_data[i] = data[i];
//        };
//        return *this;
//    }
//
//    /* destructor */
//    payload::~payload(void) = default;

    /* getters */
    const std::string& payload::get_description() const {
        return std::get<std::string>(m_value);
    }
    bool payload::get_flag() const {
        if (std::holds_alternative<bool>(m_value)){
            auto& data = std::get<bool>(m_value);
            return data;
        }
        throw std::logic_error("");
    }

    double payload::get_value() const {
        if (auto* data = std::get_if<double>(&m_value); data){
            return *data;
        }
        throw std::logic_error("");

    }

    const char* payload::get_data() const {
        if (std::holds_alternative<blob>(m_value)){
            auto& data = std::get<blob>(m_value);
            return data.arr.get();
        }
        return nullptr;
    }

    int payload::get_size() const {
        if (auto* data = std::get_if<blob>(&m_value); data){
            return data->size;
        }

//        if (std::holds_alternative<blob>(m_value)){
//            auto& data = std::get<blob>(m_value);
//            return data.size;
//        }
        return -1;
    }


}


