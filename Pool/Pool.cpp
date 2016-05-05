#include "Pool.h"
#include "../Entity/Entity.h"
#include "../Entity/EntityData.h"
#include "../Group/Group.h"

Pool::Pool()
{
	m_IndexedGroups.resize(ComponentID::TOTAL_COMPONENTS);
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

Entity* Pool::CreateEntity()
{
	Entity* pEntity = new Entity();

	pEntity->SetObserver(this);
	m_pEntities.insert(pEntity);

	return pEntity;
}

void Pool::DestroyEntity(Entity* pEntity)
{
	for(IComponent* pComponent : pEntity->m_pComponents){
		if(pComponent){
			GroupList groupList = m_IndexedGroups[pComponent->GetComponentID()];
			RemoveEntityFromGroups(pEntity, groupList);
		}
	}

	m_pEntities.erase(pEntity);
	delete pEntity;
}

bool Pool::IsEntityValid(Entity* pEntity) const
{
	return pEntity->m_pComponents.size() == ComponentID::TOTAL_COMPONENTS && pEntity->m_pObserver != nullptr;
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

	UpdateIndexedGroups(pGroup);
	AddEntitiesToGroup(pGroup);
	
	return *pGroup;
}

void Pool::Notify(EntityPoolData* pData)
{
	if(!pData){
		throw NullPointerException("Pool::Notify >> Data is null!");
	}

	GroupList groupList = m_IndexedGroups[pData->GetComponentID()];

	ComponentEvent componentEvent = pData->GetComponentEvent();
	if(componentEvent == ComponentEvent::ComponentAdded){
		AddEntityToGroups(pData->GetEntity(), groupList);
	}else if(componentEvent == ComponentEvent::ComponentRemoved){
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

inline void Pool::UpdateIndexedGroups(Group* pGroup)
{
	for(ComponentID componentID : pGroup->GetComponentIDs()){
		m_IndexedGroups[componentID].push_back(pGroup);
	}
}

inline void Pool::AddEntitiesToGroup(Group* pGroup) const
{
	for(Entity* pEntity : m_pEntities){
		AddEntityToGroup(pEntity, pGroup);
	}
}

inline void Pool::AddEntityToGroups(Entity* pEntity, const GroupList& groupList) const
{
	for(Group* pGroup : groupList){
		AddEntityToGroup(pEntity, pGroup);
	}
}

inline void Pool::AddEntityToGroup(Entity* pEntity, Group* pGroup) const
{
	for(ComponentID componentID : pGroup->GetComponentIDs()){
		if(!pEntity->HasComponent(componentID)){
			return;
		}
	}

	pGroup->AddEntity(pEntity);
}

inline void Pool::RemoveEntityFromGroups(Entity* pEntity, const GroupList& groupList) const
{
	for(Group* pGroup : groupList){
		pGroup->RemoveEntity(pEntity);
	}
}
