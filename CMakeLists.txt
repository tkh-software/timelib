cmake_minimum_required(VERSION 3.0.0)

project(TimeLib VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE EQUAL Release)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-DNDEBUG -Wall -O3")
endif()

option(BUILD_SHARED_LIBS "Build the shared library" OFF)
option(BUILD_TESTING "Build tests" OFF)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(CPUARCH x64)
else()
    set(CPUARCH x32)
endif()

if(WIN32)
    set(OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/windows/${CPUARCH}")
elseif(APPLE)
    set(OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/macos/${CPUARCH}")
else()
    set(OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/linux/${CPUARCH}")
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})

#BUILD

file(GLOB_RECURSE SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")

if(BUILD_SHARED_LIBS)
    add_library(timelib SHARED ${SRC})
else()
    add_library(timelib STATIC ${SRC})
endif()

target_include_directories(timelib PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_compile_features(timelib
    PRIVATE
    cxx_attributes
    cxx_defaulted_functions
    cxx_deleted_functions
    cxx_final
)

#INSTALL

install(TARGETS timelib LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/TimeLib"
        DESTINATION "include"
        FILES_MATCHING
        PATTERN "*.hpp"
)

#TESTS

include(CTest)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(tests)
endif ()

enable_testing()