#pragma once

#include <string>

namespace k {
        namespace col {
                inline const std::string reset() {return "\e[0m";}

                inline const std::string make_white(std::string text) {return "\e[0;37m" + text + reset();}
                inline const std::string make_grey(std::string text) {return "\e[0;90m" + text + reset();}
                inline const std::string make_yellow(std::string text) {return "\e[0;33m" + text + reset();}
                inline const std::string make_red(std::string text) {return "\e[0;31m" + text + reset();}
                inline const std::string make_bright_red(std::string text) {return "\e[0;91m" + text + reset();}

                inline const std::string get_white() {return "\e[0;37m";}
                inline const std::string get_grey() {return "\e[0;90m";}
                inline const std::string get_yellow() {return "\e[0;33m";}
                inline const std::string get_red() {return "\e[0;31m";}
                inline const std::string get_bright_red() {return "\e[0;91m";}
        }
}
