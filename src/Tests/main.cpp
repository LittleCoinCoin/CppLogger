
#include "Logging/ExeConsoleLoggerSink.hpp"
#include "Logging/Logger.hpp"
#include "Tests/TestLoggerSink.hpp"

int main()
{
	Logging::TestLoggerSink* testLoggerSink = new Logging::TestLoggerSink("TestLoggerSink");
	int testLoggerSinkIdx = Logging::Logger::AddSink(testLoggerSink);

	LOG_TRACE("This is a trace message.");
	LOG_TRACE("This is a trace message with an int: %u", 42);
	LOG_DEBUG("This is a debug message.");
	LOG_DEBUG("This is a debug message with a float: %f", 42.123f);
	LOG_ERROR("This is an error message.");
	LOG_ERROR("This is an error message with the hex format of %u: %x", 42, 42);
	LOG_WARNING("This is a warning message.");
	LOG_WARNING("This is a warning message with a string: %s", "forty two");

	// Test reprinting everything when only the trace level is enabled.
	Logging::Logger::SetEnabledLogLevels(Logging::LogLevelFlag_Trace);
	LOG_TRACE("This is a trace message when only this LogLevel is enabled.");
	LOG_DEBUG("This is a debug message when only the trace LogLevel is enabled."); // This should not be printed.
	LOG_ERROR("This is an error message when only the trace LogLevel is enabled."); // This should not be printed.
	LOG_WARNING("This is a warning message when only the trace LogLevel is enabled."); // This should not be printed.

	Logging::Logger::RemoveSink(testLoggerSinkIdx);
	delete testLoggerSink;

	Logging::Logger::SetEnabledLogLevels(Logging::LogLevelFlag_All);

	Logging::ExeConsoleLoggerSink* consoleExeLoggerSink = new Logging::ExeConsoleLoggerSink("ExeConsoleLoggerSink");
	int consoleExeLoggerSinkIdx = Logging::Logger::AddSink(consoleExeLoggerSink);

	LOG_TRACE("This is a trace message.");
	LOG_TRACE("This is a trace message with an int: %u", 42);
	LOG_DEBUG("This is a debug message.");
	LOG_DEBUG("This is a debug message with a float: %f", 42.123f);
	LOG_ERROR("This is an error message.");
	LOG_ERROR("This is an error message with the hex format of %u: %x", 42, 42);
	LOG_WARNING("This is a warning message.");
	LOG_WARNING("This is a warning message with a string: %s", "forty two");

	Logging::Logger::RemoveSink(consoleExeLoggerSinkIdx);
	delete consoleExeLoggerSink;

	return 0;
}
