# ~/src/Tests/DirectBuild/CMakeLists.txt

msg("Configure Test: DirectBuild")

add_compile_definitions(CRT_SECURE_NO_WARNINGS)

set(TargetName ${LOGGING_LIB_NAME}_DirectBuildTest)
add_executable (${TargetName}

"../main.cpp"

"../../Logging/ExeConsoleLoggerSink.cpp" #Included to test the build but not used in the test
"../../Logging/Logger.cpp"
"../../Logging/LoggerSink.cpp"

"../TestLoggerSink.cpp"
)

target_compile_features(${TargetName} PUBLIC cxx_std_20)

target_include_directories(${TargetName} PRIVATE "../../../headers")

if(RUNTIME_LOGGING_TESTS)
	add_test(NAME ${TargetName} COMMAND ${TargetName})
endif()