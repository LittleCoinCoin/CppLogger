# ~/src/Logging/CMakeLists.txt

add_compile_definitions(CRT_SECURE_NO_WARNINGS)

set(TargetName ${LOGGING_LIB_NAME})

add_library(${TargetName} SHARED

"./ExeConsoleLoggerSink.cpp"
"./Logger.cpp"
"./LoggerSink.cpp"
)

target_compile_features(${TargetName} PUBLIC cxx_std_20)
target_compile_definitions(${TargetName} PRIVATE BUILD_LOGGING_LIB)

target_include_directories(${TargetName} PUBLIC

"../../headers"

)