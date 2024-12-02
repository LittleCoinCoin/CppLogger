# ~/src/Tests/SharedLibLink/CMakeLists.txt

add_compile_definitions(CRT_SECURE_NO_WARNINGS)

# Building the lib first
set(TargetLibName LoggingLibTest)
add_library(${TargetLibName} SHARED

"../../Logging/ExeConsoleLoggerSink.cpp" #Included to test the build but not used in the test
"../../Logging/Logger.cpp"
"../../Logging/LoggerSink.cpp"

"../TestLoggerSink.cpp"
)

target_compile_features(${TargetLibName} PUBLIC cxx_std_20)
target_compile_definitions(${TargetLibName} PRIVATE BUILD_LOGGING_LIB)

target_include_directories(${TargetLibName} PUBLIC

"../../../headers"

)

# Building the exe that will test linking the logging library
set(TargetTestName LoggingExeWithLibLinkTest)
add_executable(${TargetTestName} 

"../main.cpp"

)

target_include_directories(${TargetTestName} PRIVATE

"../../../headers"

)

target_compile_features(${TargetTestName} PUBLIC cxx_std_20)
target_compile_definitions(${TargetTestName} PRIVATE USE_LOGGING_LIB)

# Add build dependencies
add_dependencies(${TargetTestName} ${TargetLibName})

target_link_libraries(${TargetTestName} PRIVATE ${TargetLibName})

if(RUNTIME_LOGGING_TESTS)
	add_test(NAME ${TargetTestName} COMMAND ${TargetTestName})
endif()