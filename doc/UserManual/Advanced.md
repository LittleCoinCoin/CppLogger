# Advanced {#advanced}

## Log Levels

CppLogger supports multiple log levels, allowing fine-grained control over which messages are logged. The log levels are defined in the `LogLevels.hpp` file:

- [LogLevel](#Logging::LogLevel)
  - `LogLevel_Debug`: Used for development and debugging messages.
  - `LogLevel_Error`: Reports errors.
  - `LogLevel_Trace`: Reports operations and general tracing information.
  - `LogLevel_Warning`: Reports warnings.

Each log level is associated with a bit flag that can be combined to enable or disable specific levels:

- [LogLevelFlag](#Logging::LogLevelFlag)
  - `LogLevelFlag_None`: No log levels are enabled.
  - `LogLevelFlag_Debug`: The Debug log level is enabled.
  - `LogLevelFlag_Error`: The Error log level is enabled.
  - `LogLevelFlag_Trace`: The Trace log level is enabled.
  - `LogLevelFlag_Warning`: The Warning log level is enabled.
  - `LogLevelFlag_All`: All log levels are enabled.

## Function Pointer Signatures in LoggerSink

In the [LoggerSink](#Logging::LoggerSink) class, function pointers are used to handle different log levels. There are two types of function pointers defined: `logFunc_pf` and `afix_pf`.

1. **logFunc_pf**: This type is used for logging message functions.

   ```cpp
   typedef void (LoggerSink::* logFunc_pf)(const char* _msg,
       const char* _time, const char* _file, const char* _function,
       int _line) const noexcept;
   ```

   - `_msg`: The log message.
   - `_time`: The time the message was logged.
   - `_file`: The file the message was logged from.
   - `_function`: The function the message was logged from.
   - `_line`: The line number in the file where the message was logged.

2. **afix_pf**: This type is used for logging prefix and suffix functions.

   ```cpp
   typedef void (LoggerSink::* afix_pf)(const char* _time,
       const char* _file, const char* _function, int _line) const noexcept;
   ```

   - `_time`: The time the message was logged.
   - `_file`: The file the message was logged from.
   - `_function`: The function the message was logged from.
   - `_line`: The line number in the file where the message was logged.

These function pointers are stored in arrays within the [LoggerSink](#Logging::LoggerSink) class ([loggingFunctions](#Logging::LoggerSink::loggingFunctions), [prefixFunctions](#Logging::LoggerSink::prefixFunctions), and [suffixFunctions](#Logging::LoggerSink::suffixFunctions)). Each index in the arrays corresponds to a specific log level [LogLevel](#Logging::LogLevel).

\remark If a function pointer is set to `nullptr` (default) for a particular log level, the message, prefix, or suffix will not be logged for that level.

## Adding Prefix and Suffix Functions

To add custom prefix and suffix functions to your logger sink, you need to define these functions in your custom sink class and register them similarly to how log functions are registered. Here’s an example to add the prefix and suffix for the Trace log level:

```cpp
#include "Logging/LoggerSink.hpp"

class CustomLoggerSink : public Logging::LoggerSink {
public:
    CustomLoggerSink(const char* name) : Logging::LoggerSink(name) {
        loggingFunctions[Logging::LogLevel_Trace] = static_cast<logFunc_pf>(&CustomLoggerSink::LogTrace);
        loggingFunctions[Logging::LogLevel_Debug] = static_cast<logFunc_pf>(&CustomLoggerSink::LogDebug);
        loggingFunctions[Logging::LogLevel_Error] = static_cast<logFunc_pf>(&CustomLoggerSink::LogError);
        loggingFunctions[Logging::LogLevel_Warning] = static_cast<logFunc_pf>(&CustomLoggerSink::LogWarning);

        prefixFunctions[Logging::LogLevel_Trace] = static_cast<afix_pf>(&CustomLoggerSink::PrefixTrace);
        suffixFunctions[Logging::LogLevel_Trace] = static_cast<afix_pf>(&CustomLoggerSink::SuffixTrace);

        // Register the other prefix/suffix pointer functions for the remaining log levels if needed.
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

    void PrefixTrace(const char* time, const char* file, const char* function, int line) const noexcept {
        // Implement your custom prefix for trace messages here
    }

    void SuffixTrace(const char* time, const char* file, const char* function, int line) const noexcept {
        // Implement your custom suffix for trace messages here
    }

    // Add the prefix/suffix for the remaining log levels if you need
};
```