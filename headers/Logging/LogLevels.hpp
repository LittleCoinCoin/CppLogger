#pragma once

/*!
@file LogLevels.hpp
@brief Declares the enum to describe log levels.
*/

namespace Logging
{
	/*!
	@brief An enum to describe different types of log levels.
	*/
	enum LogLevel : unsigned char
	{
		LogLevel_Debug, /*!< Intended to be used to print messages during development.*/
		LogLevel_Error, /*!< Reports errors.*/
		LogLevel_Trace, /*!< Reports operations.*/
		LogLevel_Warning, /*!< Reports warnings.*/

		LogLevel_Count /*!< The number of log levels.*/
	};

	/*!
	@brief An enum to describe which log levels are enabled.
	*/
	enum LogLevelFlag : unsigned char
	{
		LogLevelFlag_None = 0, /*!< No log levels are enabled.*/
		LogLevelFlag_Debug = 1 << LogLevel_Debug, /*!< The Debug log level is enabled.*/
		LogLevelFlag_Error = 1 << LogLevel_Error, /*!< The Error log level is enabled.*/
		LogLevelFlag_Trace = 1 << LogLevel_Trace, /*!< The Trace log level is enabled.*/
		LogLevelFlag_Warning = 1 << LogLevel_Warning, /*!< The Warning log level is enabled.*/
		LogLevelFlag_All = LogLevelFlag_Debug | LogLevelFlag_Error | LogLevelFlag_Trace | LogLevelFlag_Warning /*!< All log levels are enabled.*/
	};
}