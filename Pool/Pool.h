#pragma once
#include "../Main/stdafx.h"

class Entity;
class EntityPoolData;
class Group;

typedef vector<Group*> GroupList;

class Pool : public INotifiablePool
{
public:
	Pool();
	virtual ~Pool();

	Entity* CreateEntity();
	void DestroyEntity(Entity* pEntity);
	bool IsEntityValid(Entity* pEntity) const;
	Group& GetGroup(vector<ComponentID> componentIDs);

	virtual void Notify(EntityPoolData* pData);

private:
	unordered_set<Entity*> m_pEntities;
	unordered_set<Group*> m_pGroups;
	vector<GroupList> m_IndexedGroups;

	inline Group* GetCachedGroup(vector<ComponentID>& componentIDs) const;
	inline void UpdateIndexedGroups(Group* pGroup);
	inline void AddEntitiesToGroup(Group* pGroup) const;

	inline void AddEntityToGroups(Entity* pEntity, const GroupList& groupList) const;
	inline void AddEntityToGroup(Entity* pEntity, Group* pGroup) const;
	inline void RemoveEntityFromGroups(Entity* pEntity, const GroupList& groupList) const;

	Pool(const Pool&) = delete;
	Pool& operator=(const Pool&) = delete;
};
