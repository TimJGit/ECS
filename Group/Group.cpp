#include "Group.h"

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
		throw NullPointerException("Group::AddObserver", "Observer is null");
	}

	m_pObservers.push_back(pObserver);
}

void Group::RemoveObserver(INotifiableSystem* pObserver)
{
	m_pObservers.erase(remove(m_pObservers.begin(), m_pObservers.end(), pObserver), m_pObservers.end());
}

void Group::SetComponentIDs(const vector<ComponentID>& componentIDs)
{
	m_ComponentIDs = componentIDs;
	sort(m_ComponentIDs.begin(), m_ComponentIDs.end());
}

const vector<ComponentID>& Group::GetComponentIDs() const
{
	return m_ComponentIDs;
}

void Group::AddEntity(Entity* pEntity)
{
	if(!pEntity){
		throw NullPointerException("Group::AddEntity", "Entity is null");
	}

	m_pEntities.insert(pEntity);

	for(INotifiableSystem* pObserver : m_pObservers){
		pObserver->Notify(pEntity, EntityEvent::EntityAdded);
	}
}

void Group::RemoveEntity(Entity* pEntity)
{
	if(!pEntity){
		throw NullPointerException("Group::RemoveEntity", "Entity is null");
	}

	m_pEntities.erase(pEntity);

	for(INotifiableSystem* pObserver : m_pObservers){
		pObserver->Notify(pEntity, EntityEvent::EntityRemoved);
	}
}
