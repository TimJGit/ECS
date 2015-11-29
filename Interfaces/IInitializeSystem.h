#pragma once

class IInitializeSystem
{
public:
	virtual ~IInitializeSystem() { }

	virtual void Initialize() = 0;
};
