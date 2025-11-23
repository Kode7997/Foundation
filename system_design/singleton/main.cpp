
#include<iostream>
#include "logger.hpp"
#include <thread>

void user1_log(){
    Logger *logger1 = Logger::get_logger_instance();
    logger1->log("user1 logs message");
}

void user2_log(){
    Logger *logger2 = Logger::get_logger_instance();
    logger2->log("user2 logs message");
}

int main(){

    std::thread t1(user1_log);
    std::thread t2(user2_log);
    
    t1.join();
    t2.join();

    return 0;
}