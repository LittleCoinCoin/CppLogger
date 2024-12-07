#pragma once

/*!
@file Logger.hpp
@brief Declares the static struct to handle logging to different sinks.
@details The functions in this struct are the main interface to the logging system.
		 But a user is expected to use the LOG_* macros instead of these functions.
		 These macros indeed call the functions with a set of predefined arguments
		 making everything easier for the user.
*/

#include <cstdio>
#include <cstdarg>
#include <ctime>
#include <vector>

#include "Logging/LoggerSink.hpp"

namespace Logging
{

/*!
@brief The macro to log a message with the level Debug.
@details It accepts variadic arguments to replace the formating anchors in the message.
*/
#define LOG_DEBUG(fmt, ...) Logging::Logger::Log(Logging::LogLevel_Debug, Logging::Logger::GetFormattedTime(), __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

/*!
@brief The macro to log a message with the level Trace.
@details It accepts variadic arguments to replace the formating anchors in the message.
*/
#define LOG_TRACE(fmt, ...) Logging::Logger::Log(Logging::LogLevel_Trace, Logging::Logger::GetFormattedTime(), __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

/*!
@brief The macro to log a message with the level Warning.
@details It accepts variadic arguments to replace the formating anchors in the message.
*/
#define LOG_WARNING(fmt, ...) Logging::Logger::Log(Logging::LogLevel_Warning, Logging::Logger::GetFormattedTime(), __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

/*!
@brief The macro to log a message with the level Error.
@details It accepts variadic arguments to replace the formating anchors in the message.
*/
#define LOG_ERROR(fmt, ...) Logging::Logger::Log(Logging::LogLevel_Error, Logging::Logger::GetFormattedTime(), __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

	/*!
	@brief Static struct to handle logging to different sinks.
	*/
	struct LOGGING_API Logger
	{
		/*!
		@brief The log level flag to determine which log levels are enabled.
				By default all log levels are enabled.
		@details To disable a log level, set the corresponding bit to 0. In such
				 cases, messages of that will not be dispatched to the sinks.
		*/
		static LogLevelFlag logLevelFlag;

		/*!
		@brief Maximum size of a message that can be logged at a time.
		*/
		static constexpr unsigned short maxMsgBufferSize = 1024;

		/*!
		@brief Buffer to store the message to be logged.
		@details This is sent to sinks.
		*/
		static char msgBuffer[maxMsgBufferSize];

		/*!
		@brief The sinks to log to.
		*/
		static std::vector<LoggerSink*> loggerSinks;

		/*!
		@brief Gets the current time in the format "YYYY-MM-DD HH:MM:SS".
		@details Uses a static buffer to store the time. Hence the return
				 value is not thread safe.
		@return The current time.
		@todo Make this thread safe.
		*/
		static const char* GetFormattedTime();

		/*!
		@brief Sets the value of ::logLevelFlag to that of @p _logLvlFlag.
		@details ::logLevelFlag is also public, but we advise using this 
				 function for clarity. It's up to you ;)
		*/
		static void SetEnabledLogLevels(LogLevelFlag _logLvlFlag) noexcept;

		/*!
		@brief Adds a sink to ::loggerSinks.
		@param _loggerSink The sink to add.
		@return The index of the new sink in ::loggerSinks.
		*/
		static std::size_t AddSink(LoggerSink* _loggerSink);

		/*!
		@brief Checks if the log level is enabled.
		@details Performs a bitwise AND operation on the log level flag and the
				 log level to check if the log level is enabled.
		@param _logLvl The log level to check.
		@return True if the log level is enabled, false otherwise.
		*/
		static bool IsLogLevelEnabled(LogLevel _logLvl) noexcept;

		/*!
		@brief Assembles and sends a message to all sinks with the level @p _logLvl.
		@details You probably want to use the LOG_* macros instead of this function.
		@param _logLvl The level of the message.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		@param _fmt The message to log containing formating anchors.
		@param ... The arguments to replace the formating anchors with.
		*/
		static void Log(LogLevel _logLvl, const char* _time, const char* _file,
			const char* _function, const int _line, const char* _fmt, ...) noexcept;

		/*!
		@brief Removes the sink at index @p _idx from ::loggerSinks.
		@param _idx The index of the sink to remove.
		*/
		static void RemoveSink(std::size_t _idx);
	};
}
