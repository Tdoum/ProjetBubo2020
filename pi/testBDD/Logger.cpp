#include "Logger.h"
#include <ctime>
#include <iostream>
#include <fstream>

Logger::Logger(std::string logFile) {
    this->logFile = logFile.empty() ? std::string("/var/log/bubo/appLog/BDD.log"):logFile;
}

Logger::~Logger() {
}

Logger::Logger(){
    this->logFile = "/var/log/bubo/appLog/BDD.log";
}

void Logger::saveLog(std::string message)
{
        std::ofstream fichier(logFile, std::ios::out | std::ios::app);

        if(fichier)
        {
            fichier << "[" << getDate() << "]" << "[ERROR] : "<< message << "\r\n";
        }

}


std::string Logger::getDate(){
    time_t temps = time(0);
    std::string date = std::string(ctime(&temps));
    std::string t = date.substr(0, date.size()-6);
    return t;
}
