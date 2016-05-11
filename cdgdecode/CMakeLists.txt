cmake_minimum_required (VERSION 3.0.2)
project (cdgdecode)

include_directories( "." )
include_directories( "include" )
file(GLOB cdgdecode_SRC "src/*.h" "src/*.cpp")
file(GLOB cdgdecode_TESTS "tests/*.cc" "tests/*.h")

if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

add_library(cdgdecode SHARED ${cdgdecode_SRC})
add_executable(CDGDecodeTests ${cdgdecode_SRC} ${cdgdecode_TESTS})
target_include_directories( CDGDecodeTests PUBLIC tests/catch )
target_include_directories( CDGDecodeTests PUBLIC tests )

target_compile_definitions(cdgdecode PRIVATE CDGDECODE_SHARED_LIBRARY=1)
