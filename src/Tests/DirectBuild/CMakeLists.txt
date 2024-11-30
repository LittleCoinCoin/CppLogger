# ~/src/Tests/DirectBuild/CMakeLists.txt

add_compile_definitions(CRT_SECURE_NO_WARNINGS)

set(TargetName LoggerDirectBuildTest)
add_executable (${TargetName}

"../main.cpp"

"../../Logging/ExeConsoleLoggerSink.cpp" #Included to test the build but not used in the test
"../../Logging/Logger.cpp"
"../../Logging/LoggerSink.cpp"

"../TestLoggerSink.cpp"
)

target_compile_features(${TargetName} PUBLIC cxx_std_20)

target_include_directories(${TargetName} PRIVATE "../../../headers")