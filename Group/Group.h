#pragma once
#include "../Main/stdafx.h"

class Entity;

class Group
{
public:
	virtual ~Group();

	vector<Entity*> GetEntities() const;
	void AddObserver(INotifiableSystem* pObserver);
	void RemoveObserver(INotifiableSystem* pObserver);

private:
	Group();

	vector<ComponentID> m_ComponentIDs;
	unordered_set<Entity*> m_pEntities;
	vector<INotifiableSystem*> m_pObservers;

	void SetComponentIDs(const vector<ComponentID>& componentIDs);
	const vector<ComponentID>& GetComponentIDs() const;

	void AddEntity(Entity* pEntity);
	void RemoveEntity(Entity* pEntity);

	friend class Pool;
};
