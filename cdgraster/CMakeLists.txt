cmake_minimum_required(VERSION 2.8.11)

project(cdgraster)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUI ON)

include_directories (".")
include_directories ("include")
file(GLOB cdgdecode_SRC "src/*.h" "src/*.cpp")

add_library(cdgdecode SHARED IMPORTED)
set_target_properties( cdgdecode PROPERTIES IMPORTED_LOCATION "../cdgdecode/libcdgdecode.so" )

if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

find_package(Qt5Widgets)

add_executable(cdgraster ${cdgdecode_SRC})
target_include_directories(cdgraster PUBLIC "../cdgdecode")
target_include_directories(cdgraster PUBLIC "../cdgdecode/include")

target_link_libraries(cdgraster Qt5::Widgets)
target_link_libraries(cdgraster cdgdecode)

qt5_use_modules(cdgraster Widgets)
