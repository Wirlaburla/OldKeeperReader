cmake_minimum_required(VERSION 3.0)

project(oldkeeperreader)

add_executable(
    oldkeeperreader
    src/main.cpp
    src/bmp.h
    src/dumbutil.h
)

install(TARGETS oldkeeperreader RUNTIME DESTINATION bin)
