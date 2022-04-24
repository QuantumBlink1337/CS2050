cmake_minimum_required(VERSION 3.22)
project(CS2050 C)

set(CMAKE_C_STANDARD 11)

include_directories(lab0)
include_directories(lab1)
include_directories(lab2)
include_directories(lab3)
include_directories(lab4)
include_directories(lab5)
include_directories(lab6)
include_directories(lab7)
include_directories(prelab5)
include_directories(prelab6)
include_directories(prelab7)
include_directories(prelab7/altlab7)
include_directories(prelab8)
include_directories(prelab9)
include_directories(prelab10)


add_executable(main prelab9/main.c prelab9/prelab9.c)
add_executable(prelab10_main prelab10/main.c prelab10/prelab10.c)

