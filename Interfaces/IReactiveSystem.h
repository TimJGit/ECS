#pragma once
#include "../Helpers/stdafx.h"

class Entity;

class IReactiveSystem
{
public:
	virtual ~IReactiveSystem() { }

	virtual vector<ComponentID> Triggers() = 0;
	virtual void Execute(vector<Entity*> pEntites) = 0;
};
