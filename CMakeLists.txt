# ./CMakeList.txt
cmake_minimum_required (VERSION 3.20)

project ("CppLogger")

# -- Cmake utility
set(CMAKE_CPPPROFILER_MSG_PREFIX "[CppLogger] ")
function(msg _msg)
	message("${CMAKE_CPPPROFILER_MSG_PREFIX}${_msg}")
endfunction()

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
	msg("Building the tests")
	if (RUNTIME_LOGGING_TESTS)
		msg("Adding runtime tests.
		Don't forget to launch them after building using `ctest` command.
		As this is using a multi-config generator, specifying the config with `-C <CONFIG>` is mandatory.")
		enable_testing()
	endif()
	add_subdirectory ("src/Tests/DirectBuild")
	add_subdirectory ("src/Tests/SharedLibLink")
endif()
