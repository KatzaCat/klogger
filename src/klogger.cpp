#include "klogger.hpp"

#include <cstdio>
#include <cstdlib>

#include "color.hpp"

/* 
 * The output of the standard log should look like this:
 *
 * [dd/mm/yy | hh:mm:ss] LOGLEVEL message
 *
 * The LOGLEVEL should be colord as such
 *   INFO:     White
 *   DEBUG:    Grey
 *   WARNING:  Yellow
 *   ERROR:    Red
 *   CRITICAL: Bright Red
 */

// what will be used as the "pull" functions
static k::PullResult _current_log = {};

// returns the log severity as a string, makes it so i dont have to type this all out manualy :3
static const std::string logSeverityToString(k::LogSeverity log_severity) {
  std::string log_severity_string = "";

  switch (log_severity) {
    case k::INFO:
      log_severity_string = k::col::make_white("INFO");
      break;
    case k::DEBUG:
      log_severity_string = k::col::make_grey("DEBUG");
      break;
    case k::WARNING:
      log_severity_string = k::col::make_yellow("WARNING");
      break;
    case k::ERROR:
      log_severity_string = k::col::make_red("ERROR");
      break;
    case k::CRITICAL:
      log_severity_string = k::col::make_bright_red("CRITICAL");
      break;

    default: break;
  }

  return log_severity_string;
}

// Basic logging methods

static void log(k::LogSeverity log_severity, const std::string message) {
}

void k::Logger::info(const std::string message) {
  std::printf("%-8s %s\n", logSeverityToString(k::INFO).c_str(), message.c_str());
}

void k::Logger::debug(const std::string message) {
  std::printf("%-8s %s\n", logSeverityToString(k::DEBUG).c_str(), message.c_str());
}

void k::Logger::warning(const std::string message) {
  std::printf("%-8s %s\n", logSeverityToString(k::WARNING).c_str(), message.c_str());
}

void k::Logger::error(const std::string message) {
  std::printf("%-8s %s\n", logSeverityToString(k::ERROR).c_str(), message.c_str());
}

void k::Logger::critical(const std::string message) {
  std::printf("%50s %s\n", logSeverityToString(k::CRITICAL).c_str(), message.c_str());
  exit(-1);
}

// Push based logging

void k::Logger::pushNewLog(const std::string message, k::LogSeverity log_severity) {
  _current_log.message = message; 
  _current_log.log_severity = log_severity;
}

k::PullResult k::Logger::pullCurrentLog() 
{return _current_log;}

void k::Logger::printCurrentLog() {
  switch (_current_log.log_severity) {
    case k::INFO:
      k::Logger::info(_current_log.message);
      break;
    case k::DEBUG:
      k::Logger::debug(_current_log.message);
      break;
    case k::WARNING:
      k::Logger::warning(_current_log.message);
      break;
    case k::ERROR:
      k::Logger::error(_current_log.message);
      break;
    case k::CRITICAL:
      k::Logger::critical(_current_log.message);
      break;

    default: break;

  }
}
