#pragma once
#include "Logging/LoggerSink.hpp"

namespace Logging
{
	/*!
	@brief The Logger sink to receive log messages and print them in the
			executables console.
	*/
	class ExeConsoleLoggerSink : public LoggerSink
	{
	public:

		/*!
		@brief Default constructor that initializes the logging functions for
				each log level.
		*/
		LOGGING_API ExeConsoleLoggerSink() : LoggerSink()
		{
			loggingFunctions[LogLevel_Trace] = static_cast<LoggerSink::logFunc_pf>(&ExeConsoleLoggerSink::LogTrace);
			loggingFunctions[LogLevel_Debug] = static_cast<LoggerSink::logFunc_pf>(&ExeConsoleLoggerSink::LogDebug);
			loggingFunctions[LogLevel_Error] = static_cast<LoggerSink::logFunc_pf>(&ExeConsoleLoggerSink::LogError);
			loggingFunctions[LogLevel_Warning] = static_cast<LoggerSink::logFunc_pf>(&ExeConsoleLoggerSink::LogWarning);
		}

	private:
		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Trace
				and prints it in the console.
		*/
		void LogTrace(const char* _msg, const char* _time, const char* _file,
			const char* _function) const noexcept;

		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Debug
				and prints it in the console.
		*/
		void LogDebug(const char* _msg, const char* _time, const char* _file,
			const char* _function) const noexcept;

		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Error
				and prints it in the console.
		*/
		void LogError(const char* _msg, const char* _time, const char* _file,
			const char* _function) const noexcept;

		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Warning
				and prints it in the console.
		*/
		void LogWarning(const char* _msg, const char* _time, const char* _file,
			const char* _function) const noexcept;
	};
}