file(GLOB SRCS *.cpp)

add_executable(test ${SRCS})
target_link_libraries(test mylib)

add_test(NAME test COMMAND test)