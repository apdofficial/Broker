//
// Created by Andrej Pistek on 18/10/2018.
//

#ifndef ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H
#define ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H

#include "iostream"
#include "variant"

namespace DATA{
    class payload {
    private:
        std::variant<double,bool,std::string>m_value,m_flag,m_description;
    public:
        explicit payload(const double &value);
        explicit payload(const bool &flag);
        explicit payload(const std::string &description);
        payload(const DATA::payload &o, const std::string& type);
        const double& getM_value() const;
        const bool& getM_flag() const;
        const std::string& getM_description() const;

    };
}

#endif //ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H
