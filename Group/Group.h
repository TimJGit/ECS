#pragma once
#include "../Helpers/stdafx.h"

class Entity;

class Group
{
public:
	virtual ~Group();

	vector<Entity*> GetEntities() const;

private:
	Group();

	vector<ComponentID> m_ComponentIDs;
	unordered_set<Entity*> m_pEntities;

	void SetComponentIDs(const vector<ComponentID>& componentIDs);
	bool CompareComponentIDs(vector<ComponentID>& componentIDs) const;

	void AddEntity(Entity* pEntity);
	void RemoveEntity(Entity* pEntity);

	friend class Pool;

	Group(const Group&) = delete;
	Group& operator=(const Group&) = delete;
};
