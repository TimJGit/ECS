#include "Group.h"
#include "../Entity/EntityData.h"

Group::Group()
{
}

Group::~Group()
{
}

vector<Entity*> Group::GetEntities() const
{
	return vector<Entity*>(m_pEntities.begin(), m_pEntities.end());
}

void Group::AddObserver(INotifiableSystem* pObserver)
{
	if(!pObserver){
		throw NullPointerException("Group::AddObserver >> Observer is null!");
	}

	m_pObservers.insert(pObserver);
}

void Group::RemoveObserver(INotifiableSystem* pObserver)
{
	m_pObservers.erase(pObserver);
}

void Group::SetComponentIDs(const vector<ComponentID>& componentIDs)
{
	m_ComponentIDs = componentIDs;
	sort(m_ComponentIDs.begin(), m_ComponentIDs.end());
}

bool Group::CompareComponentIDs(vector<ComponentID>& componentIDs) const
{
	if(m_ComponentIDs.size() != componentIDs.size()){
		return false;
	}

	sort(componentIDs.begin(), componentIDs.end());

	for(unsigned int i = 0; i < m_ComponentIDs.size(); ++i){
		if(m_ComponentIDs[i] != componentIDs[i]){
			return false;
		}
	}

	return true;
}

void Group::AddEntity(Entity* pEntity)
{
	if(pEntity){
		m_pEntities.insert(pEntity);
		NotifyObservers(pEntity, EntityEvent::EntityAdded);
	}
}

void Group::RemoveEntity(Entity* pEntity)
{
	if(pEntity){
		m_pEntities.erase(pEntity);
		NotifyObservers(pEntity, EntityEvent::EntityRemoved);
	}
}

inline void Group::NotifyObservers(Entity* pEntity, EntityEvent entityEvent) const
{
	for(INotifiableSystem* pObserver : m_pObservers){
		EntitySystemData* pData = new EntitySystemData();

		pData->SetEntity(pEntity);
		pData->SetEntityEvent(entityEvent);

		pObserver->Notify(pData);

		delete pData;
	}
}
