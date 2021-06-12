cmake_minimum_required(VERSION 2.8)
project(deeprain)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -g -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

include_directories(.)
include_directories(/usr/local/include)
link_directories(/usr/local/lib64)

find_library(YAMLCPP libyaml-cpp.a)

set(LIB_SRC
    deeprain/log.cc
    deeprain/util.cc
    deeprain/config.cc
    )

add_library(deeprain SHARED ${LIB_SRC})

add_executable(test tests/test.cc)
add_dependencies(test deeprain)
target_link_libraries(test deeprain)

add_executable(test_config tests/test_config.cc)
add_dependencies(test_config deeprain)
target_link_libraries(test_config deeprain -L/usr/local/lib64 -lyaml-cpp)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
