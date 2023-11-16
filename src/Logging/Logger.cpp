#include "Logging/Logger.hpp"

char Logging::Logger::msgBuffer[Logging::Logger::maxMsgBufferSize] = { 0 };

std::vector<Logging::LoggerSink*> Logging::Logger::loggerSinks = std::vector<LoggerSink*>();

std::size_t Logging::Logger::AddSink(LoggerSink* _loggerSink)
{
	loggerSinks.push_back(_loggerSink);
	LogDebug("Logger sink added");
	return loggerSinks.size() - 1;
}

void Logging::Logger::LogTrace(const char* _fmt, ...) noexcept
{
	va_list args;
	va_start(args, _fmt);

	vsnprintf(msgBuffer, maxMsgBufferSize, _fmt, args);

	for (std::vector<LoggerSink*>::iterator it = loggerSinks.begin(); it != loggerSinks.end(); it++)
	{
		(*it)->LogTrace(msgBuffer);
	}

	va_end(args);
}

void Logging::Logger::LogDebug(const char* _fmt, ...) noexcept
{
	va_list args;
	va_start(args, _fmt);

	vsnprintf(msgBuffer, maxMsgBufferSize, _fmt, args);
	for (std::vector<LoggerSink*>::iterator it = loggerSinks.begin(); it != loggerSinks.end(); it++)
	{
		(*it)->LogDebug(msgBuffer);
	}

	va_end(args);
}

void Logging::Logger::LogError(const char* _fmt, ...) noexcept
{
	va_list args;
	va_start(args, _fmt);

	vsnprintf(msgBuffer, maxMsgBufferSize, _fmt, args);
	for (std::vector<LoggerSink*>::iterator it = loggerSinks.begin(); it != loggerSinks.end(); it++)
	{
		(*it)->LogError(msgBuffer);
	}

	va_end(args);
}

void Logging::Logger::LogWarning(const char* _fmt, ...) noexcept
{
	va_list args;
	va_start(args, _fmt);

	vsnprintf(msgBuffer, maxMsgBufferSize, _fmt, args);
	for (std::vector<LoggerSink*>::iterator it = loggerSinks.begin(); it != loggerSinks.end(); it++)
	{
		(*it)->LogWarning(msgBuffer);
	}

	va_end(args);
}
void Logging::Logger::RemoveSink(std::size_t& _idx)
{
	LogDebug("Removing Sink at index: %llu", _idx);
	loggerSinks.erase(loggerSinks.begin() + _idx);
}
