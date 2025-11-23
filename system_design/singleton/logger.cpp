#include<iostream>
#include "logger.hpp"



int Logger::counter = 0;
Logger* Logger::logger_instance = nullptr;
std::mutex Logger::mtx;

void Logger::log(std::string msg) {
    std::cout<<msg<<std::endl;
}

Logger::Logger() {
    ++counter;
    std::cout<<"logger instance created, instance number "<<counter<<std::endl;
}

Logger* Logger::get_logger_instance(){

    if(logger_instance == nullptr){
        std::lock_guard<std::mutex>lock(mtx);
        if(logger_instance == nullptr){
            logger_instance = new Logger();
        }
    }

    return logger_instance;
}
