
#include "Logging/ExeConsoleLoggerSink.hpp"
#include "Logging/Logger.hpp"
#include "Tests/TestLoggerSink.hpp"

int main()
{
	Logging::TestLoggerSink* logSink = new Logging::TestLoggerSink();
	Logging::Logger::AddSink(logSink);

	LOG_TRACE("This is a trace message.");
	LOG_TRACE("This is a trace message with an int: %u", 42);
	LOG_DEBUG("This is a debug message.");
	LOG_DEBUG("This is a debug message with a float: %f", 42.123f);
	LOG_ERROR("This is an error message.");
	LOG_ERROR("This is an error message with the hex format of %u: %x", 42, 42);
	LOG_WARNING("This is a warning message.");
	LOG_WARNING("This is a warning message with a string: %s", "forty two");

	Logging::Logger::RemoveSink(0);
	delete logSink;

	Logging::ExeConsoleLoggerSink* consoleSink = new Logging::ExeConsoleLoggerSink();
	Logging::Logger::AddSink(consoleSink);

	LOG_TRACE("This is a trace message.");
	LOG_TRACE("This is a trace message with an int: %u", 42);
	LOG_DEBUG("This is a debug message.");
	LOG_DEBUG("This is a debug message with a float: %f", 42.123f);
	LOG_ERROR("This is an error message.");
	LOG_ERROR("This is an error message with the hex format of %u: %x", 42, 42);
	LOG_WARNING("This is a warning message.");
	LOG_WARNING("This is a warning message with a string: %s", "forty two");

	Logging::Logger::RemoveSink(0);
	delete consoleSink;

	return 0;
}
