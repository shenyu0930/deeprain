#include <iostream>
#include <thread>
#include "../deeprain/log.h"
#include "../deeprain/util.h"

int main(int argc, char** argv) {
    deeprain::Logger::ptr logger(new deeprain::Logger);
    logger->addAppender(deeprain::LogAppender::ptr(new deeprain::StdoutLogAppender));
    deeprain::FileLogAppender::ptr file_appender(new deeprain::FileLogAppender("./log.txt")); 
   // deeprain::LogEvent::ptr event(new deeprain::LogEvent(logger, __FILE__, __LINE__, 0, deeprain::GetThreadId(), deeprain::GetFiberId(), time(0)));
    
    deeprain::LogFormatter::ptr fmt(new deeprain::LogFormatter("%d%T%m%n"));
    file_appender->setFormatter(fmt);
    file_appender->setLevel(deeprain::LogLevel::ERROR);
    logger->addAppender(file_appender);
    //logger->log(deeprain::LogLevel::DEBUG, event);
    
    DEEPRAIN_LOG_INFO(logger) << "test macro";    
    DEEPRAIN_LOG_ERROR(logger) << "test macro error";
    //std::cout << std::endl;
    DEEPRAIN_LOG_FMT_INFO(logger, "my name is %s", "lzw");

    auto l = deeprain::LoggerMgr::GetInstance()->getLogger("xx");
    DEEPRAIN_LOG_INFO(l) << "xxx";
    DEEPRAIN_LOG_INFO(DEEPRAIN_LOG_ROOT()) << "hello world";
    return 0;
}
