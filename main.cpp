#include <iostream>
#include <vector>
#include "message.h"
#include "broker.h"
#include <exception>
int main() {
    char data[5]{4, 8, 16, 32, 64};
    sax::message m1{"/status/health/sens1", true};
    sax::message m2{"/status/health/motor1", false};
    sax::message m3{"/reading/value/sens1", 1.34};
    sax::message m4{"/reading/error/sens1", 0.07};
    sax::message m5{"/reading/value/motor1/current", 0.12};
    sax::message m6{"/status/diag/motor1/desc", "current too low"};
    sax::message m7{"/reading/value/imager", data, 5};

    std::cout<<"\n*****printing messages using operator<<*****"<<"\n";
    std::cout << m1  << "\n";
    std::cout << m2  << "\n";
    std::cout << m3  << "\n";
    std::cout << m4  << "\n";
    std::cout << m5  << "\n";
    std::cout << m6  << "\n";
    std::cout << m7  << "\n";

    saxion::broker br;
    auto id_m1 = br.post(m1);
    auto id_m2 = br.post(m2);
    auto id_m3 = br.post(m3);
    auto id_m4 = br.post(m4);
    auto id_m5 = br.post(m5);
    auto id_m6 = br.post(m6);
    auto id_m7 = br.post(m7);

    try {
        std::cout << "Using ID obtained from broker: ID: " << id_m6 << " message= " << br[id_m6]<<"\n";
    }
    catch (char const* e){
        std::cout<<e<<"\n";
    }

    std::cout<<"\n*********USING list(n)*******"<<"\n";
    auto listing = br.list("/*");
    for (auto& lst : listing){
        std::cout << lst << "\n";
    }

    std::cout<<"\n*********USING extract(n)*****"<<"\n";
    auto messages = br.extract("/reading/*");
    for (auto& message : messages){
        std::cout << message << "\n";
    }

    std::cout<<"\n*********USING get(n)*********"<<"\n";
    messages = br.get("/*");
    for (auto& message : messages) {
        std::cout << message << "\n";
    }

//    std::cout<<"\n"<<"\n";
//
//    for (auto iter = br.begin("/status/health/*"); iter != br.end(); ++iter ){
//        std::cout<<
//        iter->first.timestamp() << " : " <<
//        iter->first.topic() << ": "<<
//        iter->first.payload_to_json() <<"\n";
//    }
}