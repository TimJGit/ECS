#pragma once
#include "../Helpers/stdafx.h"

class Entity;
class Group;

class Pool
{
public:
	Pool();
	virtual ~Pool();

	Entity* CreateEntity();
	const Group& GetGroup(vector<ComponentID> componentIDs);

private:
	unordered_set<Entity*> m_pEntities;
	unordered_set<Group*> m_pGroups;

	Pool(const Pool&) = delete;
	Pool& operator=(const Pool&) = delete;
};
