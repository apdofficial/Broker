#include <vector>
#include "broker.h"
#include "map"
#include "iostream"

namespace saxion {
    int broker::post(const sax::message &message) {
        m_messages.insert({++id, message});
        return id;
    }

    sax::message broker::operator[](int id) const {
        return m_messages.at(id);
    }

    std::vector<std::string> broker::list(std::string request) {
        std::vector<std::string> result = {};
        bool wild = false;
        if (request.back() == '*') {
            wild = true;
            request = request.substr(0, request.length() - 1);
        }
        for (auto&[id, m_message]:m_messages) {
            auto &topic = m_message.topic();
            if ((wild && topic.find_first_of(request) == 0) || (!wild && topic == request)) {
                result.push_back(std::to_string(id) + " : " + m_message.topic());
            }
        }
        return result;
    }

    std::vector<sax::message> broker::extract(std::string request) {
        std::vector<sax::message> result = {};
        bool wild = false;
        if (request.back() == '*') {
            wild = true;
            request = request.substr(0, request.length() - 1);
        }
        for (auto&[id, m_message]:m_messages) {
            auto &topic = m_message.topic();
            if ((wild && topic.find_first_of(request) == 0) || (!wild && topic == request)) {
                result.push_back(m_message);
                m_messages.erase(id);
            }
        }
        return result;
    }

    std::vector<sax::message> broker::get(std::string request) {
        std::vector<sax::message> result = {};
        bool wild = false;
        if (request.back() == '*') {
            wild = true;
            request = request.substr(0, request.length() - 1);
        }
        for (auto&[id, m_message]:m_messages) {
            auto &topic = m_message.topic();
            if ((wild && topic.find_first_of(request) == 0) || (!wild && topic == request)) {
                result.push_back(m_message);
            }
        }
        return result;
    }

    std::map<int, sax::message>::const_iterator broker::begin(std::string request) {
        if (request.back() == '*') {
            request = request.substr(0, request.length() - 1);
        }
        for ( auto current = m_messages.begin(); current != m_messages.end(); ++current){
            if (request == current->second.topic().substr(0, request.size())) {
                return current;
            }
        }
    }

    std::map<int, sax::message>::const_iterator broker::end() {
        return m_messages.end();
    }
}