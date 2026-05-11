cmake_minimum_required(VERSION 4.1)
project(RankigAcademico)

set(CMAKE_CXX_STANDARD 20)

add_executable(RankingAcademico
        Src/main.cpp
        Src/Student.h
        Src/AVL.cpp
        Src/AVL.h)

