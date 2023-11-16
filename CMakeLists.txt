# ./CMakeList.txt
cmake_minimum_required (VERSION 3.20)

project ("CppLogger")

# In Windows, generated dlls and .exe must be at the same place
# This makes sure that the dll will be at the same place as the .exe 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CACHE STRING "" )
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CACHE STRING "" )

# For consistency we separate the potential .lib generated
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" CACHE STRING "")

#In this project, by default we want to build the tests
option(BUILD_LOGGER_TESTS "Build the test executable for the logger" ON)
if (BUILD_LOGGER_TESTS)
	add_subdirectory ("src/Tests")
endif()
