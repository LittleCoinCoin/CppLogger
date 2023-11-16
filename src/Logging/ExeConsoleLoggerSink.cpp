#include <iostream>
#include "Logging/ExeConsoleLoggerSink.hpp"

void Logging::ExeConsoleLoggerSink::LogTrace(const char* _msg) const noexcept
{
	std::cout << "[Trace] " << _msg << std::endl;
}


void Logging::ExeConsoleLoggerSink::LogDebug(const char* _msg) const noexcept
{
	std::cout << "[Debug] " << _msg << std::endl;
}


void Logging::ExeConsoleLoggerSink::LogError(const char* _msg) const noexcept
{
	std::cout << "[Error] " << _msg << std::endl;
}


void Logging::ExeConsoleLoggerSink::LogWarning(const char* _msg) const noexcept
{
	std::cout << "[Warning] " << _msg << std::endl;
}