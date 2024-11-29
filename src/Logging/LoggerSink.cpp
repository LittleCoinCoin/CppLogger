#include "Logging/LoggerSink.hpp"

void Logging::LoggerSink::Log(LogLevel _lvl, const char* _msg,
	const char* _time, const char* _file, const char* _function, const int _line) noexcept
{
	if (loggingFunctions[_lvl])
	{
		(this->*loggingFunctions[_lvl])(_msg, _time, _file, _function, _line);
	}
}