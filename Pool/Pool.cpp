#include "Pool.h"
#include "../Entity/Entity.h"
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
	Entity* pEntity = new Entity(this);
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
	m_pGroups.push_back(pGroup);

	UpdateIndexedGroups(pGroup);
	AddEntitiesToGroup(pGroup);
	
	return *pGroup;
}

void Pool::Notify(Entity* pEntity, ComponentID componentID, ComponentEvent componentEvent)
{
	if(!pEntity){
		throw NullPointerException("Pool::Notify", "Entity is null");
	}

	GroupList groupList = m_IndexedGroups[componentID];
	if(componentEvent == ComponentEvent::ComponentAdded){
		AddEntityToGroups(pEntity, groupList);
	}else if(componentEvent == ComponentEvent::ComponentRemoved){
		RemoveEntityFromGroups(pEntity, groupList);
	}
}

inline Group* Pool::GetCachedGroup(vector<ComponentID>& componentIDs) const
{
	for(Group* pGroup : m_pGroups){
		if(CompareGroupComponentIDs(pGroup->GetComponentIDs(), componentIDs)){
			return pGroup;
		}
	}

	return nullptr;
}

inline bool Pool::CompareGroupComponentIDs(const vector<ComponentID>& componentIDs1, vector<ComponentID>& componentIDs2) const
{
	if(componentIDs1.size() != componentIDs2.size()){
		return false;
	}

	sort(componentIDs2.begin(), componentIDs2.end());

	for(unsigned int i = 0; i < componentIDs1.size(); ++i){
		if(componentIDs1[i] != componentIDs2[i]){
			return false;
		}
	}

	return true;
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
