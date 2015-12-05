#pragma once
#include "../Helpers/stdafx.h"

class Entity;

enum TriggerEvent { OnAdded, OnRemoved, OnAddedOrRemoved };

class IReactiveSystem
{
public:
	virtual ~IReactiveSystem() { }

	virtual vector<ComponentID> GetTriggers() = 0;
	virtual TriggerEvent GetTriggerEvent() = 0;
	virtual void Execute(vector<Entity*> pEntites) = 0;
};
