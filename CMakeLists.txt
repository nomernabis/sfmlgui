cmake_minimum_required(VERSION 3.2)
project(UI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ui/Container.cpp ui/Container.h ui/Node.cpp ui/Node.h ui/Utils.cpp ui/Utils.h)
add_executable(UI ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(UI ${SFML_LIBRARIES})
endif()
