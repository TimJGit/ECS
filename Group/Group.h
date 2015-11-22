#pragma once
#include "../Helpers/stdafx.h"

class Entity;

class Group
{
public:
	virtual ~Group();

	void SetComponentIDs(const vector<ComponentID>& componentIDs);
	const vector<ComponentID>& GetComponentIDs() const;

	bool CompareComponentIDs(vector<ComponentID>& componentIDs) const;

private:
	Group();

	vector<ComponentID> m_ComponentIDs;
	unordered_set<Entity*> m_pEntities;

	friend class Pool;

	Group(const Group&) = delete;
	Group& operator=(const Group&) = delete;
};
