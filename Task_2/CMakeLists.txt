cmake_minimum_required(VERSION 3.19)
project(Task_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task_2 main.cpp Server.cpp Server.h Client.cpp Client.h Comms.cpp Comms.h Exceptions/CreateSocketException.h Exceptions/SetSocketOptionsException.h)