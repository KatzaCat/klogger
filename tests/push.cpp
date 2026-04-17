#include <klogger.hpp>

int main() {
  // push a few normal things 

  k::Logger::pushNewLog("Test Info", k::INFO);
  k::Logger::printCurrentLog();

  k::Logger::pushNewLog("Test Debug", k::DEBUG);
  k::Logger::printCurrentLog();

  k::Logger::pushNewLog("Test Warning", k::WARNING);
  k::Logger::printCurrentLog();

  k::Logger::pushNewLog("Test Error", k::ERROR);
  k::Logger::printCurrentLog();

  return 0;
}
