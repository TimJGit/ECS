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

const Group& Pool::GetGroup(vector<ComponentID> componentIDs)
{
	for(Group* pGroup : m_pGroups){
		if(pGroup->CompareComponentIDs(componentIDs)){
			return *pGroup;
		}
	}
	
	Group* pGroup = new Group();

	pGroup->SetComponentIDs(componentIDs);
	m_pGroups.insert(pGroup);

	for(ComponentID componentID : componentIDs){
		m_IndexedGroups[componentID].push_back(pGroup);
	}
	
	return *pGroup;
}

void Pool::Notify(void* pData)
{
	EntityData* pEntityData = static_cast<EntityData*>(pData);
	UpdateGroups(*pEntityData);
}

inline void Pool::UpdateGroups(const EntityData& entityData) const
{
	GroupList groupList = m_IndexedGroups[entityData.GetComponentID()];

	ComponentEvent componentEvent = entityData.GetComponentEvent();
	if(componentEvent == ComponentEvent::ComponentAdded){
		AddEntityToGroups(entityData.GetEntity(), groupList);
	}else if(componentEvent == ComponentEvent::ComponentRemoved){
		RemoveEntityFromGroups(entityData.GetEntity(), groupList);
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
