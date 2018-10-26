//
// Created by Andrej Pistek on 18/10/2018.
//

#include "broker.h"
#include "map"

int broker::post(MAN::message &message) {
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
