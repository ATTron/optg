cmake_minimum_required(VERSION 3.12)

project(OPTG VERSION 1.1 HOMEPAGE_URL \"https://github.com/attron\")

# check g++ version >= 4.9
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
        message(FATAL_ERROR "GCC Version must be at least 4.9!  " ${CMAKE_CXX_COMPILER_VERSION})
    endif()
endif()

## use c++ 11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

## setting globals
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(SRC_PATH ${PROJECT_SOURCE_DIR}/src)
set(SOURCES ${SRC_PATH}/optg.cxx ${SRC_PATH}/block.cxx ${SRC_PATH}/block.h ${SRC_PATH}/events.cxx ${SRC_PATH}/events.h)

configure_file(${SRC_PATH}/OPTGConfig.h.in OPTGConfig.h)

include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}" "${SRC_PATH}")
add_executable(OPTG ${SOURCES})
