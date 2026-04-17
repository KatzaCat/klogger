#include <klogger.hpp>

int main() {
  // someting youd use if you were logging something small
  
  k::Logger::info("Test");
  k::Logger::debug("Test");
  k::Logger::warning("Test");
  k::Logger::error("Test");

  return 0;
}
