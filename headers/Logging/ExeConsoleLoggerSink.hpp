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
		LOGGING_API ExeConsoleLoggerSink(const char* _name) : LoggerSink(_name)
		{
			loggingFunctions[LogLevel_Trace] = static_cast<LoggerSink::logFunc_pf>(&ExeConsoleLoggerSink::LogTrace);
			loggingFunctions[LogLevel_Debug] = static_cast<LoggerSink::logFunc_pf>(&ExeConsoleLoggerSink::LogDebug);
			loggingFunctions[LogLevel_Error] = static_cast<LoggerSink::logFunc_pf>(&ExeConsoleLoggerSink::LogError);
			loggingFunctions[LogLevel_Warning] = static_cast<LoggerSink::logFunc_pf>(&ExeConsoleLoggerSink::LogWarning);
		
			prefixFunctions[LogLevel_Trace] = static_cast<LoggerSink::afix_pf>(&ExeConsoleLoggerSink::PrefixTrace);
			prefixFunctions[LogLevel_Debug] = static_cast<LoggerSink::afix_pf>(&ExeConsoleLoggerSink::PrefixDebug);
			prefixFunctions[LogLevel_Error] = static_cast<LoggerSink::afix_pf>(&ExeConsoleLoggerSink::PrefixError);
			prefixFunctions[LogLevel_Warning] = static_cast<LoggerSink::afix_pf>(&ExeConsoleLoggerSink::PrefixWarning);
		}

	private:
		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Trace
				and prints it in the console.
		@details This function is meant to be registered in the ::loggingFunctions
				 array for the @a LogLevel_Trace.
		@param _msg The message to log.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		void LogTrace(const char* _msg, const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;

		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Debug
				and prints it in the console.
		@details This function is meant to be registered in the ::loggingFunctions
				 array for the @a LogLevel_Debug.
		@param _msg The message to log.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		void LogDebug(const char* _msg, const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;

		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Error
				and prints it in the console.
		@details This function is meant to be registered in the ::loggingFunctions
				 array for the @a LogLevel_Error.
		@param _msg The message to log.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		void LogError(const char* _msg, const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;

		/*!
		@brief Forwards a message (@p _msg) to indicate it is of type @a Warning
				and prints it in the console.
		@details This function is meant to be registered in the ::loggingFunctions
				 array for the @a LogLevel_Warning.
		@param _msg The message to log.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		void LogWarning(const char* _msg, const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;

		/*!
		@brief Prints the prefix for a message of type @a Trace in the console.
		@details This function is meant to be registered in the ::prefixFunctions
				 array for the @a LogLevel_Trace.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		void PrefixTrace(const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;

		/*!
		@brief Prints the prefix for a message of type @a Debug in the console.
		@details This function is meant to be registered in the ::prefixFunctions
				 array for the @a LogLevel_Debug.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		void PrefixDebug(const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;

		/*!
		@brief Prints the prefix for a message of type @a Error in the console.
		@details This function is meant to be registered in the ::prefixFunctions
				 array for the @a LogLevel_Error.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		void PrefixError(const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;

		/*!
		@brief Prints the prefix for a message of type @a Warning in the console.
		@details This function is meant to be registered in the ::prefixFunctions
				 array for the @a LogLevel_Warning.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		void PrefixWarning(const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;
	};
}