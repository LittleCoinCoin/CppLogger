#include "Logging/Logger.hpp"

Logging::LogLevelFlag Logging::Logger::logLevelFlag = Logging::LogLevelFlag_All;

char Logging::Logger::msgBuffer[Logging::Logger::maxMsgBufferSize] = { 0 };

std::vector<Logging::LoggerSink*> Logging::Logger::loggerSinks = std::vector<LoggerSink*>();

const char* Logging::Logger::GetFormattedTime()
{
	static char buf[100];
	std::time_t now = std::time(nullptr);
	std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
	return buf;
}

void Logging::Logger::SetEnabledLogLevels(LogLevelFlag _logLvlFlag) noexcept
{
	logLevelFlag = _logLvlFlag;
}

std::size_t Logging::Logger::AddSink(LoggerSink* _loggerSink)
{
	loggerSinks.push_back(_loggerSink);
	LOG_DEBUG("Adding LoggerSink '%s' at index: %llu", _loggerSink->name, loggerSinks.size() - 1);
	return loggerSinks.size() - 1;
}

bool Logging::Logger::IsLogLevelEnabled(LogLevel _logLvl) noexcept
{
	return (logLevelFlag & ( 1 << _logLvl)) > 0;
}

void Logging::Logger::Log(LogLevel _logLvl, const char* _time, const char* _file,
	const char* _function, const int _line, const char* _fmt, ...) noexcept
{
	if (IsLogLevelEnabled(_logLvl))
	{
		va_list args;
		va_start(args, _fmt);

		vsnprintf(msgBuffer, maxMsgBufferSize, _fmt, args);

		for (std::vector<LoggerSink*>::iterator it = loggerSinks.begin(); it != loggerSinks.end(); it++)
		{
			(*it)->Log(_logLvl, msgBuffer, _time, _file, _function, _line);
		}

		va_end(args);
	}
}

void Logging::Logger::RemoveSink(std::size_t _idx)
{
	LOG_DEBUG("Removing LoggerSink '%s' at index: %llu", loggerSinks[_idx]->name, _idx);
	loggerSinks.erase(loggerSinks.begin() + _idx);
}
