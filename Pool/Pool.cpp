#include "Pool.h"
#include "../Entity/Entity.h"
#include "../Group/Group.h"

Pool::Pool()
{
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
	m_pEntities.insert(pEntity);
	return pEntity;
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
	return *pGroup;
}
