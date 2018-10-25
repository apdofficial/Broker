//
// Created by Andrej Pistek on 18/10/2018.
//

#include "broker.h"

broker::broker(MANAGEMENT::message message) {
    m_messages[message] = counter++;
}

int broker::post(const std::string &message) {
    return 0;
}
