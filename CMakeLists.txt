# ./CMakeList.txt
cmake_minimum_required (VERSION 3.20)

project ("CppLogger")

# Building the library for the logger
option(BUILD_LOGGING_LIBRARY "Build the library for the logger" ON)
if (BUILD_LOGGING_LIBRARY)
	add_subdirectory ("src/Logging")
endif()

#In this project, by default we want to build the tests
option(BUILD_LOGGING_TESTS "Build the test executable for the logger" ON)
if (BUILD_LOGGING_TESTS)
	add_subdirectory ("src/Tests/DirectBuild")
	add_subdirectory ("src/Tests/SharedLibLink")
endif()
