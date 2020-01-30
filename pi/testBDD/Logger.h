#ifndef LOGGER_H
#define LOGGER_H

#include <string>


class Logger {
public:
    Logger(std::string logFile);
    ~Logger();
    void saveLog(std::string message);
    Logger();
private:
    std::string logFile;
    std::string getDate();
};

#endif // LOGGER_H
