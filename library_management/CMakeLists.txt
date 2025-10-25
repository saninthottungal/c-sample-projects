cmake_minimum_required(VERSION 4.1.2)

project(LibraryManagement C)

include_directories(include)

set(
    SOURCES 
        src/main.c 
        src/library.c
)

add_executable(library_app ${SOURCES})