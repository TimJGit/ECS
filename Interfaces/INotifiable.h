#pragma once

class EntityPoolData;
class EntitySystemData;

class INotifiablePool
{
public:
	virtual ~INotifiablePool() { }

	virtual void Notify(EntityPoolData* pData) = 0;
};

class INotifiableSystem
{
public:
	virtual ~INotifiableSystem() { }

	virtual void Notify(EntitySystemData* pData) = 0;
};
