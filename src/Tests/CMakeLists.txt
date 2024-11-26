# ~/src/Tests/CMakeLists.txt

add_compile_definitions(CRT_SECURE_NO_WARNINGS)

set(TargetName LoggerTest)
add_executable (${TargetName}

"main.cpp"

"../Logging/ExeConsoleLoggerSink.cpp"
"../Logging/Logger.cpp"

)

target_compile_features(${TargetName} PUBLIC cxx_std_20)

target_include_directories(${TargetName} PRIVATE "../../headers")