set(CMAKE_LEGACY_CYGWIN_WIN32 0)

PROJECT(libadt CXX)
SET(CMAKE_BUILD_TYPE Release)
cmake_minimum_required(VERSION 2.8)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -I../include -I../common/include -Iinclude -L../src")
endif()

ADD_EXECUTABLE(main src/main.cpp src/array_test.cpp)
TARGET_LINK_LIBRARIES(main adt)
