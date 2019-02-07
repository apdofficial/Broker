cmake_minimum_required(VERSION 3.12)
project(Assignment_5_Message_broker)

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(Assignment_5_Message_broker main.cpp message.cpp message.h payload.cpp payload.h broker.cpp broker.h)

