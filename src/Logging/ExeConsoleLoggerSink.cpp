#include <iostream>
#include "Logging/ExeConsoleLoggerSink.hpp"

void Logging::ExeConsoleLoggerSink::LogTrace(const char* _msg, const char* _time,
	const char* _file,	const char* _function, const int _line) const noexcept
{
	std::cout << _msg << std::endl;
}

void Logging::ExeConsoleLoggerSink::LogDebug(const char* _msg, const char* _time,
	const char* _file, const char* _function, const int _line) const noexcept
{
	std::cout << _msg << std::endl;
}

void Logging::ExeConsoleLoggerSink::LogError(const char* _msg, const char* _time,
	const char* _file, const char* _function, const int _line) const noexcept
{
	std::cout << _msg << std::endl;
}

void Logging::ExeConsoleLoggerSink::LogWarning(const char* _msg, const char* _time,
	const char* _file, const char* _function, const int _line) const noexcept
{
	std::cout << _msg << std::endl;
}

void Logging::ExeConsoleLoggerSink::PrefixTrace(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "[TRACE | '" << _time << "' | '" << _file << " | '" << _function << "-" << _line << "']" << std::endl;
}

void Logging::ExeConsoleLoggerSink::PrefixDebug(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "[DEBUG | '" << _time << "' | '" << _file << " | '" << _function << "-" << _line << "']" << std::endl;
}

void Logging::ExeConsoleLoggerSink::PrefixError(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "[ERROR | '" << _time << "' | '" << _file << " | '" << _function << "-" << _line << "']" << std::endl;
}

void Logging::ExeConsoleLoggerSink::PrefixWarning(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "[WARNING | '" << _time << "' | '" << _file << " | '" << _function << "-" << _line << "']" << std::endl;
}