cmake_minimum_required(VERSION 3.12)
project(HW2_OOP)

set(CMAKE_CXX_STANDARD 98)

add_executable(HW2_OOP BeverageItem.cpp Customer.cpp BookkeepingEntry.cpp BeverageStore.cpp
        main.cpp)