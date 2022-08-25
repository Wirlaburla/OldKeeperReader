cmake_minimum_required(VERSION 3.0)

project(oldkeeperfiler)

add_executable(oldkeeperfiler main.cpp)

install(TARGETS oldkeeperfiler RUNTIME DESTINATION bin)
