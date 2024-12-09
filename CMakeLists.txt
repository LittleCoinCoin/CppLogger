# ./CMakeList.txt
cmake_minimum_required (VERSION 3.20)

project ("CppLogger")

# Project options
## About the library
option(BUILD_LOGGING_LIBRARY "Build the library for the logger" ON)
set(LOGGING_LIB_NAME "Logger" CACHE STRING "The name of the library to be built")

## About the tests
option(BUILD_LOGGING_TESTS "Build the test executable for the logger" ON)
option(RUNTIME_LOGGING_TESTS "Run the tests after building. It has an effect only if BUILD_LOGGING_TESTS is ON." ON)

# Configuration
if (BUILD_LOGGING_LIBRARY)
	add_subdirectory ("src/Logging")
endif()

if (BUILD_LOGGING_TESTS)
	if (RUNTIME_LOGGING_TESTS)
		enable_testing()
	endif()
	add_subdirectory ("src/Tests/DirectBuild")
	add_subdirectory ("src/Tests/SharedLibLink")
endif()
