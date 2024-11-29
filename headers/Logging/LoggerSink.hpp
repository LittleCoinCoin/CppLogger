#pragma once

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
		typedef void (LoggerSink::* logFunc_pf)(const char* /*_msg*/,
			const char* /*_time*/, const char* /*_file*/, const char* /*_function*/,
			int /*_line*/ ) const noexcept;
		logFunc_pf loggingFunctions[LogLevel_Count];

	public:

		LoggerSink() = default;

		virtual ~LoggerSink() = default;

		LOGGING_API void Log(LogLevel _lvl, const char* _msg,
			const char* _time, const char* _file, const char* _function, const int _line) noexcept;
	};
}