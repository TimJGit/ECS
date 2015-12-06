#include "ReactiveSystem.h"
#include "../Pool/Pool.h"
#include "../Group/Group.h"

ReactiveSystem::ReactiveSystem(Pool* pPool, IReactiveSystem* pReactiveSystem) :
	m_pPool(pPool),
	m_pReactiveSystem(pReactiveSystem)
{
	m_pPool->GetGroup(GetTriggers()).AddObserver(this);
}

ReactiveSystem::~ReactiveSystem()
{
	m_pPool->GetGroup(GetTriggers()).RemoveObserver(this);
	delete m_pReactiveSystem;
}

vector<ComponentID> ReactiveSystem::GetTriggers()
{
	return m_pReactiveSystem->GetTriggers();
}

TriggerEvent ReactiveSystem::GetTriggerEvent()
{
	return m_pReactiveSystem->GetTriggerEvent();
}

void ReactiveSystem::Execute(vector<Entity*> pEntites)
{
	m_pReactiveSystem->Execute(pEntites);
}

void ReactiveSystem::Notify(EntitySystemData* pData)
{
}
