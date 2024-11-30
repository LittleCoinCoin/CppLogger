#include <iostream>
#include "Tests/TestLoggerSink.hpp"

void Logging::TestLoggerSink::LogTrace(const char* _msg, const char* _time,
	const char* _file, const char* _function, const int _line) const noexcept
{
	std::cout << "Message: " << _msg << std::endl;
}

void Logging::TestLoggerSink::LogDebug(const char* _msg, const char* _time,
	const char* _file, const char* _function, const int _line) const noexcept
{
	std::cout << "Message: " << _msg << std::endl;
}

void Logging::TestLoggerSink::LogError(const char* _msg, const char* _time,
	const char* _file, const char* _function, const int _line) const noexcept
{
	std::cout << "Message: " << _msg << std::endl;
}

void Logging::TestLoggerSink::LogWarning(const char* _msg, const char* _time,
	const char* _file, const char* _function, const int _line) const noexcept
{
	std::cout << "Message: " << _msg << std::endl;
}

void Logging::TestLoggerSink::PrefixTrace(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "Prefix: [TRACE at '" << _time << "' from '" << _file << " in '" << _function << "-" << _line << "']" << std::endl;
}

void Logging::TestLoggerSink::PrefixDebug(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "Prefix: [DEBUG at '" << _time << "' from '" << _file << " in '" << _function << "-" << _line << "']" << std::endl;
}

void Logging::TestLoggerSink::PrefixError(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "Prefix: [ERROR at '" << _time << "' from '" << _file << " in '" << _function << "-" << _line << "']" << std::endl;
}

void Logging::TestLoggerSink::PrefixWarning(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "Prefix: [WARNING at '" << _time << "' from '" << _file << " in '" << _function << "-" << _line << "']" << std::endl;
}

void Logging::TestLoggerSink::SuffixTrace(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "Suffix: NONE" << std::endl;
}

void Logging::TestLoggerSink::SuffixDebug(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "Suffix: NONE" << std::endl;
}

void Logging::TestLoggerSink::SuffixError(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "Suffix: NONE" << std::endl;
}

void Logging::TestLoggerSink::SuffixWarning(const char* _time, const char* _file,
	const char* _function, const int _line) const noexcept
{
	std::cout << "Suffix: NONE" << std::endl;
}