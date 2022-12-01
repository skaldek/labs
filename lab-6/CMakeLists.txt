cmake_minimum_required(VERSION 3.24)
set(PROJECT_NAME lab_6)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

include_directories("include/")

add_executable("${PROJECT_NAME}" main.cpp include/Read.h include/Calculate.h include/Write.h src/Read.cpp src/Calculate.cpp src/Write.cpp)

#file(COPY input.txt DESTINATION "/")
#file(COPY output.txt DESTINATION "/")
