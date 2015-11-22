#pragma once

class ISystem
{
public:
	virtual ~ISystem() { };

	virtual void Execute() = 0;
};

