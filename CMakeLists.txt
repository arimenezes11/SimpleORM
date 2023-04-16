cmake_minimum_required(VERSION 3.8)
project(Database)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Database
        main.cpp
        Column.h
        Table.h
        Engine.cpp
        Engine.h
        Database.h
        Table.cpp
        Database.cpp
)
add_executable(
        test
        test.cpp
        Column.h
        Table.h
        Engine.cpp
        Engine.h
        Database.h
        Table.cpp
        Database.cpp
)