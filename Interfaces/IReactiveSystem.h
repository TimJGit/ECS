#pragma once
#include "../Main/stdafx.h"

class Entity;

class IReactiveSystem
{
public:
	virtual ~IReactiveSystem() { }

	virtual vector<ComponentID> GetTriggers() = 0;
	virtual TriggerEvent GetTriggerEvent() = 0;
	virtual void Execute(vector<Entity*> pEntities) = 0;
};
