
#include "Logging/Logger.hpp"
#include "Tests/TestLoggerSink.hpp"

int main()
{
	Logging::TestLoggerSink logSink;
	Logging::Logger::AddSink(new Logging::TestLoggerSink());

	LOG_TRACE("This is a trace message.");
	LOG_TRACE("This is a trace message with an int: %u", 42);
	LOG_DEBUG("This is a debug message.");
	LOG_DEBUG("This is a debug message with a float: %f", 42.123f);
	LOG_ERROR("This is an error message.");
	LOG_ERROR("This is an error message with the hex format of %u: %x", 42, 42);
	LOG_WARNING("This is a warning message.");
	LOG_WARNING("This is a warning message with a string: %s", "forty two");

	return 0;
}
