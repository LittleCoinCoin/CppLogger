#include "Logging/LoggerSink.hpp"

void Logging::LoggerSink::Log(LogLevel _lvl, const char* _msg,
	const char* _time, const char* _file, const char* _function, const int _line) noexcept
{
	if (prefixFunctions[_lvl])
	{
		(this->*prefixFunctions[_lvl])(_time, _file, _function, _line);
	}

	if (loggingFunctions[_lvl])
	{
		(this->*loggingFunctions[_lvl])(_msg, _time, _file, _function, _line);
	}

	if (suffixFunctions[_lvl])
	{
		(this->*suffixFunctions[_lvl])(_time, _file, _function, _line);
	}
}