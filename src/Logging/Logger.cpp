#include "Logging/Logger.hpp"

char Logging::Logger::msgBuffer[Logging::Logger::maxMsgBufferSize] = { 0 };

std::vector<Logging::LoggerSink*> Logging::Logger::loggerSinks = std::vector<LoggerSink*>();

std::size_t Logging::Logger::AddSink(LoggerSink* _loggerSink)
{
	loggerSinks.push_back(_loggerSink);
	LOG_DEBUG("Logger sink added");
	return loggerSinks.size() - 1;
}

void Logging::Logger::Log(LogLevel _logLvl, const char* _fmt, ...) noexcept
{
	va_list args;
	va_start(args, _fmt);

	vsnprintf(msgBuffer, maxMsgBufferSize, _fmt, args);

	for (std::vector<LoggerSink*>::iterator it = loggerSinks.begin(); it != loggerSinks.end(); it++)
	{
		(*it)->Log(_logLvl, msgBuffer);
	}

	va_end(args);
}

void Logging::Logger::RemoveSink(std::size_t& _idx)
{
	LOG_DEBUG("Removing Sink at index: %llu", _idx);
	loggerSinks.erase(loggerSinks.begin() + _idx);
}
