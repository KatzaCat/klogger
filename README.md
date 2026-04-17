# Klogger

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
    k::Logger::pushNewLog("message", k::ERROR); // WARNING: will override previous pushed
    
    // PullResult has 2 members; message of type std::string,
    // and log_level
    k::PullResult result = k::Logger::pullCurrentLog();

    // you can also just print the most recent pushed log
    k::Logger::printCurrentLog();
```

## Building / Testing

If you wish to build it you'll need few requirements:

- [cmake](https://cmake.org/)
- some sort of build system (recommended to use [GNU-Make and MinGW](https://www.mingw-w64.org/))

After making sure you have a way to build it you can;

### On Windows

Run either the ```build-make.bat```, or the ```build-make-test.bat``` file
depending on weather or not you wanna test it, or just build information.

>[!CAUTION]
> These two build files spacificly only run with [GNU-Make and MinGW](https://www.mingw-w64.org/)
> so be sure to have them if you wish to use the ```build-make.bat```, or the ```build-make-test.bat``` file!
> If you dont then you'll have to build it manualy!

### On any other OS

You'll unfortunatly have to build it your-self, you could also just copy the
command from ```build-make.bat```, or the ```build-make-test.bat```, and just
run it on the command line.
