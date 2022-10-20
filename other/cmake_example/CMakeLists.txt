cmake_minimum_required(VERSION 3.2)

set(SOURCES main.cpp sum.cpp)
set(HEADERS sum.h)

add_executable(work ${SOURCES} ${HEADERS})