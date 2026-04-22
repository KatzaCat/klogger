#include <klogger.hpp>

#include <print>
#include <string>

class ReformattedLogger {
  public:
    inline static void log(const std::string message) {
      k::LogInformation log_information;

      k::Logger::pushNewLog(message, k::WARNING);
      log_information = k::Logger::pullCurrentLog();

      std::println("{}{} \"reformattedlogger\" {}\e[0m", 
          log_information.log_color, 
          log_information.log_text, 
          log_information.message);
    }
};

int main() {
  ReformattedLogger::log("test");

  return 0;
}
