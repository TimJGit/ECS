#pragma once
#include "../Helpers/stdafx.h"

class Entity;
class Group;

class Pool : public INotifiable
{
public:
	Pool();
	virtual ~Pool();

	Entity* CreateEntity();
	const Group& GetGroup(vector<ComponentID> componentIDs);

	virtual void Notify(void* pData);

private:
	unordered_set<Entity*> m_pEntities;
	unordered_set<Group*> m_pGroups;

	Pool(const Pool&) = delete;
	Pool& operator=(const Pool&) = delete;
};
