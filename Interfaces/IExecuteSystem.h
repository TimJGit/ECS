#pragma once

class IExecuteSystem : public ISystem
{
public:
	virtual ~IExecuteSystem() { }

	virtual void Execute() = 0;
};
