#include "Pool.h"
#include "../Entity/Entity.h"
#include "../Entity/EntityData.h"
#include "../Group/Group.h"

Pool::Pool()
{
	m_IndexedGroups.resize(TOTAL_COMPONENTS);
}

Pool::~Pool()
{
	for(Entity* pEntity : m_pEntities){
		delete pEntity;
	}

	for(Group* pGroup : m_pGroups){
		delete pGroup;
	}
}

Entity& Pool::CreateEntity()
{
	Entity* pEntity = new Entity();

	pEntity->SetObserver(this);
	m_pEntities.insert(pEntity);

	return *pEntity;
}

Group& Pool::GetGroup(vector<ComponentID> componentIDs)
{
	Group* pCachedGroup = GetCachedGroup(componentIDs);
	if(pCachedGroup){
		return *pCachedGroup;
	}
	
	Group* pGroup = new Group();

	pGroup->SetComponentIDs(componentIDs);
	m_pGroups.insert(pGroup);

	UpdateIndexedGroups(componentIDs, pGroup);
	AddEntitesToGroup(componentIDs, pGroup);
	
	return *pGroup;
}

void Pool::Notify(EntityPoolData* pData)
{
	GroupList groupList = m_IndexedGroups[pData->GetComponentID()];

	ComponentEvent componentEvent = pData->GetComponentEvent();
	if(componentEvent == ComponentEvent::ComponentAdded){
		AddEntityToGroups(pData->GetEntity(), groupList);
	} else if(componentEvent == ComponentEvent::ComponentRemoved){
		RemoveEntityFromGroups(pData->GetEntity(), groupList);
	}
}

inline Group* Pool::GetCachedGroup(vector<ComponentID>& componentIDs) const
{
	for(Group* pGroup : m_pGroups){
		if(pGroup->CompareComponentIDs(componentIDs)){
			return pGroup;
		}
	}
	return nullptr;
}

inline void Pool::UpdateIndexedGroups(const vector<ComponentID>& componentIDs, Group* pGroup)
{
	for(ComponentID componentID : componentIDs){
		m_IndexedGroups[componentID].push_back(pGroup);
	}
}

inline void Pool::AddEntitesToGroup(const vector<ComponentID>& componentIDs, Group* pGroup) const
{
	for(Entity* pEntity : m_pEntities){
		for(ComponentID componentID : componentIDs){
			if(!pEntity->HasComponent(componentID)){
				break;
			}
		}
		pGroup->AddEntity(pEntity);
	}
}

inline void Pool::AddEntityToGroups(Entity* pEntity, const GroupList& groupList) const
{
	for(Group* pGroup : groupList){
		pGroup->AddEntity(pEntity);
	}
}

inline void Pool::RemoveEntityFromGroups(Entity* pEntity, const GroupList& groupList) const
{
	for(Group* pGroup : groupList){
		pGroup->RemoveEntity(pEntity);
	}
}
