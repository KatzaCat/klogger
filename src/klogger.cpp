#include "klogger.hpp"

// what will be used as the "pull" functions
static k::PullResult _current_log = {};

// returns the log severity as a string, makes it so i dont have to type this all out manualy :3
static const std::string logSeverityToString(k::LogSeverity log_severity) {
  std::string log_severity_string = "";

  switch (log_severity) {
    case k::INFO:
      log_severity_string = "INFO";
      break;
    case k::DEBUG:
      log_severity_string = "DEBUG";
      break;
    case k::WARNING:
      log_severity_string = "WARNING";
      break;
    case k::ERROR:
      log_severity_string = "ERROR";
      break;
    case k::CRITICAL:
      log_severity_string = "CRITICAL";
      break;

    default: break;
  }

  return log_severity_string;
}

// Basic logging methods

void k::Logger::info(const std::string message) {
}

void k::Logger::debug(const std::string message) {
}

void k::Logger::warning(const std::string message) {
}

void k::Logger::error(const std::string message) {
}

void k::Logger::critical(const std::string message) {
}

// Push based logging

void k::Logger::pushNewLog(const std::string message, k::LogSeverity log_severity) {
  _current_log.message = message; 
  _current_log.log_severity = log_severity;
}

k::PullResult k::Logger::pullCurrentLog() 
{return _current_log;}

void k::Logger::printCurrentLog() {
}
