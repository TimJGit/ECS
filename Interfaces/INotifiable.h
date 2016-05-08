#pragma once

class Entity;

class INotifiablePool
{
public:
	virtual ~INotifiablePool() { }

	virtual void Notify(Entity* pEntity, ComponentID componentID, ComponentEvent componentEvent) = 0;
};

class INotifiableSystem
{
public:
	virtual ~INotifiableSystem() { }

	virtual void Notify(Entity* pEntity, EntityEvent entityEvent) = 0;
};
