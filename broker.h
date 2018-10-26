//
// Created by Andrej Pistek on 18/10/2018.
//

#ifndef ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H
#define ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H

#include "iostream"
#include "map"
#include "message.h"

class broker {
public:
    broker() = default;
    int post(const MAN::message &message);
    MAN::message operator[](int id_num)const;
    std::vector<std::string> list(const std::string& request);
    std::vector<std::string> extract(const std::string& request);
    std::vector<std::string> get(const std::string& request)const;
private:
    int counter {0};
    std::map<MAN::message,int> m_messages;
};


#endif //ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H
