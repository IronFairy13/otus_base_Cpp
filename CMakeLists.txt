cmake_minimum_required(VERSION 3.5.0)
project(guess_number)

add_executable(guess_number 
guess_number.cpp
profiles.cpp
profiles.h
parametrs.cpp
parametrs.h
)

set_target_properties(guess_number PROPERTIES
       CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
