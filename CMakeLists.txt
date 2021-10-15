cmake_minimum_required(VERSION 3.14)
project(S21-P02-CustomContainers)
set(EXE_NAME CustomContainers)

set(input01 "test/input_big.txt")
set(output01 "output/dict.txt")
set(output02 "output/find.txt")
set(output03 "output/list.txt")
set(output04 "output/vector_heap.txt")
set(output05 "output/vector_insertion.txt")
set(output06 "output/vector_quick.txt")
set(output07 "output/vector.txt")
set(output08 "output/data.csv")

foreach (file IN LISTS input01 output01 output02 output03 output04 output05 output06 output07 output08)
    configure_file(${file} ${file} COPYONLY)
endforeach ()

set(CMAKE_CXX_STANDARD 17)

add_executable(${EXE_NAME} src/main.cpp src/DataGen.cpp src/Driver.cpp)
