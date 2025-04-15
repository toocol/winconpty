cmake_minimum_required (VERSION 3.8)

project ("winconpty")

if (WIN32)
    add_definitions(/utf-8)
endif()

if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS_RELEASE -Ofast)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O3  -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3  -Wall")

add_definitions(-DUNICODE)

include_directories("src/")

set(HEADERS 
	src/winconpty.h
	src/pipeio.h
	src/conptytypes.h
)
set(SOURCES
	src/winconpty.cpp
	src/pipeio.cpp
	src/conptytypes.cpp
)

add_library(winconpty STATIC
	${SOURCES}
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET winconpty PROPERTY CXX_STANDARD 20)
endif()

INSTALL(FILES 
	${HEADERS}
	DESTINATION
	include
)

INSTALL(TARGETS winconpty LIBRARY DESTINATION lib)
