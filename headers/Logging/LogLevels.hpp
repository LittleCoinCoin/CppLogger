#pragma once

/*!
@file LogLevel.h
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
		LogLevel_Error, /*!< Reports errors to the user of the engine.*/
		LogLevel_Trace, /*!< Reports operation performed by the engine to the user.*/
		LogLevel_Warning, /*!< Reports warnings to the user.*/

		LogLevel_Count /*!< The number of log levels.*/
	};

	/*!
	@brief An enum to describe which log levels are enabled.
	*/
	enum LogLevelFlag : unsigned char
	{
		LogLevelFlag_None = 0,
		LogLevelFlag_Debug = 1 << LogLevel_Debug,
		LogLevelFlag_Error = 1 << LogLevel_Error,
		LogLevelFlag_Trace = 1 << LogLevel_Trace,
		LogLevelFlag_Warning = 1 << LogLevel_Warning,
		LogLevelFlag_All = LogLevelFlag_Debug | LogLevelFlag_Error | LogLevelFlag_Trace | LogLevelFlag_Warning
	};
}