#include <iostream>
#include "Logging/ExeConsoleLoggerSink.hpp"

void Logging::ExeConsoleLoggerSink::LogTrace(const char* _msg, const char* _file,
	const char* _function) const noexcept
{
	std::cout << "[" <<  "TRACE from '" <<_file << "' in '" << _function << "']\n\t" << _msg << std::endl;
}


void Logging::ExeConsoleLoggerSink::LogDebug(const char* _msg, const char* _file,
	const char* _function) const noexcept
{
	std::cout << "[" << "DEBUG from '" << _file << " in '" << _function << "']\n\t" << _msg << std::endl;
}


void Logging::ExeConsoleLoggerSink::LogError(const char* _msg, const char* _file,
	const char* _function) const noexcept
{
	std::cout << "[" << "ERROR from '" << _file << " in '" << _function << "']\n\t" << _msg << std::endl;
}


void Logging::ExeConsoleLoggerSink::LogWarning(const char* _msg, const char* _file,
	const char* _function) const noexcept
{
	std::cout << "[" << "WARNING from '" << _file << " in '" << _function << "']\n\t" << _msg << std::endl;
}