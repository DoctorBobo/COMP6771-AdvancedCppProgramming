cmake_minimum_required(VERSION 3.0)
project(BAD_LIST CXX)

enable_testing()
include(CTest)

find_program(MEMORYCHECK_COMMAND valgrind)
if(MEMORYCHECK_COMMAND-NOTFOUND)
  message("[W] Valgrind not found")
else()
  message("Valgrind: ${MEMORYCHECK_COMMAND}")
  set(MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
  set(CMAKE_CXX_FLAGS_DEBUG "-O0 -fno-inline -g3 -fstack-protector-all")
  set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -g0 -DNDEBUG")
endif()

add_executable(test0a test0a.cpp)
add_test(test0a test0a)

add_executable(test0b test0b.cpp)
add_test(test0b test0b)

add_executable(test0c test0c.cpp)
add_test(test0c test0c)

add_executable(test1a test1a.cpp)
add_test(test1a test1a)

add_executable(test1b test1b.cpp)
add_test(test1b test1b)

add_executable(test1c test1c.cpp)
add_test(test1c test1c)

add_executable(test2a test2a.cpp)
add_test(test2a test2a)

add_executable(test2b test2b.cpp)
add_test(test2b test2b)

add_executable(test3a test3a.cpp)
add_test(test3a test3a)

add_executable(test3b test3b.cpp)
add_test(test3b test3b)

add_executable(test4a test4a.cpp)
add_test(test4a test4a)

add_executable(test4b test4b.cpp)
add_test(test4b test4b)

add_executable(test4c test4c.cpp)
add_test(test4c test4c)

add_executable(test4d test4d.cpp)
add_test(test4d test4d)

add_executable(test4e test4e.cpp)
add_test(test4e test4e)

add_executable(test4f test4f.cpp)
add_test(test4f test4f)

add_executable(test5a test5a.cpp)
add_test(test5a test5a)

add_executable(test5b test5b.cpp)
add_test(test5b test5b)

add_executable(test6a test6a.cpp)
add_test(test6a test6a)

add_executable(test6b test6b.cpp)
add_test(test6b test6b)

add_executable(test6c test6c.cpp)
add_test(test6c test6c)

add_executable(test7a test7a.cpp)
add_test(test7a test7a)

add_executable(test7b test7b.cpp)
add_test(test7b test7b)

add_executable(test7c test7c.cpp)
add_test(test7c test7c)

add_executable(test8 test8.cpp)
add_test(test8 test8)

add_executable(test9 test9.cpp)
add_test(test9 test9)

add_executable(test10 test10.cpp)
add_test(test10 test10)

add_executable(test11a test11a.cpp)
add_test(test11a test11a)

add_executable(test12a test12a.cpp)
add_test(test12a test12a)

add_executable(test12b test12b.cpp)
add_test(test12b test12b)
