#pragma once

class NullPointerException : public runtime_error
{
public:
	NullPointerException(const char* caller, const char* message) :
		runtime_error(""),
		m_Caller(caller),
		m_Message(message)
	{
	}

	virtual const char* what() const throw()
	{
		stringstream buffer;
		buffer << m_Caller << " >> " << m_Message;
		return buffer.str().c_str();
	}

private:
	const char* m_Caller;
	const char* m_Message;
};

class EntityAlreadyHasComponentException : public runtime_error
{
public:
	EntityAlreadyHasComponentException(const char* caller, const char* componentName) :
		runtime_error(""),
		m_Caller(caller),
		m_ComponentName(componentName)
	{
	}

	virtual const char* what() const throw()
	{
		stringstream buffer;
		buffer << m_Caller << " >> " << "Entity already has " << m_ComponentName << "Component";
		return buffer.str().c_str();
	}

private:
	const char* m_Caller;
	const char* m_ComponentName;
};

class EntityDoesNotHaveComponentException : public runtime_error
{
public:
	EntityDoesNotHaveComponentException(const char* caller, const char* componentName) :
		runtime_error(""),
		m_Caller(caller),
		m_ComponentName(componentName)
	{
	}

	virtual const char* what() const throw()
	{
		stringstream buffer;
		buffer << m_Caller << " >> " << "Entity does not have " << m_ComponentName << "Component";
		return buffer.str().c_str();
	}

private:
	const char* m_Caller;
	const char* m_ComponentName;
};

class UnknownSystemTypeException : public runtime_error
{
public:
	UnknownSystemTypeException(const char* caller) :
		runtime_error(""),
		m_Caller(caller)
	{
	}

	virtual const char* what() const throw()
	{
		stringstream buffer;
		buffer << m_Caller << " >> " << "System has an unknown type";
		return buffer.str().c_str();
	}

private:
	const char* m_Caller;
};
