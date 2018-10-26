//
// Created by Andrej Pistek on 18/10/2018.
//

#include <vector>
#include <regex>
#include "broker.h"
#include "map"

int broker::post(const MAN::message &message) {
    m_messages.insert({message, ++counter});
    return counter;
}

MAN::message broker::operator[](int id_num) const {
    for(auto& [key,val]:m_messages){
        if(val == id_num){
            return key;
        }
    }
}

std::vector<std::string> broker::list(const std::string &request){
    std::vector<std::string> result = {};
    if(request.find_last_of('*')){
        std::string temp1 {request.substr(0,request.size()-1)};
        for (auto&[key, val]:m_messages) {
            if(temp1 == key.getM_topic().substr(0,temp1.size())) {
                result.push_back(std::to_string(val) + " : " + key.getM_topic());
            }
        }
    }
    return result;
}

std::vector<std::string> broker::extract(const std::string &request) {
    std::vector<std::string> result = {};
    if(request.find_last_of('*')){
        std::string temp1 {request.substr(0,request.size()-1)};
        for (auto&[key, val]:m_messages) {
            if(temp1 == key.getM_topic().substr(0,temp1.size())) {
                result.push_back(std::to_string(key.getM_timestamp())+" | "+key.getM_topic()+" | "+key.convert_payload_to_json());
            m_messages.erase(key);
            }
        }
    }
    return result;
}

std::vector<std::string> broker::get(const std::string &request)const {
    std::vector<std::string> result = {};
    if(request.find_last_of('*')){
        std::string temp1 {request.substr(0,request.size()-1)};
        for (auto&[key, val]:m_messages) {
            if(temp1 == key.getM_topic().substr(0,temp1.size())) {
                result.push_back(std::to_string(key.getM_timestamp())+" | "+key.getM_topic()+" | "+key.convert_payload_to_json());
            }
        }
    }
    return result;
}