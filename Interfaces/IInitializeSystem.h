#pragma once

class IInitializeSystem : public ISystem
{
public:
	virtual ~IInitializeSystem() { }

	virtual void Initialize() = 0;
};
