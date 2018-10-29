#ifndef ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H
#define ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H

#include "map"
#include "message.h"
#include "vector"
#include <iterator>
#include "iterator"

namespace saxion {
    class broker {
    public:
        broker() = default;

        int post(const sax::message &message);

        sax::message operator[](int id_num) const;

        std::vector<std::string> list(std::string request);

        std::vector<sax::message> extract(std::string request);

        std::vector<sax::message> get(std::string request);

        std::map<int, sax::message>::const_iterator begin(std::string request);

        std::map<int, sax::message>::const_iterator end();

    private:
        int id{0};
        std::map<int, sax::message> m_messages;
    };
}

#endif //ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H
