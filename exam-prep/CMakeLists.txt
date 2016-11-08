cmake_minimum_required(VERSION 2.8)
project(BAD_LIST CXX)

enable_testing()
include(CTest)

include_directories(include)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
endif()

add_subdirectory(test)
