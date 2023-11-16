# ~/src/Tests/CMakeLists.txt

add_compile_definitions(CRT_SECURE_NO_WARNINGS)

add_executable (Logger

"main.cpp"

"../Logging/ExeConsoleLoggerSink.cpp"
"../Logging/Logger.cpp"

)

set_property(TARGET Logger PROPERTY CXX_STANDARD 20)

target_include_directories(Logger PRIVATE "../../headers")