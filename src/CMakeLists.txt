cmake_minimum_required(VERSION 3.14)

add_library(tiny_zip tiny_zip.cpp)
add_library(dtor::tiny_zip ALIAS tiny_zip)

target_include_directories(tiny_zip PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

set_target_properties(tiny_zip PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED YES)
set_target_properties(tiny_zip PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)