#pragma once

#include <cstdio>
#include <cstdarg>
#include <ctime>
#include <vector>

#include "Logging/LoggerSink.hpp"

namespace Logging
{

#define LOG_DEBUG(fmt, ...) Logging::Logger::Log(Logging::LogLevel_Debug, Logging::Logger::GetCurrentTime(), __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_TRACE(fmt, ...) Logging::Logger::Log(Logging::LogLevel_Trace, Logging::Logger::GetCurrentTime(), __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_WARNING(fmt, ...) Logging::Logger::Log(Logging::LogLevel_Warning, Logging::Logger::GetCurrentTime(), __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) Logging::Logger::Log(Logging::LogLevel_Error, Logging::Logger::GetCurrentTime(), __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

	/*!
	@brief Static struct to handle logging to different sinks.
	*/
	struct LOGGING_API Logger
	{
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
		static const char* GetCurrentTime();

		/*!
		@brief Adds a sink to ::loggerSinks.
		@param _loggerSink The sink to add.
		*/
		static std::size_t AddSink(LoggerSink* _loggerSink);

		/*!
		@brief Assembles and sends a message to all sinks with the level @p _logLvl.
		@details You probably want to use the LOG_* macros instead of this function.
		@param _logLvl The level of the message.
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
