#include "klogger.hpp"

#include <ctime>
#include <filesystem>
#include <fstream>
#include <print>
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
static k::LogInformation _current_log = {};

// Stores the color and text sepaeately
struct SeverityResult {
  std::string text = "";
  std::string color = "";
};

void k::Logger::setOutputDestination(k::OutputDestination destination) 
{_current_log.destination = destination;}

// Dealing with logging to a file

void k::Logger::setOutputFile(const std::string file) {
  _current_log.file_destination = file;
  if (std::filesystem::exists(file)) {
    // clears the file;
    std::ofstream clear_file(file, std::ios::trunc);
    if (clear_file.is_open()) {clear_file.close();}
  }
}

// returns the log severity as a string, makes it so i dont have to type this all out manualy :3
static SeverityResult logSeverityResult(k::LogSeverity log_severity) {
  SeverityResult log_severity_result = {};

  switch (log_severity) {
    case k::INFO:
      log_severity_result.color = k::col::get_white();
      log_severity_result.text = "INFO";
      break;
    case k::DEBUG:
      log_severity_result.color = k::col::get_grey();
      log_severity_result.text = "DUBUG";
      break;
    case k::WARNING:
      log_severity_result.color = k::col::get_yellow();
      log_severity_result.text = "WARNING";
      break;
    case k::ERROR:
      log_severity_result.color = k::col::get_red();
      log_severity_result.text = "ERROR";
      break;
    case k::CRITICAL:
      log_severity_result.color = k::col::get_bright_red();
      log_severity_result.text = "CRITICAL";
      break;

    default: break;
  }

  return log_severity_result;
}

// Basic logging methods

static const std::string getTimeAsString() {
  std::time_t current_time = std::time(NULL);
  // localtime is depricated, but ill look for a 
  // alternitive later
  std::tm *local_time = std::localtime(&current_time);

  char buffer[255];
  std::strftime(buffer, 255, "%d/%m/%y | %H:%M:%S", local_time);

  return buffer;
}

static void logToStdOut(k::LogSeverity log_severity, const std::string message) {
  SeverityResult severity_result = logSeverityResult(log_severity);
   
  std::println(
      "[{}] {}{:>9}{} {}", 
      getTimeAsString(),
      severity_result.color, severity_result.text, k::col::reset(), 
      message);
}

static void logToFile(k::LogSeverity log_severity, const std::string message) {
  SeverityResult severity_result = logSeverityResult(log_severity);
   
  std::ofstream file(_current_log.file_destination, std::ios::app);

  if (!file.is_open()) {
    std::println("Failed to open \"{}\"", _current_log.file_destination);
    return;
  }

  file << std::format("[{}] {:>9} {}\n", getTimeAsString(), severity_result.text, message);

  file.close();
}

static void log(k::LogSeverity log_severity, const std::string message) {
  switch (_current_log.destination) {
    case k::STD_OUT:
      logToStdOut(log_severity, message);
      break;
    case k::FILE:
      logToFile(log_severity, message); 
      break;

    default: break;
  }
}

void k::Logger::info(const std::string message) 
{log(k::INFO, message);}

void k::Logger::debug(const std::string message) 
{log(k::DEBUG, message);}

void k::Logger::warning(const std::string message) 
{log(k::WARNING, message);}

void k::Logger::error(const std::string message) 
{log(k::ERROR, message);}

void k::Logger::critical(const std::string message) {
  log(k::CRITICAL, message);
  exit(-1);
}

// Push based logging

void k::Logger::pushNewLog(const std::string message, k::LogSeverity log_severity) {
  _current_log.message = message; 
  
  _current_log.log_severity = log_severity;

  SeverityResult severity_result = logSeverityResult(log_severity);
  _current_log.log_text = severity_result.text;
  _current_log.log_color = severity_result.color;
}

k::LogInformation k::Logger::pullCurrentLog() 
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
