cmake_minimum_required(VERSION 3.4)

project("EntityXLoader" C CXX)

set(CMAKE_CXX_STANDARD 17)

# Set output directory to ./binary
if(MSVC)
	foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
		string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
		set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_SOURCE_DIR}/binary")
		set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_SOURCE_DIR}/binary")
		set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_SOURCE_DIR}/binary")
	endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)
else(MSVC)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/binary")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/binary")
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/binary")
endif(MSVC)

# Include functions for downloading libs
include("functions.cmake")

# Add main folders
add_subdirectory("thirdparty")
add_subdirectory("source")

