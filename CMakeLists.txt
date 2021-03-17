cmake_minimum_required(VERSION 3.10)

project(FaceRecognition VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(KEEP_RPATHS)

add_subdirectory(face_detector)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.cpp)

# add the executable
add_executable(FaceRecognition main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(FaceRecognition mylib)