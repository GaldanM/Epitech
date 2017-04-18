#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component) : component(component), _message(message)
{
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
	_message = message;
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
	_message = message;
}

UserError::UserError(std::string const &message, std::string const &component) : NasaError(message, component)
{
	_message = message;
}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice")
{
	_message = message;
}

std::string const &NasaError::getComponent() const
{
	return component;
}

const char *NasaError::what() const throw()
{	
	const char *str = _message.c_str();
	return str;
}