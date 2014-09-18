set(CMAKE_LEGACY_CYGWIN_WIN32 0)

PROJECT(libadt CXX)
SET(CMAKE_BUILD_TYPE Release)
cmake_minimum_required(VERSION 2.8)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb ")
endif()

# build the sort library
ADD_EXECUTABLE(MyList MyList.cpp)
ADD_LIBRARY(adt SHARED MyList)
SET_TARGET_PROPERTIES(containers PROPERTIES COMPILE_FLAGS -std=c++11) 



