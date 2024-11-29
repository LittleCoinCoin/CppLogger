#pragma once

#include "LogLevels.hpp"
#include "Export.hpp"

namespace Logging
{
	/*
	@brief LoggerSink is an interface for all sinks that can be added to the static logger.
	@details Derive from this class to create your new logging sink. Implement the Log functions
			 for each log level you want to support in the derived class and add them to the
			 loggingFunctions array. You can also implement the Prefix functions to add a prefix
			 to the message. Add these to the prefixFunctions array.
			 Finally, add the instance of your new sink to the list of sinks in the Logger class.
	@see Logging::Logger
	*/
	class LoggerSink
	{
	protected:

		/*!
		@brief A custom type for the function pointer to log messages.
		*/
		typedef void (LoggerSink::* logFunc_pf)(const char* /*_msg*/,
			const char* /*_time*/, const char* /*_file*/, const char* /*_function*/,
			int /*_line*/ ) const noexcept;

		/*!
		@brief The array of function pointers to log messages for each log level.
		@details The index of the function in the array corresponds to the Logging::LogLevel.
				 By default it is full of nullptrs. If you do not set a function pointers
				 for a log level, the message will not be logged.
		*/
		logFunc_pf loggingFunctions[LogLevel_Count] = { nullptr };

		/*!
		@brief A custom type for the function pointer to log the prefix of a message.
		*/
		typedef void (LoggerSink::* prefix_pf)( const char* /*_time*/,
			const char* /*_file*/, const char* /*_function*/, int /*_line*/) const noexcept;
		/*!
		@brief The array of function pointers to log the prefix for each log level.
		@details The index of the function in the array corresponds to the Logging::LogLevel.
				 By default it is full of nullptrs. If you do not set a function pointers
				 for a log level, the prefix will not be logged.
		*/
		prefix_pf prefixFunctions[LogLevel_Count] = { nullptr };

	public:

		LoggerSink() = default;

		virtual ~LoggerSink() = default;

		/*!
		@brief The function to log a message.
		@param _lvl The level of the message.
		@param _msg The message to log.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		LOGGING_API void Log(LogLevel _lvl, const char* _msg,
			const char* _time, const char* _file, const char* _function, const int _line) noexcept;
	
		/*!
		@brief The function to log the prefix of a message.
		@param _lvl The level of the message.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		LOGGING_API void Prefix(LogLevel _lvl, const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;
	};
}