# ./CMakeList.txt
cmake_minimum_required (VERSION 3.20)

project ("CppLogger")

# In Windows, generated dlls and .exe must be at the same place
# This makes sure that the dll will be at the same place as the .exe 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CACHE STRING "" )

if(MSVC)
	# In Windows, generated dlls and .exe must be at the same place
	# This makes sure that the dll will be at the same place as the .exe 
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CACHE STRING "" )
else()
	# Otherwise we shared libraries in a lib folder
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" CACHE STRING "" )
endif()
# For consistency we separate the potential .lib generated
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" CACHE STRING "")

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
