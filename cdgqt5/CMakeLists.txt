cmake_minimum_required(VERSION 2.8.11)

project(cdgqt5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUI ON)

include_directories (".")
include_directories ("include")
file(GLOB cdgqt5_SRC "src/*.h" "src/*.cpp")

if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

find_package(Qt5Widgets)

add_library(cdgqt5 ${cdgqt5_SRC})
target_include_directories(cdgqt5 PUBLIC "../cdgqt5")
target_include_directories(cdgqt5 PUBLIC "../cdgqt5/include")
target_include_directories(cdgqt5 PUBLIC "../cdgdecode")
target_include_directories(cdgqt5 PUBLIC "../cdgdecode/include")

target_link_libraries(cdgqt5 Qt5::Widgets)
target_link_libraries(cdgqt5 cdgdecode)
