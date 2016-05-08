#include "ReactiveSystem.h"
#include "../Group/Group.h"
#include "../Pool/Pool.h"

ReactiveSystem::ReactiveSystem(Pool* pPool, IReactiveSystem* pReactiveSystem) :
	m_pPool(pPool),
	m_pReactiveSystem(pReactiveSystem)
{
	SubscribeToGroup();
}

ReactiveSystem::~ReactiveSystem()
{
	UnsubscribeFromGroup();
	delete m_pReactiveSystem;
}

void ReactiveSystem::Execute()
{
	if(!m_pPool){
		throw NullPointerException("ReactiveSystem::Execute", "Pool is null");
	}

	if(!m_pReactiveSystem){
		throw NullPointerException("ReactiveSystem::Execute", "ReactiveSystem is null");
	}

	CleanupCollectedEntities();
	if(m_pCollectedEntities.size() == 0){
		return;
	}

	vector<Entity*> pCollectedEntities(m_pCollectedEntities.begin(), m_pCollectedEntities.end());
	m_pReactiveSystem->Execute(pCollectedEntities);

	m_pCollectedEntities.clear();
}

void ReactiveSystem::Notify(Entity* pEntity, EntityEvent entityEvent)
{
	if(!pEntity){
		throw NullPointerException("ReactiveSystem::Notify", "Entity is null");
	}

	TriggerEvent triggerEvent = m_pReactiveSystem->GetTriggerEvent();
	if(triggerEvent == TriggerEvent::TriggerAdded && entityEvent == EntityEvent::EntityAdded ||
	   triggerEvent == TriggerEvent::TriggerRemoved && entityEvent == EntityEvent::EntityRemoved ||
	   triggerEvent == TriggerEvent::TriggerAddedOrRemoved){
		m_pCollectedEntities.insert(pEntity);
	}
}

inline void ReactiveSystem::SubscribeToGroup()
{
	if(m_pPool && m_pReactiveSystem){
		m_pPool->GetGroup(m_pReactiveSystem->GetTriggers()).AddObserver(this);
	}
}

inline void ReactiveSystem::UnsubscribeFromGroup()
{
	if(m_pPool && m_pReactiveSystem){
		m_pPool->GetGroup(m_pReactiveSystem->GetTriggers()).RemoveObserver(this);
	}
}

inline void ReactiveSystem::CleanupCollectedEntities()
{
	vector<Entity*> pEntitiesToRemove;
	pEntitiesToRemove.reserve(m_pCollectedEntities.size());

	for(Entity* pEntity : m_pCollectedEntities){
		if(!m_pPool->IsEntityValid(pEntity)){
			pEntitiesToRemove.push_back(pEntity);
		}
	}

	for(Entity* pEntity : pEntitiesToRemove){
		m_pCollectedEntities.erase(pEntity);
	}
}
