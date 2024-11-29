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
	std::cout << "[TRACE at '" << _time << "' from '" << _file << " in '" << _function << "-" << _line << "']\n\t";
}

void Logging::ExeConsoleLoggerSink::PrefixDebug(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "[DEBUG at '" << _time << "' from '" << _file << " in '" << _function << "-" << _line << "']\n\t";
}

void Logging::ExeConsoleLoggerSink::PrefixError(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "[ERROR at '" << _time << "' from '" << _file << " in '" << _function << "-" << _line << "']\n\t";
}

void Logging::ExeConsoleLoggerSink::PrefixWarning(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "[WARNING at '" << _time << "' from '" << _file << " in '" << _function << "-" << _line << "']\n\t";
}

void Logging::ExeConsoleLoggerSink::SuffixTrace(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << '\n' << std::endl;
}

void Logging::ExeConsoleLoggerSink::SuffixDebug(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << '\n' << std::endl;
}

void Logging::ExeConsoleLoggerSink::SuffixError(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << '\n' << std::endl;
}

void Logging::ExeConsoleLoggerSink::SuffixWarning(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << '\n' << std::endl;
}