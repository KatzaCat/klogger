#include <klogger.hpp>

int main() {
  k::Logger::setOutputDestination(k::FILE);
  k::Logger::setOutputFile("out.txt");

  k::Logger::info("file test");
  k::Logger::error("something went wrong(not really) uwu");

  k::Logger::pushNewLog("pushing a log", k::WARNING);
  k::Logger::printCurrentLog();

  return 0;
}
