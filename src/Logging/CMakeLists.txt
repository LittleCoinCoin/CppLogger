# ~/src/Logging/CMakeLists.txt

add_compile_definitions(CRT_SECURE_NO_WARNINGS)

set(TargetName LoggingLib)

add_library(${TargetName} SHARED

./Logger.cpp
./ExeConsoleLoggerSink.cpp

)

target_compile_features(${TargetName} PUBLIC cxx_std_20)

target_include_directories(${TargetName} PUBLIC

../../headers

)