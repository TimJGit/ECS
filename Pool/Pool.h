#pragma once
#include "../Helpers/stdafx.h"

class Entity;
class EntityData;
class Group;

typedef vector<Group*> GroupList;

class Pool : public INotifiable
{
public:
	Pool();
	virtual ~Pool();

	Entity& CreateEntity();
	const Group& GetGroup(vector<ComponentID> componentIDs);

	virtual void Notify(void* pData);

private:
	unordered_set<Entity*> m_pEntities;
	unordered_set<Group*> m_pGroups;
	vector<GroupList> m_IndexedGroups;

	inline Group* GetCachedGroup(vector<ComponentID>& componentIDs) const;
	inline void UpdateIndexedGroups(const vector<ComponentID>& componentIDs, Group* pGroup);
	inline void AddEntitesToGroup(const vector<ComponentID>& componentIDs, Group* pGroup) const;

	inline void UpdateGroups(const EntityData& entityData) const;
	inline void AddEntityToGroups(Entity* pEntity, const GroupList& groupList) const;
	inline void RemoveEntityFromGroups(Entity* pEntity, const GroupList& groupList) const;

	Pool(const Pool&) = delete;
	Pool& operator=(const Pool&) = delete;
};
