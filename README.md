# Klogger

Klogger is a simple(ish) logging system for the c++ lanuage!

## Usage

The main idea is as follows:

```c++
    k::Logger::info("your message"); // for basic information
    k::Logger::debug("your message"); // for debuggin
    k::Logger::warning("your message"); // for warning the user
    k::Logger::error("your message"); // for throwing a catchable error
    k::Logger::critical("your message"); // for a crash
```

Although you are able to manually push a new log, then print it 
whenever you feel necessary:

```c++
    // run some code
    // it fails
    k::Logger::pushNewLog("message", k::ERROR); // WARNING: will override previous pushed
    
    // once applicable, ask to print the log
    k::Logger::printCurrentLog();
```

If necessary, you can also print to a file:

```c++
    k::Logger::setOutputDestination(k::FILE);
    k::Logger::setFileOutputh("out.txt");

    // do your logging
```

This allows you to switch between logging to the standard output
and a file.

## Testing

If you wish to test klooger, you'll need a few requirements installed:

- [cmake](https://cmake.org/)
- some sort of build system (recommended to use [GNU-Make and MinGW](https://www.mingw-w64.org/))

After making sure you have a way to build it, you can;

### On Windows

Run either the ```build-make.bat```, or the ```build-make-test.bat``` file
depending on whether or not you want to test it or just build information.

>[!CAUTION]
> These two build files specifically only run with [GNU-Make and MinGW](https://www.mingw-w64.org/)
> so be sure to have them if you wish to use the ```build-make.bat```, or the ```build-make-test.bat``` file!
> If you don't then you'll have to build it manually!

### On any other OS

You'll unfortunately  have to build it yourself, you could also just copy the
command from ```build-make.bat```, or the ```build-make-test.bat```, and just
run it on the command line.
