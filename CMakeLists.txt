CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(split)

SET(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra -Weffc++ -std=c++98")

SET(SOURCE_FILES src/split.cpp src/main.cpp)
INCLUDE_DIRECTORIES("include")

ADD_EXECUTABLE(split ${SOURCE_FILES})
