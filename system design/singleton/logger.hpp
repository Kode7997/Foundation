#ifndef logger_hpp
#define logger_hpp

#include<mutex>

class Logger{
    static int counter;
    static Logger* logger_instance;
    static std::mutex mtx;
    // make Logger private
    Logger();

    public:

        void log(std::string msg);

        static Logger* get_logger_instance();
};


#endif