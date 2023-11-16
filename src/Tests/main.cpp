
#include "Logging/Logger.hpp"
#include "Logging/ExeConsoleLoggerSink.hpp"

int main()
{
	Logging::ExeConsoleLoggerSink logSink;
	Logging::Logger::AddSink(new Logging::ExeConsoleLoggerSink());

	Logging::Logger::LogTrace("This is a trace message.");
	Logging::Logger::LogDebug("This is a debug message.");
	Logging::Logger::LogError("This is an error message.");
	Logging::Logger::LogWarning("This is a warning message.");

	return 0;
}
