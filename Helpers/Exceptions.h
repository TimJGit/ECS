#pragma once

class NullPointerException : public runtime_error
{
public:
	NullPointerException(const char* message) : runtime_error(message) { }
	virtual const char* what() const throw() { return runtime_error::what(); }
};

class EntityAlreadyHasComponentException : public runtime_error
{
public:
	EntityAlreadyHasComponentException(const char* message) : runtime_error(message) { }
	virtual const char* what() const throw() { return runtime_error::what(); }
};

class EntityDoesNotHaveComponentException : public runtime_error
{
public:
	EntityDoesNotHaveComponentException(const char* message) : runtime_error(message) { }
	virtual const char* what() const throw() { return runtime_error::what(); }
};

class UnknownSystemTypeException : public runtime_error
{
public:
	UnknownSystemTypeException(const char* message) : runtime_error(message) { }
	virtual const char* what() const throw() { return runtime_error::what(); }
};
