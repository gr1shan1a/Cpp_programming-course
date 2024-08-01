cmake_minimum_required(VERSION 3.25)
project(TP_lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP_lab1 main.cpp PublicQueue.cpp ProtectedQueue.cpp Queue.cpp PrivateQueue.cpp)
