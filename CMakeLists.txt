cmake_minimum_required(VERSION 3.27)
project(Final_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Final_Project main.cpp
        Time.h
        Time.cpp
        Date.h
        Date.cpp
        AirQuality.cpp
        AirQuality.h
        Vector.cpp
        Vector.h
        MenuItem.cpp
        MenuItem.h
)