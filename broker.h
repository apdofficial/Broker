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
    explicit broker(MANAGEMENT::message message);

private:
    int counter {0};

    std::map<MANAGEMENT::message,int> m_messages;
    int post(const std::string &message);
};


#endif //ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H
