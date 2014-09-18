set(CMAKE_LEGACY_CYGWIN_WIN32 0)

PROJECT(libadt CXX)
SET(CMAKE_BUILD_TYPE Release)
cmake_minimum_required(VERSION 2.8)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -I../include -I../common/include")
endif()

# build the sort library
SET(SRCS MyAlgorithms.cpp MyAssociation.cpp MyContainer.cpp MyGraph.cpp MyHashTable.cpp MyHeap.cpp MyList.cpp MyObject.cpp MyPool.cpp MyQueue.cpp MySet.cpp MySort.cpp MyStack.cpp MyTree.cpp)

# ADD_EXECUTABLE(MyList.o MyList.cpp)
ADD_LIBRARY(adt SHARED ${SRCS})
#SET_TARGET_PROPERTIES(containers PROPERTIES COMPILE_FLAGS -std=c++11) 



