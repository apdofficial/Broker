#include <iostream>
#include "message.h"

int main() {
    std::string messa{"a"};
    MANAGEMENT::message m1{"health",true};
    MANAGEMENT::message m2{"health",2.2};
    MANAGEMENT::message m3{"health","description"};
    MANAGEMENT::message message{"s",messa};
    return 0;
}