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

  enum OutputDestination {
    STD_OUT,
    FILE
  };

  struct LogInformation {
    std::string message = "";

    OutputDestination destination = STD_OUT;
    
    LogSeverity log_severity = INFO;
    std::string log_text = "";
    std::string log_color = "";

    std::string file_destination = "";
  };

  class Logger {
    public:
      static void setOutputDestination(OutputDestination destination);

      // Dealing with logging to a file

      static void setFileOutput(const std::string file);
      
      // Basic logging methods

      static void info(const std::string message);
      static void debug(const std::string message);
      static void warning(const std::string message);
      static void error(const std::string message);
      static void critical(const std::string message);

      // Push based logging

      static void pushNewLog(const std::string message, LogSeverity log_severity);
      static LogInformation pullCurrentLog();
      
      static void printCurrentLog();
  };
}
