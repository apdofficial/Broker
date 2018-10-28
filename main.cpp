#include <iostream>
#include <vector>
#include "message.h"
#include "broker.h"
#include <exception>
int main() {
    // First create some messages. Two messages with boolean data
    MAN::message m1{"/status/health/sens1", true};
    MAN::message m2{"/status/health/motor1", false};
    // Three with numeric data
    MAN::message m3{"/reading/value/sens1", 1.34};
    MAN::message m4{"/reading/error/sens1", 0.07};
    MAN::message m5{"/reading/value/motor1/current", 0.12};
    // One containing a string data
    MAN::message m6{"/status/diag/motor1/desc", "current too low"};
    // And one with arbitrary binary data
    char data[5]{4, 8, 16, 32, 64};
    MAN::message m7{"/reading/value/imager", data, 5};

    // I can directly print messages, because they overload operator<<, e.g.:
    std::cout << m1  << "\n";
    std::cout << m2  << "\n";
    std::cout << m6  << "\n";
    std::cout << m7  << "\n";

// create a broker instance
    broker br;

// and post the messages:
    br.post(m1);
// broker returns a unique_id for each message posted to it, which can be captured
    auto id_m2 = br.post(m2);
    br.post(m1);
    br.post(m4);
    br.post(m5);
    br.post(m6);
    auto id_m7 = br.post(m7);
//this id can be used to obtain a message from the broker, but broker might also expose other information about a message:
    try {
        std::cout << "Using ID obtained from broker: ID: " << id_m7 << " message= " << br[id_m7];
    }
    catch (char const* e){
        std::cout<<e<<"\n";
    }
    //get listings of everything: this is just a list of messages, not full messages
    auto listing = br.list("/*");

// and print them, notice that lst is just a string and it's up to the broker
// how strings in listings are composed.
// My implementation contains only the unique message id and the topic of a listing entry
    for (auto& lst : listing){
        std::cout << lst << "\n";
    }


    // the extract function of the broker retrieves all the messages matching a topic.
// Those messages are also removed from the broker.
// Those are full messages being returned, like std::vector<message>
    auto messages = br.extract("/reading/*");

// let's print those messages that we got:
    for (auto& message : messages){
        std::cout << message << "\n";
    }

    messages = br.get("/*");
    for (auto& message : messages) {
        std::cout << message << "\n";
    }
}