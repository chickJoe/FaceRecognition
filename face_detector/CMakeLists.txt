cmake_minimum_required(VERSION 3.5)
project(mylib VERSION 1.0.0 LANGUAGES CXX)

set(DEFAULT_BUILD_TYPE "Release")

include(GNUInstallDirs)

set(XML_PATH "${CMAKE_CURRENT_SOURCE_DIR}/haarcascade_frontalface_alt2.xml")
set(TEST_IMAGES_PATH "${CMAKE_CURRENT_SOURCE_DIR}/test/test_images/")

configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h @ONLY)

set(SOURCE_FILES src/face_detector.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

install(TARGETS ${PROJECT_NAME} EXPORT MyLibConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(EXPORT MyLibConfig DESTINATION share/MyLib/cmake)

export(TARGETS ${PROJECT_NAME} FILE MyLibConfig.cmake)

add_subdirectory(test)
