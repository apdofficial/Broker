//
// Created by Andrej Pistek on 18/10/2018.
//

#include <vector>
#include <regex>
#include "broker.h"
#include "map"
#include "iostream"

int broker::post(const MAN::message &message) {
    m_messages.insert({message, ++counter});
    return counter;
}

MAN::message broker::operator[](int id_num) const{
        for (auto&[key, val]:m_messages) {
            if (val == id_num) {
                return key;
            }
        }
        throw "no candidate was found under given ID";
}

std::vector<std::string> broker::list(const std::string &request){
    std::vector<std::string> result = {};
    std::string temp1;
    if(request.find_last_of('*')) {
        temp1.append(request.substr(0, request.size() - 1));
    }
        for (auto&[key, val]:m_messages) {
            if(temp1 == key.topic().substr(0,temp1.size())) {
                result.push_back(std::to_string(val) + " : " + key.topic());
            }
        }
    return result;
}

std::vector<std::string> broker::extract(const std::string &request) {
    std::vector<std::string> result = {};
    std::string temp1;
    if(request.find_last_of('*')) {
        temp1.append(request.substr(0, request.size() - 1));
    }
        for (auto&[key, val]:m_messages) {
            if(temp1 == key.topic().substr(0,temp1.size())) {
                result.push_back(std::to_string(
                        key.timestamp())+" | "+
                        key.topic()+" | "+
                        key.payload_to_json());
            m_messages.erase(key);
            }
        }
    return result;
}

std::vector<std::string> broker::get(const std::string &request)const {
    std::vector<std::string> result = {};
    std::string temp1;
    if(request.find_last_of('*')) {
        temp1.append(request.substr(0, request.size() - 1));
    }
        for (auto&[key, val]:m_messages) {
            if(temp1 == key.topic().substr(0,temp1.size())) {
                result.push_back(std::to_string(
                        key.timestamp())+" | "+
                        key.topic()+" | "+
                        key.payload_to_json());
            }
        }
    return result;
}

std::map<MAN::message,int>::iterator broker::begin(std::string str){
    std::string temp1;
    if(str.find_last_of('*')) {
        temp1.append(str.substr(0, str.size() - 1));
    }
    for ( auto current = m_messages.begin(); current != m_messages.end(); ++current){
        if (temp1 == current.operator->()->first.topic().substr(0, temp1.size())) {
            return current;
        }
    }
}

std::map<MAN::message,int>::iterator broker::end(){
    return m_messages.end();
}
