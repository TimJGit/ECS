#pragma once

class IExecuteSystem
{
public:
	virtual ~IExecuteSystem() { }

	virtual void Execute() = 0;
};
