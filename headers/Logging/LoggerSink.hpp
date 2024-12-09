#pragma once

/*!
@file LoggerSink.hpp
@brief Declares the interface for a sink for the logger.
*/

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
		@brief A custom type for the function pointer to log the prefix or suffix of a message.
		*/
		typedef void (LoggerSink::* afix_pf)( const char* /*_time*/,
			const char* /*_file*/, const char* /*_function*/, int /*_line*/) const noexcept;
		/*!
		@brief The array of function pointers to log the prefix for each log level.
		@details The index of the function in the array corresponds to the Logging::LogLevel.
				 By default it is full of nullptrs. If you do not set a function pointers
				 for a log level, the prefix will not be logged.
		*/
		afix_pf prefixFunctions[LogLevel_Count] = { nullptr };

		/*!
		@brief The array of function pointers to log the suffix for each log level.
		@details The index of the function in the array corresponds to the Logging::LogLevel.
				 By default it is full of nullptrs. If you do not set a function pointers
				 for a log level, the suffix will not be logged.
		*/
		afix_pf suffixFunctions[LogLevel_Count] = { nullptr };

		/*!
		@brief The function to log the prefix of a message.
		@param _lvl The level of the message.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		void Prefix(LogLevel _lvl, const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;

		/*!
		@brief The function to log the suffix of a message.
		@param _lvl The level of the message.
		@param _time The time the message was logged.
		@param _file The file the message was logged from.
		@param _function The function the message was logged from.
		@param _line The line (in the file) the message was logged from.
		*/
		void Suffix(LogLevel _lvl, const char* _time, const char* _file,
			const char* _function, const int _line) const noexcept;

	public:

		/*!
		@brief The name of the logger sink.
		*/
		const char* name = nullptr;

		/*!
		@brief Default constructor that initializes the name of the sink.
		@param _name The name of the sink.
		*/
		LoggerSink(const char* _name) : name(_name) {}

		/*!
		@brief Default destructor.
		*/
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
	};
}