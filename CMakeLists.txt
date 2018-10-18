cmake_minimum_required(VERSION 3.12)
project(Assignment_5_Message_broker)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment_5_Message_broker main.cpp message.cpp message.h playload.cpp playload.h broker.cpp broker.h)