# Overview {#mainpage}

## Purpose

The CppLogger repository provides a logging system for C++ projects. It allows to dispatch log messages to different "sinks" (outputs) with various log levels such as Debug, Trace, Warning, and Error.

## How to Use This Repository

### Cloning the Repository

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/LittleCoinCoin/CppLogger.git
   cd CppLogger
   ```

2. **Build Options**:
   The repository provides several build options that can be configured using CMake options:
   - `BUILD_LOGGING_LIBRARY` (default: ON): Build the library for the logger.
   - `BUILD_LOGGING_TESTS` (default: ON): Build the test executables for the logger.
   - `RUNTIME_LOGGING_TESTS` (default: ON): Run the tests after building. This option takes effect only if `BUILD_LOGGING_TESTS` is ON.

   You can set these options when running CMake:

   ```bash
   mkdir build
   cd build
   cmake -DBUILD_LOGGING_LIBRARY=ON -DBUILD_LOGGING_TESTS=ON -DRUNTIME_LOGGING_TESTS=ON ..
   make
   ```

3. **Using the Logger in Your Project**:
   You can use the logger in your project in two ways:

   - **Using the Shared Library**:
    Link against the `LoggingLib` library and include its headers.

        ```cmake
        target_link_libraries(your_target PRIVATE LoggingLib)
        target_include_directories(your_target PRIVATE ${CMAKE_SOURCE_DIR}/headers)
        ```
   - **Directly Including Source Files**:
    You can directly include the source files in your executable.

        ```cmake
        add_executable(your_target
        "path/to/your/source.cpp"

        "src/Logging/ExeConsoleLoggerSink.cpp"
        "src/Logging/Logger.cpp"
        "src/Logging/LoggerSink.cpp"
        )
        target_include_directories(your_target PRIVATE ${CMAKE_SOURCE_DIR}/headers)
        target_compile_features(your_target PUBLIC cxx_std_20)
        ```

4. **Building and Running Tests**:
   The repository includes tests for the logger, which are built and run by default if the corresponding options are enabled.

   ```bash
   cmake -DBUILD_LOGGING_TESTS=ON -DRUNTIME_LOGGING_TESTS=ON ..
   make
   ctest
   ```

   This will compile and run the tests located in the `src/Tests` directory.

### Adding as a Git Submodule

1. **Add the Repository as a Submodule**:

   ```bash
   git submodule add https://github.com/LittleCoinCoin/CppLogger.git path/to/CppLogger
   git submodule update --init --recursive
   ```

2. **Build Options**:
   Configure the build options as described above.

3. **Using the Logger in Your Project**:
   Follow the same instructions for using the logger in your project, whether linking against the `LoggingLib` library or directly including the source files. Adjust the paths accordingly to reflect the submodule's location.

For more detailed build and usage instructions, refer to the individual `CMakeLists.txt` files in the repository.

## How to Implement a Custom Logger Sink

To add your own valid logger sink to the CppLogger system, follow these steps:

1. **Create Your Custom Logger Sink**:
   Derive a class from `Logging::LoggerSink` and implement the required logging functions. Below is an example of how to create a new custom sink:

   ```cpp
   #include "Logging/LoggerSink.hpp"

   class CustomLoggerSink : public Logging::LoggerSink {
   public:
       CustomLoggerSink(const char* name) : Logging::LoggerSink(name) {
           loggingFunctions[Logging::LogLevel_Trace] = static_cast<logFunc_pf>(&CustomLoggerSink::LogTrace);
           loggingFunctions[Logging::LogLevel_Debug] = static_cast<logFunc_pf>(&CustomLoggerSink::LogDebug);
           loggingFunctions[Logging::LogLevel_Error] = static_cast<logFunc_pf>(&CustomLoggerSink::LogError);
           loggingFunctions[Logging::LogLevel_Warning] = static_cast<logFunc_pf>(&CustomLoggerSink::LogWarning);
       }

   private:
       void LogTrace(const char* msg, const char* time, const char* file, const char* function, int line) const noexcept {
           // Implement your custom logging for trace messages here
       }

       void LogDebug(const char* msg, const char* time, const char* file, const char* function, int line) const noexcept {
           // Implement your custom logging for debug messages here
       }

       void LogError(const char* msg, const char* time, const char* file, const char* function, int line) const noexcept {
           // Implement your custom logging for error messages here
       }

       void LogWarning(const char* msg, const char* time, const char* file, const char* function, int line) const noexcept {
           // Implement your custom logging for warning messages here
       }
   };
   ```

2. **Add Your Custom Sink to the Logger**:
   In your main application or test file, add an instance of your custom sink to the logger:

   ```cpp
   #include "Logging/Logger.hpp"
   #include "CustomLoggerSink.hpp"

   int main() {
       CustomLoggerSink* customSink = new CustomLoggerSink("CustomLoggerSink");
       int customSinkIdx = Logging::Logger::AddSink(customSink);

       LOG_TRACE("This is a trace message.");
       LOG_DEBUG("This is a debug message.");
       LOG_ERROR("This is an error message.");
       LOG_WARNING("This is a warning message.");

       Logging::Logger::RemoveSink(customSinkIdx);
       delete customSink;

       return 0;
   }
   ```

\note Users can also write `Prefix` and `Suffix` functions in the same way in their `CustomLoggerSink` if they want to add custom prefixes or suffixes to their log messages. See for instance how those were implemented in [TestLoggerSink](#Logging::TestLoggerSink).

For more examples, see the existing sink implementations `src/Logging/ExeConsoleLoggerSink.cpp` or `src/Tests/TestLoggerSink.cpp` and how it is used in `src/Tests/main.cpp`.
