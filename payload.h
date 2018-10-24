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

    };
}

#endif //ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H
