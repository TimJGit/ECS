#include "Group.h"

Group::Group()
{
}

Group::~Group()
{
}

vector<Entity*> Group::GetEntities() const
{
	vector<Entity*> pEntities;
	pEntities.reserve(m_pEntities.size());

	for(Entity* pEntity : m_pEntities){
		pEntities.push_back(pEntity);
	}

	return pEntities;
}

void Group::AddObserver(INotifiable* pObserver)
{
	m_pObservers.insert(pObserver);
}

void Group::RemoveObserver(INotifiable* pObserver)
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
		NotifyObservers();
	}
}

void Group::RemoveEntity(Entity* pEntity)
{
	if(pEntity){
		m_pEntities.erase(pEntity);
		NotifyObservers();
	}
}

inline void Group::NotifyObservers() const
{
	for(INotifiable* pObserver : m_pObservers){
		pObserver->Notify(nullptr);
	}
}
