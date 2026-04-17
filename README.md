### Klogger

Klogger is a simple(ish) logging system for the c++ lanuage!

## Usage

The main idea is as fallows:

```c++
    k::Logger::info("your message"); // for basic information
    k::Logger::debug("your message"); // for debuggin
    k::Logger::warning("your message"); // for warning the user
    k::Logger::error("your message"); // for throwing a catchable error
    k::Logger::critical("your message"); // for a crash
```

Another way you can use this:

```c++
    k::Logger::pushNewLog("message", ERROR); // WARNING: will override previous pushed
    
    // PullResult has 2 members; message of type std::string,
    // and log_level
    k::PullResult result = k::Logger::pullCurrentLog();

    // you can also just print the most recent pushed log
    k::Logger::printCurrentLog();
```
