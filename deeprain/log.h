#ifndef __DEEPRAIN_LOG_H__
#define __DEEPRAIN_LOG_H__

#include <string>
#include <stdint.h>
#include <memory>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdarg.h>
#include <map>
#include "singleton.h"
#include "util.h"

#define DEEPRAIN_LOG_LEVEL(logger, level) \
    if(logger->getLevel() <= level) \
        deeprain::LogEventWrap(deeprain::LogEvent::ptr(new deeprain::LogEvent(logger, level, __FILE__, __LINE__, 0, \
        deeprain::GetThreadId(), deeprain::GetFiberId(), time(0)))).getSS()

#define DEEPRAIN_LOG_DEBUG(logger) DEEPRAIN_LOG_LEVEL(logger, deeprain::LogLevel::DEBUG)
#define DEEPRAIN_LOG_INFO(logger) DEEPRAIN_LOG_LEVEL(logger, deeprain::LogLevel::INFO)
#define DEEPRAIN_LOG_WARN(logger) DEEPRAIN_LOG_LEVEL(logger, deeprain::LogLevel::WARN)
#define DEEPRAIN_LOG_ERROR(logger) DEEPRAIN_LOG_LEVEL(logger, deeprain::LogLevel::ERROR)
#define DEEPRAIN_LOG_FATAL(logger) DEEPRAIN_LOG_LEVEL(logger, deeprain::LogLevel::FATAL)

#define DEEPRAIN_LOG_FMT_LEVEL(logger, level, fmt, ...) \
    if(logger->getLevel() <= level) \
        deeprain::LogEventWrap(deeprain::LogEvent::ptr(new deeprain::LogEvent(logger, level, __FILE__, __LINE__, 0, \
                           deeprain::GetThreadId(), deeprain::GetFiberId(), time(0) ))).getEvent()->format(fmt, __VA_ARGS__)

#define DEEPRAIN_LOG_FMT_DEBUG(logger, fmt, ...) DEEPRAIN_LOG_FMT_LEVEL(logger, deeprain::LogLevel::DEBUG, fmt, __VA_ARGS__)
#define DEEPRAIN_LOG_FMT_INFO(logger, fmt, ...) DEEPRAIN_LOG_FMT_LEVEL(logger, deeprain::LogLevel::INFO, fmt, __VA_ARGS__)
#define DEEPRAIN_LOG_FMT_WARN(logger, fmt, ...) DEEPRAIN_LOG_FMT_LEVEL(logger, deeprain::LogLevel::WARN, fmt, __VA_ARGS__)
#define DEEPRAIN_LOG_FMT_ERROR(logger, fmt, ...) DEEPRAIN_LOG_FMT_LEVEL(logger, deeprain::LogLevel::ERROR, fmt, __VA_ARGS__)
#define DEEPRAIN_LOG_FMT_FATAL(logger, fmt, ...) DEEPRAIN_LOG_FMT_LEVEL(logger, deeprain::LogLevel::FATAL, fmt, __VA_ARGS__)

#define DEEPRAIN_LOG_ROOT() deeprain::LoggerMgr::GetInstance()->getRoot()

namespace deeprain {
class Logger;

class LogLevel {
public:
    enum Level {
        UNKNOWN = 0,
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4,
        FATAL = 5,
    };

    static const char* ToString(LogLevel::Level level);
};

class LogEvent {
public:  
    typedef std::shared_ptr<LogEvent> ptr;
    LogEvent(std::shared_ptr<Logger> logger, LogLevel::Level level, const char* file, int32_t line, uint32_t elapse
            , uint32_t threadId, uint32_t fiberId, uint64_t time);
    
    const char* getFile() const { return m_file; }
    int32_t getLine() const { return m_line; }
    uint32_t getElapse() const { return m_elapse; }
    uint32_t getThreadId() const { return m_threadId; }
    uint32_t getFiberId() const { return m_fiberId; }
    uint64_t getTime() const { return m_time; }
    std::string getContent() const { return m_ss.str(); }
    std::shared_ptr<Logger> getLogger() const { return m_logger; }
    LogLevel::Level getLevel() const { return m_level; }

    std::stringstream& getSS() { return m_ss; }
    void format(const char* fmt, ...);
    void format(const char* fmt, va_list al);
private:
    const char* m_file = nullptr;
    int32_t m_line = 0;
    uint32_t m_elapse = 0;
    uint32_t m_threadId = 0;
    uint32_t m_fiberId = 0;
    uint64_t m_time = 0;
    std::stringstream m_ss;

    std::shared_ptr<Logger> m_logger;
    LogLevel::Level m_level;
};

class LogEventWrap {
public:
    LogEventWrap(LogEvent::ptr e);
    ~LogEventWrap();

    std::stringstream& getSS();
    LogEvent::ptr getEvent() const { return m_event; }
private:
    LogEvent::ptr m_event;
};


class LogFormatter {
public:
    typedef std::shared_ptr<LogFormatter> ptr;
    LogFormatter(const std::string& pattern);

    std::string format(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
public:
    class FormatItem {
    public:
        typedef std::shared_ptr<FormatItem> ptr;
        FormatItem(const std::string& fmt = "") {};
        virtual ~FormatItem() {};

        virtual void format(std::ostream& os, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;

    };
    
    void init();
private:
    std::string m_pattern;
    std::vector<FormatItem::ptr> m_items;
    bool m_error = false;
};

class LogAppender {
public:
    typedef std::shared_ptr<LogAppender> ptr;
    virtual ~LogAppender() {};

    virtual void log(std::shared_ptr<Logger> logger, LogLevel::Level, LogEvent::ptr event) = 0;
    
    void setFormatter(LogFormatter::ptr val) { m_formatter = val; }
    LogFormatter::ptr getFormatter() const { return m_formatter; }

    LogLevel::Level getLevel() const { return m_level; }       
    void setLevel(LogLevel::Level val) { m_level = val; }
protected:
    LogLevel::Level m_level = LogLevel::DEBUG;
    LogFormatter::ptr m_formatter;
};

class Logger : public std::enable_shared_from_this<Logger> {
public:
    typedef std::shared_ptr<Logger> ptr;
    Logger(const std::string& name = "root");
    
    void log(LogLevel::Level level, const LogEvent::ptr event);

    void debug(LogEvent::ptr event);
    void info(LogEvent::ptr event);
    void warn(LogEvent::ptr event);
    void error(LogEvent::ptr event);
    void fatal(LogEvent::ptr event);

    void addAppender(LogAppender::ptr appender);
    void delAppender(LogAppender::ptr appender);
    LogLevel::Level getLevel() const { return m_level; }
    void setLevel(LogLevel::Level val) { m_level = val; }

    std::string getName() const { return m_name; }
private:
    std::string m_name;
    LogLevel::Level m_level;
    std::list<LogAppender::ptr> m_appenders;
    LogFormatter::ptr m_formatter;
};

class StdoutLogAppender : public LogAppender {
public:
    typedef std::shared_ptr<StdoutLogAppender> ptr;
    
    void log(std::shared_ptr<Logger> logger, LogLevel::Level, LogEvent::ptr event) override;
private:
};

class FileLogAppender : public LogAppender {
public:
    typedef std::shared_ptr<FileLogAppender> ptr;
    FileLogAppender(const std::string& filename);

    void log(std::shared_ptr<Logger> logger, LogLevel::Level, LogEvent::ptr event) override;

    bool reopen();
private:
    std::string m_filename;
    std::ofstream m_filestream;
};

class LoggerManager {
public:
    LoggerManager();
    Logger::ptr getLogger(const std::string& name);

    void init();
    Logger::ptr getRoot() const { return m_root; }
private:
    std::map<std::string, Logger::ptr> m_loggers;
    Logger::ptr m_root;
};

typedef deeprain::Singleton<LoggerManager> LoggerMgr;

}



#endif
