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
		ExeConsoleLoggerSink() : LoggerSink()
		{
			loggingFunctions[LogLevel_Trace] = std::bind(&ExeConsoleLoggerSink::LogTrace, this, std::placeholders::_1);
			loggingFunctions[LogLevel_Debug] = std::bind(&ExeConsoleLoggerSink::LogDebug, this, std::placeholders::_1);
			loggingFunctions[LogLevel_Error] = std::bind(&ExeConsoleLoggerSink::LogError, this, std::placeholders::_1);
			loggingFunctions[LogLevel_Warning] = std::bind(&ExeConsoleLoggerSink::LogWarning, this, std::placeholders::_1);
		}

	private:
		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Trace
				and prints it in the console.
		*/
		void LogTrace(const char* _msg) const noexcept;

		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Debug
				and prints it in the console.
		*/
		void LogDebug(const char* _msg) const noexcept;

		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Error
				and prints it in the console.
		*/
		void LogError(const char* _msg) const noexcept;

		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Warning
				and prints it in the console.
		*/
		void LogWarning(const char* _msg) const noexcept;
	};
}