#pragma once
#include "../Helpers/stdafx.h"

class Entity;

class Group
{
public:
	virtual ~Group();

private:
	Group();

	vector<ComponentID> m_ComponentIDs;
	unordered_set<Entity*> m_pEntities;

	void SetComponentIDs(const vector<ComponentID>& componentIDs);
	bool CompareComponentIDs(vector<ComponentID>& componentIDs) const;

	friend class Pool;

	Group(const Group&) = delete;
	Group& operator=(const Group&) = delete;
};
