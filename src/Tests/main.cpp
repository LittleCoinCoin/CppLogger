
#include "Logging/ExeConsoleLoggerSink.hpp"
#include "Logging/Logger.hpp"
#include "Tests/TestLoggerSink.hpp"

int main()
{
	Logging::TestLoggerSink* testLoggerSink = new Logging::TestLoggerSink();
	int testLoggerSinkIdx = Logging::Logger::AddSink(testLoggerSink);

	LOG_TRACE("This is a trace message.");
	LOG_TRACE("This is a trace message with an int: %u", 42);
	LOG_DEBUG("This is a debug message.");
	LOG_DEBUG("This is a debug message with a float: %f", 42.123f);
	LOG_ERROR("This is an error message.");
	LOG_ERROR("This is an error message with the hex format of %u: %x", 42, 42);
	LOG_WARNING("This is a warning message.");
	LOG_WARNING("This is a warning message with a string: %s", "forty two");

	Logging::Logger::RemoveSink(testLoggerSinkIdx);
	delete testLoggerSink;

	Logging::ExeConsoleLoggerSink* consoleExeLoggerSink = new Logging::ExeConsoleLoggerSink();
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
