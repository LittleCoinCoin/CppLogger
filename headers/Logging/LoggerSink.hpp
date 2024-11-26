#pragma once
#include <string>
#include <functional>

#include "LogLevels.hpp"
#include "Export.hpp"

namespace Logging
{
	/*
	@brief LoggerSink is an interface for all sinks that can be added to the static logger.
	@details Derive from this class to create your new logging sink. Implement the Log functions
			 for each log level you want to support in the derived class and add them to the
			 loggingFunctions array.
			 Finally, add the instance of your new sink to the list of sinks in the Logger class.
	@see Logging::Logger
	*/
	class LoggerSink
	{
	protected:
		std::function<void(const char*)> loggingFunctions[LogLevel_Count];

	public:

		LOGGING_API LoggerSink() = default;

		LOGGING_API void Log(LogLevel _lvl, const char* _msg)
		{
			if (loggingFunctions[_lvl])
			{
				loggingFunctions[_lvl](_msg);
			}
		}
	};
}