//
// Created by Andrej Pistek on 18/10/2018.
//

#ifndef ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H
#define ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H

#include "iostream"
#include "map"
#include "message.h"
#include "vector"
#include <iterator>
namespace saxion {
    class broker {
    public:
        broker() = default;

        int post(const sax::message &message);

        sax::message operator[](int id_num) const;

        std::vector<std::string> list(std::string request);

        std::vector<sax::message> extract(std::string request);

        std::vector<sax::message> get(std::string request);

        /* iterators */
        std::map<sax::message, int>::iterator begin(std::string str);

        std::map<sax::message, int>::iterator end();

    private:
        int id{0};
        std::map<int, sax::message> m_messages;
    };
}

#endif //ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H
