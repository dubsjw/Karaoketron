cmake_minimum_required(VERSION 2.8.11)

project(viewer)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

include_directories (".")
include_directories ("include")
file(GLOB viewer_SRC "src/*.h" "src/*.cpp" "src/*.ui")

if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

find_package(Qt5Widgets)

add_executable(viewer ${viewer_SRC})
target_include_directories(viewer PUBLIC "../cdgdecode")
target_include_directories(viewer PUBLIC "../cdgdecode/include")

target_include_directories(viewer PUBLIC "../cdgqt5")
target_include_directories(viewer PUBLIC "../cdgqt5/include")

target_link_libraries(viewer Qt5::Widgets)
target_link_libraries(viewer cdgdecode)
target_link_libraries(viewer cdgqt5)

qt5_use_modules(viewer Widgets)
