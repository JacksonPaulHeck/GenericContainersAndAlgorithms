cmake_minimum_required(VERSION 3.14)
project(S21-P02-CustomContainers)
set(EXE_NAME CustomContainers)

foreach (file IN LISTS)
    configure_file(${file} ${file} COPYONLY)
endforeach ()

set(CMAKE_CXX_STANDARD 17)

add_executable(${EXE_NAME} src/main.cpp)
