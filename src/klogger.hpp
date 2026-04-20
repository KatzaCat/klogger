#pragma once

#include <string>

namespace k {
  enum LogSeverity {
    INFO,
    DEBUG,
    WARNING,
    ERROR,
    CRITICAL
  };

  struct PullResult {
    std::string message = "";

    LogSeverity log_severity = INFO;
    std::string log_text = "";
    std::string log_color = "";
  };

  class Logger {
    public:
      // Basic logging methods

      static void info(const std::string message);
      static void debug(const std::string message);
      static void warning(const std::string message);
      static void error(const std::string message);
      static void critical(const std::string message);

      // Push based logging

      static void pushNewLog(const std::string message, LogSeverity log_severity);
      static PullResult pullCurrentLog();
      
      static void printCurrentLog();
  };
}
