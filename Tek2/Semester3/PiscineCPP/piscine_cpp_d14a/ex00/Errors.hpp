#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <stdexcept>

class NasaError : public std::exception
{
    protected:
        std::string component;
        std::string _message;

   public:
        NasaError(std::string const &message, std::string const &component = "Unknown");
        virtual ~NasaError() throw() {}
        std::string const &getComponent() const;
        const char* what() const throw();
};

class MissionCriticalError : public NasaError
{
    protected:
        std::string _message;

    public:
        MissionCriticalError(std::string const &message,
        std::string const &component = "Unknown");
        
        virtual ~MissionCriticalError() throw() {}
};

class LifeCriticalError : public NasaError
{
    protected:
       std::string _message;

    public:
        LifeCriticalError(std::string const &message,
        std::string const &component = "Unknown");
        virtual ~LifeCriticalError() throw() {}
};

class UserError : public NasaError
{
    protected:
       std::string _message;
       
    public:
        virtual ~UserError() throw() {}
        UserError(std::string const &message,
        std::string const &component = "Unknown");
};

class CommunicationError : public NasaError
{
    public:
        std::string _message;
        CommunicationError(std::string const &message);

        virtual ~CommunicationError() throw() {}
};

#endif
