add_library(copyable copyable.cpp)

add_executable(test8 test8.cpp)
add_test(test8 test8)

add_executable(test9 test9.cpp)
add_test(test9 test9)

add_executable(test10 test10.cpp)
add_test(test10 test10)

add_executable(test11a test11a.cpp)
add_test(test11a test11a)

add_subdirectory(constructors)
add_subdirectory(copy-semantics)
add_subdirectory(move-semantics)
add_subdirectory(push)
add_subdirectory(iterators)
add_subdirectory(emplace)